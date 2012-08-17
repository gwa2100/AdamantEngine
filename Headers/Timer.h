//
//  Timer.h
//  SkyFarm
//
//  Created by Timothy Carlisle on 11/6/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SkyFarm_Timer_h
#define SkyFarm_Timer_h

#include <SDL.h>
#include <vector>
#include <algorithm>
#include "Sprite.h"
#include "CApp.h"



class Timer
{
private:
    //The clock time when the timer started
    int startTicks;

    //The ticks stored when the timer was paused
    int pausedTicks;

    //The timer status
    bool paused;
    bool started;

public:
    //Initializes variables
    Timer();

    //The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();

    //Gets the timer's time
    int get_ticks();

    //Checks the status of the timer
    bool is_started();
    bool is_paused();
};

#endif
