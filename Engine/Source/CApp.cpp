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

const int FrameCap = 60;

#include "PositionDataTypes.h"
#include "CApp.h"

//Z Comparison (DEPTH)
bool operator < (GameObject& left,GameObject& right)
{
	if  (left.GetPosition3i().z < right.GetPosition3i().z) return true;
	return false;
}

CApp::CApp(){
    Surf_Display = NULL;
    Running = true;
}

int CApp::OnExecute() {
    if (OnInit() == false) {
        return -1;
    }



    while (Running) {
        if (timerStarted == false)
        {
            timerStarted = true;
            timer.start();
        }
        if (timerStarted == true)
        {
            prevTime = currTime;
            currTime = SDL_GetTicks();
        }
        accTime = accTime + currTime - prevTime;

        while (SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }
        OnLoop();
        //if (accTime >= 1000/FrameCap)
        //{
            accTime = 0;
            OnRender();
        //}


    }
    OnCleanup();

    return 0;
}


//ENGINE TOOLS

//Create Pos3i from x,y,z
Pos3i CApp::Pos3iFiller(int x, int y, int z)
{
    Pos3i temp;
    temp.x = x;
    temp.y = y;
    temp.z = z;
    return temp;
}
//Create Pos2i from x,y
Pos2i CApp::Pos2iFiller(int x, int y)
{
    Pos2i temp;
    temp.x = x;
    temp.y = y;
    return temp;
}
//Create Pos3f from x,y,z
Pos3f CApp::Pos3fFiller(float x, float y, float z)
{
    Pos3f temp;
    temp.x = x;
    temp.y = y;
    temp.z = z;
    return temp;
}
//Create Pos2f from x,y
Pos2f CApp::Pos2fFiller(float x, float y)
{
    Pos2f temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

//Create rect from x,y,h,w
SDL_Rect CApp::RectFiller(int x, int y, int h, int w)
{
    SDL_Rect Temp;
    Temp.x = x;
    Temp.y = y;
    Temp.h = h;
    Temp.w = w;
    return Temp;
}


void CApp::BindSprite(GameObject *bindMe)
{
    int beforeSize = SpriteList.size();
    SpriteList.resize(beforeSize + 1);
    SpriteList[beforeSize] = bindMe;
}

