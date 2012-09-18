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
#include "../include/adamantengine.hpp"

CAnimatedSprite::CAnimatedSprite()
{
    //ctor
}

CAnimatedSprite::~CAnimatedSprite()
{
    //dtor
}

void CAnimatedSprite::Update(float fDeltaTime /*= 0.0f*/)
{
    uint32_t uCurrentMs = m_uCurrentTick - m_uStartTick;

    if ( uCurrentMs > m_uAnimateMS )
    {
        m_uStartTick = m_uCurrentTick;
        //Operation here on m_nCurrentFrame may be undefined!  Maybe use m_nCurrentFrame ++ before modulu operation occurs to set current frame.
        m_nCurrentFrame = ++m_nCurrentFrame % m_nMaxFrames;
    }
}

void CAnimatedSprite::Render(HSURFACE hDstSurf)
{
    Pos3f pos = GetPosition();
    Pos2f dim = GetDimensions();

    CRect rect(pos,dim);

    //Eventually this will have a src rect that will point to current frame.

    AmtBlit( m_hSurf, NULL, hDstSurf, &rect);
}

void CAnimatedSprite::StartAnimation()
{
    m_uStartTick = m_uCurrentTick;
}

bool CAnimatedSprite::CreateFromFile( const string& sFilename, unsigned int nFrames, uint32_t uDelayInMS )
{
    bool bValid = CSprite::CreateFromFile( sFilename );
    if ( !bValid ) return bValid;

    dimensions.x = dimensions.x / nFrames;

    m_nMaxFrames = nFrames;
    m_nCurrentFrame = 0;
    m_uAnimateMS = uDelayInMS;

    return bValid;
}
