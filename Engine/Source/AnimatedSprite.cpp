//
//  AnimatedSprite.h
//  AdamantEngine
//
//  Created by Kevin Sucre on 08/30/2012.
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

#include "AnimatedSprite.h"

CAnimatedSprite::CAnimatedSprite()
{
    //ctor
}

CAnimatedSprite::~CAnimatedSprite()
{
    //dtor
}

bool CAnimatedSprite::Update(float fDeltaTime /*= 0.0f*/)
{
    Uint32 uCurrentMs = m_uCurrentTick - m_uStartTick;

    if ( uCurrentMs > m_uAnimateMS )
    {
        m_uStartTick = m_uCurrentTick;
        m_nCurrentFrame = ++m_nCurrentFrame % m_nMaxFrames;
    }

    return true;
}

bool CAnimatedSprite::Render(SDL_Surface* pDestSurf)
{
    Pos3i pos = GetPosition3i();
    Pos2i dim = GetDimensions2i();
    SDL_Rect rect = CDefault_Rect(pos.x, pos.y, dim.x, dim.y);
    SDL_Rect src = CDefault_Rect(pos.x * m_nCurrentFrame, 0, dim.x, dim.y );

    if (SDL_BlitSurface(m_pSurf, NULL, pDestSurf, &rect) != 1)
    {
        return false;
    }
    else
    {
        return true;
    }

}

void CAnimatedSprite::StartAnimation()
{
    m_uStartTick = m_uCurrentTick;
}

bool CAnimatedSprite::CreateFromFile( const string& sFilename, unsigned int nFrames, Uint32 uDelayInMS )
{
    m_sFileName = sFilename;
    bool bValid = CSprite::CreateFromFile();
    if ( !bValid ) return bValid;

    dimensions.x = m_pSurf->w / nFrames;
    dimensions.y = m_pSurf->h;

    m_nMaxFrames = nFrames;
    m_nCurrentFrame = 0;
    m_uAnimateMS = uDelayInMS;

    return bValid;
}
