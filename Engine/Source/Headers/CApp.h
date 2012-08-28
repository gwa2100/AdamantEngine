//
//  CApp.h
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

#ifndef CApp_h
#define CApp_h

#include <SDL.h>
#include <vector>
#include <algorithm>
#include <string>
#include "Timer.h"
#include "CSound.h"
#include <SDL_mixer.h>
#include <Sprite.h>
#include "PositionDataTypes.h"



using namespace std;

const unsigned int MOVE_SPD = 5;

class CApp {
private:
    bool Running;
public:

    CApp();

    //Engine Core!
    int OnExecute();
    bool OnInit();
    void OnEvent( SDL_Event* Event);
    void OnLoop();
    void OnRender();
    void OnCleanup();

    SDL_Surface* Surf_Display;


    //Some nice helper functions for graphics!
    SDL_Surface* LoadSprite(const char *fileName);
    bool DrawSurface(SDL_Surface *src, SDL_Surface *dst);
    bool DrawSurface(SDL_Surface *src, int src_x, int src_y, SDL_Surface *dst, int dst_x, int dst_y);
    bool DrawSurface(SDL_Surface *src, SDL_Surface *dst, int dst_x, int dst_y);

    //Input data.
    Pos2i inputVelocity;
    short unsigned int movementSpeed;




    //Timing and Event System Stuff alot of of it needs a cleanup, as most likely it is all not needed.
    Timer timer;
    SDL_Event Event;
    bool timerStarted;
    int prevTime;
    int currTime;
    int accTime;
    int gravRate;
    int gravFrame;

    bool jump;
    bool alreadyJump;
    int jumpTime;
    int jumpPower;

    //Use this to make it easy to make a SDL_Rect using integers, good for when a function requires SDL_RECT.
    SDL_Rect RectFiller(int x, int y, int h, int w);

    //Used for the Sprite Pointer Vector for automated rendering and updating, etc.
    //You will pretty much always bind a new Sprite to this system. Just use BindSprite, passing it the pointer to the sprite object.
    std::vector<Sprite*> SpriteList;
    void BindSprite(Sprite* bindMe);

    CSound TestSound;

    //Screen Resolution
    const static unsigned int ScreenResoultionX = 1920;
    const static unsigned int ScreenResolutionY = 1080;


};



bool operator < (Sprite& left,Sprite& right);

#endif