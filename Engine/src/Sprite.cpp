//
//  Sprite.cpp
//  AdamantEngine
//
//  Created by Timothy Carlisle on 10/26/11.
/*
   Copyright 2011-2012 Timothy Carlisle

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0
s
   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include "../include/adamantengine.hpp"
#include <SDL_video.h>

void CSprite::Render(HSURFACE hDestSurf)
{
    Pos3f pos = GetPosition();
    Pos2f dim = GetDimensions();
    CRect dst(pos, dim);

    AmtBlit(m_hSurf, NULL, hDestSurf, &dst);
}

CSprite::CSprite()
: m_hSurf(NULL)
{

}

CSprite::~CSprite()
{
    if (m_hSurf != NULL)
    {
        SDL_FreeSurface((SDL_Surface*)m_hSurf);
    }
}

bool CSprite::CreateFromFile( const string& sFilename )
{
    SDL_Surface* pTemp = SDL_LoadBMP(sFilename.c_str());
    if ( pTemp == NULL) return false;

    SDL_Surface* pSurface = SDL_DisplayFormat(pTemp);

    dimensions.x = pSurface->w;
    dimensions.y = pSurface->h;

    bool bValid = pSurface != NULL;

    SDL_FreeSurface(pTemp);

    if ( bValid )
    {
        m_hSurf = pSurface;
    }

    return bValid;

}
