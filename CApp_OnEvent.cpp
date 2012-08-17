//
//  CApp_OnEvent.cpp
//  SkyFarm
//
//  Created by Timothy Carlisle on 10/26/11.
//  Copyright 2011 EnvironTek Games, LLC. All rights reserved.
//

#include "CApp.h"

void CApp::OnEvent(SDL_Event* Event) {
    if (Event->type == SDL_QUIT) {
        Running = false;
    }
    if (Event->type == SDL_KEYDOWN) {
        switch (Event->key.keysym.sym){
            case SDLK_LEFT:
                inputVelocityX = -1;
                break;
            case SDLK_RIGHT:
                inputVelocityX = 1;
                break;
            case SDLK_UP:
                jump = true;
                break;
            case SDLK_DOWN:
                inputVelocityY = 1;
                break;
            case SDLK_ESCAPE:
                CApp::Running = false;
            default:
                break;
        }
    }
    if (Event->type == SDL_KEYUP) {
        switch (Event->key.keysym.sym){
            case SDLK_LEFT:
                inputVelocityX = 0;
                break;
            case SDLK_RIGHT:
                inputVelocityX = 0;
                break;
            case SDLK_UP:
                inputVelocityY = 0;
                break;
            case SDLK_DOWN:
                inputVelocityY = 0;
                break;
            default:
                break;
        }
    }
}

