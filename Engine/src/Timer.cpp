//
//  Timer.cpp
//  AdamantEngine
//
//  Created by Timothy Carlisle on 11/5/11.
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
#include "Timer.hpp"
#include <SDL_timer.h>

CTimer::CTimer()    //Initialize the variables
 : m_uStartTicks(0)
 , m_uPausedTicks(0)
 , m_bPaused(false)
 , m_bStarted(false)
{
}

void CTimer::Start()
{
    //Start the timer
    m_bStarted = true;

    //Unpause the timer
    m_bPaused = false;

    //Get the current clock time
    m_uStartTicks = SDL_GetTicks();
}

void CTimer::Stop()
{
    //Stop the timer
    m_bStarted = false;

    //Unpause the timer
    m_bPaused = false;
}


Uint32 CTimer::GetTicks()
{
    //If the timer is running
    if( m_bStarted == true )
    {
        //If the timer is paused
        if( m_bPaused == true )
        {
            //Return the number of ticks when the timer was paused
            return m_uPausedTicks;
        }
        else
        {
            //Return the current time minus the start time
            return SDL_GetTicks() - m_uStartTicks;
        }
    }

    //If the timer isn't running
    return 0;
}


void CTimer::Pause()
{
    //If the timer is running and isn't already paused
    if( ( m_bStarted == true ) && ( m_bPaused == false ) )
    {
        //Pause the timer
        m_bPaused = true;

        //Calculate the paused ticks
        m_uPausedTicks = SDL_GetTicks() - m_uStartTicks;
    }
}


void CTimer::Resume()
{
    //If the timer is paused
    if( m_bPaused == true )
    {
        //Unpause the timer
        m_bPaused = false;

        //Reset the starting ticks
        m_uStartTicks = SDL_GetTicks() - m_uPausedTicks;

        //Reset the paused ticks
        m_uPausedTicks = 0;
    }
}


bool CTimer::IsStarted() const
{
    return m_bStarted;
}

bool CTimer::IsPaused() const
{
    return m_bPaused;
}
