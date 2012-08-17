//
//  main.cpp
//  SkyFarm
//
//  Created by Timothy Carlisle on 10/26/11.
//  Copyright 2011 EnvironTek Games, LLC. All rights reserved.
//

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
