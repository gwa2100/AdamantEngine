//
//  CApp.cpp
//  AdamantEngine
//
//  Created by Timothy Carlisle on 10/26/11.
/*
   Copyright 2011-2012 Timothy Carlisle

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include "App.hpp"
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_events.h>

const int g_ciFrameCap = 60;

//Z Comparison (DEPTH)
bool operator < (const CGameObject& left, const CGameObject& right)
{
	if  (left.GetPosition().z < right.GetPosition().z) return true;
	return false;
}

CApp::CApp()
 : m_bRunning( true )
 , m_pSurfDisplay(NULL)
 , m_uPrevTime(0)
 , m_uCurrTime(0)
 , m_uAccTime(0)
 , m_nGravRate(0)
 , m_nGravFrame(0)
 , m_bJump(false)
 , m_bAlreadyJump(false)
 , m_nJumpTime(0)
 , m_nJumpPower(0)

{
}

int CApp::Execute() {
    SDL_Event localEvent;

    while (m_bRunning)
    {
        if (m_timer.IsStarted() == false)
        {
            m_timer.Start();
        }

        if (m_timer.IsStarted() == true)
        {
            m_uPrevTime = m_uCurrTime;
            m_uCurrTime = SDL_GetTicks();
        }

        m_uAccTime = m_uAccTime + m_uCurrTime - m_uPrevTime;

        while (SDL_PollEvent(&localEvent))
        {
            OnEvent(&localEvent);
        }
        OnLoop();
        //if ( accTime >= 1000 )
        {
            m_uAccTime = 0;

            OnRender();
        }
    }

    OnCleanup();

    return 0;
}

void CApp::Bind(CGameObject* pBindMe)
{

    //lets let vector do the memory management of the internal buffers...
    m_arObjectList.push_back( pBindMe );
}

SDL_Surface* CApp::LoadSprite(const char* pszFileName) const
{
    SDL_Surface* pSurfTemp = NULL;
    SDL_Surface* pSurfReturn = NULL;

    if ((pSurfTemp = SDL_LoadBMP(pszFileName)) == NULL) {
        return NULL;
    }

    pSurfReturn = SDL_DisplayFormat(pSurfTemp);

    SDL_FreeSurface(pSurfTemp);

    //Uint32 colorKey = SDL_MapRGB( Surf_Return->format,0, 0xFF, 0xFF);
    //SDL_SetColorKey(Surf_Return, SDL_RLEACCEL | SDL_SRCCOLORKEY, colorKey);

    SDL_SetColorKey(pSurfReturn, SDL_SRCCOLORKEY, SDL_MapRGB(pSurfReturn->format, 153,217,234));

    return pSurfReturn;

}

bool CApp::DrawSurface(SDL_Surface* pSrc, SDL_Surface* pDst)
{
    if (SDL_BlitSurface(pSrc, NULL, pDst, NULL) != 1)
    {
        return false;
    }
    else
    {
        return true;
    }

}


bool CApp::DrawSurface(SDL_Surface* pSrc, SDL_Surface* pDst, Sint16 nDstX, Sint16 nDstY)
{
    SDL_Rect rect = {nDstX, nDstY , 0 , 0};

    if (SDL_BlitSurface(pSrc, NULL, pDst, &rect) != 1)
    {
        return false;
    }
    else
    {
        return true;
    }

}

//KMS: don't use this because it isnt in good shape atm, it only supplies x,y on the source and not what width and height you want
bool CApp::DrawSurface(SDL_Surface* pSrc, Sint16 nSrcX, Sint16 nSrcY, SDL_Surface* pDst, Sint16 nDstX, Sint16 nDstY)
{
    SDL_Rect rcSrc = {nSrcX, nSrcY, 0 ,0};
    SDL_Rect rcDst = {nDstX, nDstY, 0, 0};

    if (SDL_BlitSurface(pSrc, &rcSrc, pDst, &rcDst) != 1)
    {
        return false;
    }
    else
    {
        return true;
    }

}


void CApp::OnCleanup(){
    SDL_Quit();
}


void CApp::OnEvent(SDL_Event* pEvent) {
    if (pEvent->type == SDL_QUIT) {
        m_bRunning = false;
    }

    bool bSendEvent = false;

    if (pEvent->type == SDL_KEYDOWN) {
        switch (pEvent->key.keysym.sym){
            case SDLK_LEFT:
                m_inputVelocity.x = -1;
                bSendEvent = true;
                break;
            case SDLK_RIGHT:
                m_inputVelocity.x = 1;
                bSendEvent = true;
                break;
            case SDLK_UP:
                m_inputVelocity.y = -1;
                bSendEvent = true;
                break;
            case SDLK_DOWN:
                m_inputVelocity.y = 1;
                bSendEvent = true;
                break;
            case SDLK_ESCAPE:
                m_bRunning = false;
                bSendEvent = false;
            default:
                break;
        }
    }
    if (pEvent->type == SDL_KEYUP) {

        switch (pEvent->key.keysym.sym){
            case SDLK_LEFT:
                m_inputVelocity.x = 0;
                bSendEvent = true;
                break;
            case SDLK_RIGHT:
                m_inputVelocity.x = 0;
                bSendEvent = true;
                break;
            case SDLK_UP:
                m_inputVelocity.y = 0;
                bSendEvent = true;
                break;
            case SDLK_DOWN:
                m_inputVelocity.y = 0;
                bSendEvent = true;
                break;
            default:
                break;
        }
    }

    if ( bSendEvent )
    {
        size_t uSize = m_arObjectList.size();

        if ( uSize > 0) {
            CGameObject** ppObjects = m_arObjectList.data();

            for (size_t x = 0; x < uSize; x++) {
                if ( ppObjects[x]->GetEvent())
                {
                    ppObjects[x]->Event(m_inputVelocity);
                }
            }
        }
    }
}

bool CApp::Initialize()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    // load support for the OGG and MOD sample/music formats
    int flags = MIX_INIT_OGG | MIX_INIT_MOD | MIX_INIT_MP3;
    int initted = Mix_Init(flags);

    if((initted & flags) != flags)
    {
        printf("Mix_Init: Failed to init required ogg, mod, and mp3 support!\n");
        printf("Mix_Init: %s\n", Mix_GetError());
        // handle error
    }

    //Setting up sound system.
    //TAC: Probably need to move settings into the CApp class so that they are held there and can be changed from there.
    int audio_rate = 22050;
    Uint16 audio_format = AUDIO_S16;    //This is 16bit audio format.
    int audio_channels = 2;             //We can increase this later after initial tests of this system.
    int audio_buffers = 4096;

    if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) == -1)
    {
        printf("Open_Audio: Failed to init! >> %s\n", Mix_GetError());
        // handle error
    }


    if ((m_pSurfDisplay = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Adamant Engine by: Timothy Carlisle. Copyright All Rights Reserved 2011-2012", NULL);

    m_inputVelocity.x = 0;
    m_inputVelocity.y = 0;
    m_uMovementSpeed = MOVE_SPD;
    m_uPrevTime = 0;
    m_uCurrTime = 0;
    m_uAccTime = 0;
    m_nGravRate = 7;
    m_nGravFrame = 0;

    //Jump stuff ::: TAC: I DONT THINK THIS IS USED ANYMORE.  May just remove it.
    m_bJump = false;
    m_bAlreadyJump = false;
    m_nJumpTime = 0;
    m_nJumpPower = 7;

    //If using a tileMap, Generate!
    if (m_bUseTileEngine)
    {
        m_TileEngine.GenerateMap();
    }

    return true;
}

#include <algorithm>

void CApp::OnLoop()
{
    //TODO: Write code for sending events to object event processor.
    //Run Update
    size_t uSize = m_arObjectList.size();
    if ( uSize == 0 ) return;

    CCollisionItemVector arCollideItems;
    arCollideItems.reserve( uSize );

    CGameObject** ppObjects = m_arObjectList.data();

    for (size_t x = 0; x < uSize; x++) {
        if (ppObjects[x]->GetUpdate() )
        {
           ppObjects[x]->Update();
        }

       Pos3f pos = ppObjects[x]->GetPosition();
       Pos2f dim = ppObjects[x]->GetDimensions();
       CCollisionItem item( CRect(pos,dim), x );
       arCollideItems.push_back( item );
    }

    //Check for collisions

    for( size_t n = 0; n < uSize; n++)
    {
        CGameObject* pObject = ppObjects[n];

		if ( pObject->GetCollision() == false ) continue;

        CCollisionItemVector::iterator i = arCollideItems.begin();

		CRect test( pObject->GetPosition(), pObject->GetDimensions());
		CFindHit hit(test, n);

		while( (i = std::find_if( i, arCollideItems.end(),  hit) ) != arCollideItems.end() )
		{
		    CRect& rect = (*i).m_rcBoundingBox;

			int iCollision2 = eCOLLISION_NONE;
			float yAmt = 0.0f;
			float xAmt = 0.0f;

			if ( test.top < rect.top )
			{
				if (test.bottom < rect.bottom )
				{
					yAmt = test.bottom - rect.top;
					iCollision2 |= eCOLLISION_BOTTOM;
				}
				else
				{
					iCollision2 |= eCOLLISION_Y_CENTER;
				}
			}
			else
			{
				if ( test.bottom < rect.bottom )
				{
					iCollision2 |= eCOLLISION_Y_CENTER;
				}
				else
				{
					iCollision2 |= eCOLLISION_TOP;
					yAmt = rect.bottom - test.top;
				}

			}

			if ( test.left < rect.left )
			{
				if ( test.right < rect.right )
				{
					iCollision2 |= eCOLLISION_RIGHT;
					xAmt = test.right - rect.left;
				}
				else
				{
					iCollision2 |= eCOLLISION_X_CENTER;
				}
			}
			else
			{
				if ( test.right < rect.right )
				{
					iCollision2 |= eCOLLISION_X_CENTER;
				}
				else
				{
					xAmt = rect.right - test.left;
					iCollision2 |= eCOLLISION_LEFT;
				}
			}

			pObject->OnCollision( (ECollision)iCollision2, xAmt, yAmt );

			//if object has moved due to collision, then we readjust here
			test = CRect( pObject->GetPosition(), pObject->GetDimensions());
			i++;
		}
    }
}

void CApp::OnRender(){
    //SpriteList SpriteDrawing!
    SDL_FillRect( m_pSurfDisplay, NULL, 0 );

    //First of all draw the tileMap if it being used.
    if (m_bUseTileEngine)
    {
        m_TileEngine.RenderCurrentViewPort(m_pSurfDisplay);
    }

    size_t uSize = m_arObjectList.size();

    if ( uSize > 0) {
        CGameObject** ppObjects = m_arObjectList.data();

        for (size_t x = 0; x < uSize; x++) {
            if ( ppObjects[x]->GetRender() ) {
                ppObjects[x]->Render(m_pSurfDisplay);
            }
        }
    }

    SDL_Flip(m_pSurfDisplay);
}
