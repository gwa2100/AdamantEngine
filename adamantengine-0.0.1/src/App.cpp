#include "App.hpp"
#include <SDL.h>
#include <SDL_mixer.h>
#include "../include/amtengine.h"

adamantengine::app_t::app_t()
	: m_bRunning(false)
{
}

adamantengine::app_t::~app_t()
{
}

int adamantengine::app_t::Execute()
{
	SDL_Event sdlevent;

	while ( m_bRunning )
	{
		//poll for input
		while (SDL_PollEvent(&sdlevent))
        {
            OnEvent(sdlevent);
        }

		//process some stuff
		OnUpdate();

		//now render the frame
		OnRender();
	}

	OnCleanup();

	return 0;
}

bool adamantengine::app_t::Intialize()
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

	return true;
}

void adamantengine::app_t::OnEvent(SDL_Event& anevent)
{
	bool bMovement = false;
	pos2i_t inputVelocity = {0};

	if (anevent.type == SDL_QUIT) 
	{
        m_bRunning = false;
		return;
    }

	if (anevent.type == SDL_KEYDOWN) 
	{
        switch ( anevent.key.keysym.sym )
		{
            case SDLK_LEFT:
                inputVelocity.x = -1;
                bMovement = true;
                break;
            case SDLK_RIGHT:
                inputVelocity.x = 1;
                bMovement = true;
                break;
            case SDLK_UP:
                inputVelocity.y = -1;
                bMovement = true;
                break;
            case SDLK_DOWN:
                inputVelocity.y = 1;
                bMovement = true;
                break;
            case SDLK_ESCAPE:
                m_bRunning = false;
                bMovement = false;
            default:
                break;
        }
    }
	else if (anevent.type == SDL_KEYUP) 
	{

        switch ( anevent.key.keysym.sym )
		{
            case SDLK_LEFT:
                inputVelocity.x = 0;
                bMovement = true;
                break;
            case SDLK_RIGHT:
                inputVelocity.x = 0;
                bMovement = true;
                break;
            case SDLK_UP:
                inputVelocity.y = 0;
                bMovement = true;
                break;
            case SDLK_DOWN:
                inputVelocity.y = 0;
                bMovement = true;
                break;
            default:
                break;
        }
    }

	if ( bMovement )
	{
		size_t nSize = m_arObjects.size();
		if ( nSize > 0 )
		{
			gameobject_t** ppObjects = m_arObjects.data();
			for( size_t n = 0; n < nSize; n++ )
			{
				if ( ppObjects[n]->UseEvent() )
				{
					ppObjects[n]->OnInput( inputVelocity );
				}
			}
		}
	}
}

void adamantengine::app_t::OnUpdate()
{
	size_t nSize = m_arObjects.size();
	if ( nSize == 0 ) return;

	gameobject_t** ppObjects = m_arObjects.data();
	
	collision::CCollisionItemVector arItems;

	//process movement
	for( size_t n = 0; n < nSize; n++ )
	{
		if ( ppObjects[n]->UseUpdate() )
		{
			ppObjects[n]->Update();
		}

		collision::CCollisionItem item( collision::CRect( ppObjects[n]->Position(), ppObjects[n]->Dimension() ), n );
		arItems.push_back( item );
	}

	arItems.Sort();
	//collision detection
	CollisionDetection(arItems);

	//process animation?
}

void adamantengine::app_t::CollisionDetection(collision::CCollisionItemVector& arItems)
{
	size_t uSize = arItems.size();
	if ( uSize == 0 ) return;

	gameobject_t** ppObjects = m_arObjects.data();

	for( size_t n = 0; n < uSize; n++)
    {
        if ( (n + 1) >= uSize ) continue;

        bool xhit = false;
        bool yhit = false;

        collision::CCollisionItem& xItemN = arItems[n];
        collision::CCollisionItem& xItemN1 = arItems[n + 1];

        bool bXLeftHit = (xItemN.m_rcBoundingBox.left >= xItemN1.m_rcBoundingBox.left && xItemN.m_rcBoundingBox.left <= xItemN1.m_rcBoundingBox.right);
        bool bXRightHit = (xItemN.m_rcBoundingBox.right >= xItemN1.m_rcBoundingBox.left && xItemN.m_rcBoundingBox.right <= xItemN1.m_rcBoundingBox.right);

        long lXN1Middle = (xItemN1.m_rcBoundingBox.left + xItemN1.m_rcBoundingBox.right) / 2;
        long lCompare = 0;

        int eCollision = eCOLLISION_NONE;
        int eCollisionN1 = eCOLLISION_NONE;

        if ( bXLeftHit && bXRightHit)
        {
            long lXNMiddle = (xItemN.m_rcBoundingBox.left + xItemN.m_rcBoundingBox.right) / 2;
            lCompare = lXNMiddle - lXN1Middle;
        }
        else if ( bXLeftHit)
        {
            lCompare = xItemN.m_rcBoundingBox.left - lXN1Middle;
        }
        else if ( bXRightHit)
        {
            lCompare = xItemN.m_rcBoundingBox.right - lXN1Middle;
        }

        bool bHitX = bXLeftHit || bXRightHit;

        if ( bHitX )
        {
            if ( lCompare < 0 )
            {
                eCollision = eCollision | eCOLLISION_LEFT;
                eCollisionN1 |= eCOLLISION_RIGHT;
            }
            else if ( lCompare > 0)
            {
                eCollision |= eCOLLISION_RIGHT;
                eCollisionN1 |= eCOLLISION_LEFT;
            }
            else
            {
                eCollision |= eCOLLISION_X_CENTER;
                eCollisionN1 |= eCOLLISION_X_CENTER;
            }
        }


        bool bYBottomHit = bHitX && (xItemN.m_rcBoundingBox.bottom <= xItemN1.m_rcBoundingBox.bottom && xItemN.m_rcBoundingBox.bottom >= xItemN1.m_rcBoundingBox.top);
        bool bYTopHit = bHitX && (xItemN.m_rcBoundingBox.top <= xItemN1.m_rcBoundingBox.bottom && xItemN.m_rcBoundingBox.top >= xItemN1.m_rcBoundingBox.top);

        lXN1Middle = (xItemN1.m_rcBoundingBox.top + xItemN1.m_rcBoundingBox.bottom) / 2;

        if ( bYTopHit && bYBottomHit)
        {
            long lXNMiddle = (xItemN.m_rcBoundingBox.top + xItemN.m_rcBoundingBox.bottom) / 2;
            lCompare = lXNMiddle - lXN1Middle;
        }
        else if ( bYTopHit )
        {
            lCompare = xItemN.m_rcBoundingBox.top - lXN1Middle;
        }
        else if ( bYBottomHit )
        {
            lCompare = xItemN.m_rcBoundingBox.bottom - lXN1Middle;
        }

        bool bHitY = bYTopHit || bYBottomHit;

        if ( bHitY )
        {
            //Could be missing a point called "eCOLLISION_Y_CENTER
            if ( lCompare > 0 )
            {
                eCollision |= eCOLLISION_TOP;
                eCollisionN1 |= eCOLLISION_BOTTOM;
            }
            else if ( lCompare < 0)
            {
                eCollision |= eCOLLISION_BOTTOM;
                eCollisionN1 |= eCOLLISION_TOP;
            }
            else
            {
                eCollision |= eCOLLISION_Y_CENTER;
                eCollisionN1 |= eCOLLISION_Y_CENTER;
            }
        }


        if ( bHitX && bHitY )
        {
            if ( ppObjects[xItemN.m_uIndex]->UseCollision())
            {
                ppObjects[xItemN.m_uIndex]->OnCollision((ECollision)eCollision);
            }

            if ( ppObjects[xItemN1.m_uIndex]->UseCollision())
            {
                ppObjects[xItemN1.m_uIndex]->OnCollision((ECollision)eCollisionN1);
            }
        }
    }
}

void adamantengine::app_t::OnRender()
{
	//call render on all gameobjects
	size_t nSize = m_arObjects.size();
	if ( nSize == 0 ) return;

	gameobject_t** ppObjects = m_arObjects.data();
	for( size_t n = 0; n < nSize; n++ )
	{
		if ( ppObjects[n]->UseRender() )
		{
			ppObjects[n]->Render();
		}
	}
}

void adamantengine::app_t::OnCleanup()
{
	size_t nSize = m_arObjects.size();
	if ( nSize == 0 ) return;
	gameobject_t** ppObjects = m_arObjects.data();
	for( size_t n = 0; n < nSize; n++ )
	{
		if ( ppObjects[n]->UseCleanup() )
		{
			ppObjects[n]->Cleanup();
		}
	}
}

void adamantengine::app_t::BindObject( gameobject_t* pObject)
{
	m_arObjects.push_back( pObject );
}