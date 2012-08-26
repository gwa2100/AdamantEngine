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

#include "CApp.h"

//Z Comparison (DEPTH)
bool operator < (Sprite& left,Sprite& right)
{
	if  (left.GetLayer() < right.GetLayer()) return true;
	return false;
}

CApp::CApp(){
    Surf_Display = NULL;
    Surf_Background = NULL;
    Surf_Sprite_Player = NULL;
    Surf_Static_Sprite_Platform = NULL;


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

SDL_Rect CApp::RectFiller(int x, int y, int h, int w)
{
    SDL_Rect Temp;
    Temp.x = x;
    Temp.y = y;
    Temp.h = h;
    Temp.w = w;
    return Temp;
}

void CApp::BindSprite(Sprite *bindMe)
{
    int beforeSize = SpriteList.size();
    SpriteList.resize(beforeSize + 1);
    SpriteList[beforeSize] = bindMe;
    bindMe->bindID = beforeSize;
}

int main(int argc, char* argv[]) {
    CApp theApp;
    return theApp.OnExecute();
}
