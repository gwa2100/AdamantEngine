//
//  CApp_OnEvent.cpp
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

