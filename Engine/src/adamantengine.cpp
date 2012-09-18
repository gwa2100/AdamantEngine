#include "../include/adamantengine.hpp"
#include "App.hpp"
#include <SDL_video.h>

IEngine* GetEngine()
{
    return new CApp;
}


void AmtBlit(HSURFACE hSrcSurface, CRect* pSrcRect, HSURFACE hDstSurface, CRect* pDstRect )
{
    SDL_Rect source = {0};
	SDL_Rect* pSourceRC = NULL;
	if ( pSrcRect != NULL )
	{
		pSourceRC = &source;
		source.x = pSrcRect->left;
		source.y = pSrcRect->top;
		source.h = pSrcRect->Height();
		source.w = pSrcRect->Width();
	}

	SDL_Rect dest = {0};
	SDL_Rect* pDestRC = NULL;
	if ( pDstRect != NULL )
	{
		pDestRC = &dest;
		dest.x = pDstRect->left;
		dest.y = pDstRect->top;
		dest.h = pDstRect->Height();
		dest.w = pDstRect->Width();
	}

	SDL_Surface* pSource = (SDL_Surface*)hSrcSurface;
	SDL_BlitSurface( pSource, pSourceRC, (SDL_Surface*)hDstSurface, pDestRC );
}
