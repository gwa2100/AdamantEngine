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

#include "Sprite.h"
#include "PositionDataTypes.h"

bool CSprite::Render(SDL_Surface* pDestSurf)
{
    Pos3i pos = GetPosition3i();
    Pos2i dim = GetDimensions2i();
    SDL_Rect rect = CDefault_Rect(pos.x, pos.y, dim.x, dim.y);

    if (SDL_BlitSurface(m_pSurf, NULL, pDestSurf, &rect) != 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

CSprite::CSprite()
: m_pSurf(NULL)
{

}

CSprite::~CSprite()
{
    if (m_pSurf != NULL)
    {
        SDL_FreeSurface(m_pSurf);
    }
}

bool CSprite::CreateFromFile()
{
    SDL_Surface* pTemp = SDL_LoadBMP(m_sFileName.c_str());
    if ( pTemp == NULL) return false;

    m_pSurf = SDL_DisplayFormat(pTemp);

    dimensions.x = m_pSurf->w;
    dimensions.y = m_pSurf->h;

    bool bValid = m_pSurf != NULL;

    SDL_FreeSurface(pTemp);

    return bValid;
}

bool CSprite::OnInit()
{
    return CreateFromFile();
}
