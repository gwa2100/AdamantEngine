//
//  Timer.h
//  AdamantEngine
//
//  Created by Timothy Carlisle on 11/6/11.
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

#ifndef Timer_h
#define Timer_h

#include <stdint.h>

class CTimer
{
private:
    //The clock time when the timer started
    uint32_t m_uStartTicks;

    //The ticks stored when the timer was paused
    uint32_t m_uPausedTicks;

    //The timer status
    bool m_bPaused;
    bool m_bStarted;

public:
    //Initializes variables
    CTimer();

    //The various clock actions
    void Start();
    void Stop();
    void Pause();
    void Resume();

    //Gets the timer's time
    uint32_t GetTicks();

    //Checks the status of the timer
    bool IsStarted() const;
    bool IsPaused() const;
};

#endif
