#include "App.hpp"
#include <SDL.h>
#include <SDL_mixer.h>
#include "../include/amtengine.h"

adamantengine::app_t::app_t()
	: m_bDetectOffscreenCollision( false )
	, m_bRunning(true)
	 
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

	if ((m_pSurfDisplay = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN)) == NULL)
    {
        return false;
    }

	SDL_SetAlpha( m_pSurfDisplay, SDL_SRCALPHA, 0 );
	SDL_SetColorKey( m_pSurfDisplay, SDL_SRCCOLORKEY, 0x00FF00);
    //Set the window caption
    SDL_WM_SetCaption( "Adamant Engine by: Timothy Carlisle. Copyright All Rights Reserved 2011-2012", NULL);

	return true;
}

void adamantengine::app_t::OnEvent(SDL_Event& anevent)
{
	bool bMovement = false;
	pos2f_t inputVelocity = {0};

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
                inputVelocity.x = -1.0f;
                bMovement = true;
                break;
            case SDLK_RIGHT:
                inputVelocity.x = 1.0f;
                bMovement = true;
                break;
            case SDLK_UP:
                inputVelocity.y = -1.0f;
                bMovement = true;
                break;
            case SDLK_DOWN:
                inputVelocity.y = 1.0f;
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
                inputVelocity.x = 0.0f;
                bMovement = true;
                break;
            case SDLK_RIGHT:
                inputVelocity.x = 0.0f;
                bMovement = true;
                break;
            case SDLK_UP:
                inputVelocity.y = 0.0f;
                bMovement = true;
                break;
            case SDLK_DOWN:
                inputVelocity.y = 0.0f;
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

	if ( m_bDetectOffscreenCollision )
	{
		pos3f_t pos = {0};
		pos.x = 0.0f;
		pos.y = (float)m_pSurfDisplay->h;
		pos2f_t dim = {0};
		dim.x = (float)m_pSurfDisplay->w;
		dim.y = 5000.0f;

		arItems.push_back( collision::CCollisionItem(collision::CRect( pos, dim ), -1) );

		pos.x = -5000.0f;
		pos.y = 0.0f;
		dim.x = 5000.0f;
		dim.y = (float)m_pSurfDisplay->h;

		arItems.push_back( collision::CCollisionItem(collision::CRect( pos, dim ), -1) );

		pos.x = 0.0f;
		pos.y = -5000.0f;
		dim.x = (float)m_pSurfDisplay->w;
		dim.y = 5000.0f;

		arItems.push_back( collision::CCollisionItem(collision::CRect( pos, dim ), -1) );

		pos.x = (float)m_pSurfDisplay->w;
		pos.y = 0.0f;
		dim.x = 5000.0f;
		dim.y = (float)m_pSurfDisplay->h;

		arItems.push_back( collision::CCollisionItem(collision::CRect( pos, dim ), -1) );
	}
	//arItems.Sort();
	//collision detection
	CollisionDetection(arItems);

	//process animation?
}


class CFindHit
{
public:
	CFindHit(adamantengine::collision::CRect& rect)
		: toFind( rect )
	{
		lXMiddle = (toFind.left + toFind.right) / 2;
		lYMiddle = (toFind.top + toFind.bottom ) / 2;
	}

	bool operator()(const adamantengine::collision::CCollisionItem& item )
	{
		if ( item.m_uIndex == nIndex ) return false;

		bool bFirst = toFind.left < item.m_rcBoundingBox.left && toFind.right >= item.m_rcBoundingBox.left;
		bool bSecond = toFind.left == item.m_rcBoundingBox.left;
		bool bThird = toFind.left > item.m_rcBoundingBox.left && toFind.left <= item.m_rcBoundingBox.right;
		if ( !(bFirst || bSecond || bThird) ) return false;
	

		bFirst = toFind.top < item.m_rcBoundingBox.top && toFind.bottom >= item.m_rcBoundingBox.top;
		bSecond = toFind.top == item.m_rcBoundingBox.top;
		bThird = toFind.top > item.m_rcBoundingBox.top && toFind.top <= item.m_rcBoundingBox.bottom;

		if ( !(bFirst || bSecond || bThird) ) return false;

		return true;
	}

	size_t nIndex;

	long lXMiddle;
	long lYMiddle;

	adamantengine::collision::CRect& toFind;
};

void adamantengine::app_t::CollisionDetection(collision::CCollisionItemVector& arItems)
{
	size_t uSize = m_arObjects.size();
	if ( uSize == 0 ) return;

	gameobject_t** ppObjects = m_arObjects.data();

	for( size_t n = 0; n < uSize; n++)
    {
		gameobject_t* pObject = ppObjects[n];

		if ( pObject->UseCollision() == false ) continue;

		auto i = arItems.begin();

		while( i != arItems.end() )
		{
			CFindHit hit(collision::CRect( pObject->Position(), pObject->Dimension()));
			hit.nIndex = n;
			i = std::find_if( i, arItems.end(), hit );
			if ( i != arItems.end() )
			{
				long rXMiddle = ((*i).m_rcBoundingBox.left + (*i).m_rcBoundingBox.right) / 2;
				long rYMiddle = ((*i).m_rcBoundingBox.top + (*i).m_rcBoundingBox.bottom ) / 2;

				int iCollision2 = eCOLLISION_NONE;
				
				if ( hit.toFind.bottom == (*i).m_rcBoundingBox.top)
				{
					iCollision2 = eCOLLISION_BOTTOM;
				}
				
				if ( hit.toFind.right == (*i).m_rcBoundingBox.left )
				{
					iCollision2 |= eCOLLISION_RIGHT;
				}

				if ( hit.toFind.top == (*i).m_rcBoundingBox.bottom )
				{
					iCollision2 |= eCOLLISION_TOP;
				}

				if (hit.toFind.left == (*i).m_rcBoundingBox.right )
				{
					iCollision2 |= eCOLLISION_LEFT;
				}

				/*long rXMiddle = ((*i).m_rcBoundingBox.left + (*i).m_rcBoundingBox.right) / 2;
				long rYMiddle = ((*i).m_rcBoundingBox.top + (*i).m_rcBoundingBox.bottom ) / 2;

				long XDiff = hit.lXMiddle - rXMiddle;
				long YDiff = hit.lYMiddle - rYMiddle;

				

				if ( XDiff == 0 )
				{
					iCollision |= eCOLLISION_X_CENTER;
				}
				else if( XDiff < 0 )
				{
					iCollision |= eCOLLISION_RIGHT;
				}
				else
				{
					iCollision |= eCOLLISION_LEFT;
				}

				if ( YDiff == 0 )
				{
					iCollision |= eCOLLISION_Y_CENTER;
				}
				else if ( YDiff > 0 )
				{
					iCollision |= eCOLLISION_TOP;
				}
				else
				{
					iCollision |= eCOLLISION_BOTTOM;
				}*/

				pObject->OnCollision( (ECollision)iCollision2, 1.0f, 1.0f );
				i++;
			}
		}
    }

}

void adamantengine::app_t::OnRender()
{
	SDL_FillRect( m_pSurfDisplay, NULL, 0 );
	//call render on all gameobjects
	size_t nSize = m_arObjects.size();
	if ( nSize > 0 )
	{
		gameobject_t** ppObjects = m_arObjects.data();
		for( size_t n = 0; n < nSize; n++ )
		{
			if ( ppObjects[n]->UseRender() )
			{
				ppObjects[n]->Render( m_pSurfDisplay );
			}
		}
	}

	//SDL_UpdateRect( m_pSurfDisplay, 0,0,0,0);
	SDL_Flip(m_pSurfDisplay);
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