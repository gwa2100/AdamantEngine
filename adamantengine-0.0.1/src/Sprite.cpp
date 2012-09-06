#include "Sprite.hpp"
#include <SDL_video.h>

adamantengine::sprite_t::sprite_t(const string& sFilename )
	: gameobject_t()
	, m_pSurf(NULL)
	, m_sName( sFilename )
{
	Create();
}

adamantengine::sprite_t::~sprite_t()
{
	if ( m_pSurf != NULL )
	SDL_FreeSurface( m_pSurf );
}

void adamantengine::sprite_t::Create()
{
	SDL_Surface* pTemp = SDL_LoadBMP(m_sName.c_str());
    if ( pTemp == NULL) return;

    m_pSurf = SDL_DisplayFormat(pTemp);

	SDL_SetAlpha( m_pSurf, SDL_SRCALPHA, 128 );
	SDL_SetColorKey( m_pSurf, SDL_SRCCOLORKEY, 0x00FF00);

    m_dimension.x = (float)m_pSurf->w;
    m_dimension.y = (float)m_pSurf->h;

	SDL_FreeSurface(pTemp);
}

void adamantengine::sprite_t::Render( SDL_Surface* pDisplaySurface )
{
	if ( m_OnRender != NULL )
	{
		m_OnRender( this, pDisplaySurface, m_pUserData );
		return;
	}

    SDL_Rect rect = CDefault_Rect((Sint16)m_position.x, (Sint16)m_position.y, (Uint16)m_dimension.x, (Uint16)m_dimension.y);
    SDL_BlitSurface(m_pSurf, NULL, pDisplaySurface, &rect);
}