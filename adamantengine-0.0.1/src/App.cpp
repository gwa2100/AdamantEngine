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

	if ((m_pSurfDisplay = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF )) == NULL)
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

		collision::CCollisionItem item( collision::CRectF( ppObjects[n]->Position(), ppObjects[n]->Dimension() ), n );
		arItems.push_back( item );
	}

	//collision detection
	CollisionDetection(arItems);

	//process animation?
}


class CFindHit
{
public:
	CFindHit(adamantengine::collision::CRectF& rect, size_t n)
		: toFind( rect )
		, nIndex(n)
	{

	}

	bool operator()(const adamantengine::collision::CCollisionItem& item )
	{
		if ( nIndex == item.m_uIndex ) return false;

		if (toFind.bottom < item.m_rcBoundingBox.top) return false;
        if (toFind.top > item.m_rcBoundingBox.bottom) return false;

        if (toFind.right < item.m_rcBoundingBox.left) return false;
        if (toFind.left > item.m_rcBoundingBox.right) return false;

        return true;
	}

	size_t nIndex;

	adamantengine::collision::CRectF& toFind;
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

		float fTop = pObject->Position().y;

        collision::CCollisionItemVector::iterator i = arItems.begin();

		collision::CRectF test( pObject->Position(), pObject->Dimension());
		CFindHit hit(test, n);

		while( (i = std::find_if( i, arItems.end(),  hit) ) != arItems.end() )
		{
			collision::CRectF& rect = (*i).m_rcBoundingBox;
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
			test = adamantengine::collision::CRectF( pObject->Position(), pObject->Dimension());
			i++;
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
