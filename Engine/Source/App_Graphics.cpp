//
//  CApp_Graphics.cpp
//  AdamantEngine
//
//  Created by Timothy Carlisle on 10/27/11.
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

#include "App.h"
#include <SDL/SDL.h>

SDL_Surface* CApp::LoadSprite(const char* pszFileName)
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
    SDL_Rect rect = CDefault_Rect( nDstX, nDstY );

    if (SDL_BlitSurface(pSrc, NULL, pDst, &rect) != 1)
    {
        return false;
    }
    else
    {
        return true;
    }

}


bool CApp::DrawSurface(SDL_Surface* pSrc, Sint16 nSrcX, Sint16 nSrcY, SDL_Surface* pDst, Sint16 nDstX, Sint16 nDstY)
{
    SDL_Rect rcSrc = CDefault_Rect( nSrcX, nSrcY);
    SDL_Rect rcDst = CDefault_Rect( nDstX, nDstY);

    if (SDL_BlitSurface(pSrc, &rcSrc, pDst, &rcDst) != 1)
    {
        return false;
    }
    else
    {
        return true;
    }

}

