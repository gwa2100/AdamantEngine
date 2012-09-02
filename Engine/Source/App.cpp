//
//  CApp.cpp
//  AdamantEngine
//
//  Created by Timothy Carlisle on 10/26/11.
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

const int g_ciFrameCap = 60;

//Z Comparison (DEPTH)
bool operator < (const CGameObject& left, const CGameObject& right)
{
	if  (left.GetPosition3i().z < right.GetPosition3i().z) return true;
	return false;
}

CApp::CApp()
 : m_bRunning( true )
 , m_pSurfDisplay(NULL)
 , m_uPrevTime(0)
 , m_uCurrTime(0)
 , m_uAccTime(0)
 , m_nGravRate(0)
 , m_nGravFrame(0)
 , m_bJump(false)
 , m_bAlreadyJump(false)
 , m_nJumpTime(0)
 , m_nJumpPower(0)

{
}

int CApp::OnExecute() {
    if (OnInit() == false)
    {
        return -1;
    }

    while (m_bRunning)
    {
        if (m_timer.IsStarted() == false)
        {
            m_timer.Start();
        }

        if (m_timer.IsStarted() == true)
        {
            m_uPrevTime = m_uCurrTime;
            m_uCurrTime = SDL_GetTicks();
        }

        m_uAccTime = m_uAccTime + m_uCurrTime - m_uPrevTime;

        //KMS: maybe we could make m_event a local variable instead that way we can forward declare SDL_Event unless we look at the "last" event that happend.
        while (SDL_PollEvent(&m_event))
        {
            OnEvent(&m_event);
        }
        OnLoop();
        //if (accTime >= 1000/ g_ciFrameCap)
        //{
            m_uAccTime = 0;
            OnRender();
        //}
    }

    OnCleanup();

    return 0;
}

void CApp::BindSprite(CGameObject* pBindMe)
{
    //lets let vector do the memory management of the internal buffers...
    m_arObjectList.push_back( pBindMe );
}

