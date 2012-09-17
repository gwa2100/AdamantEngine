//
//  main.cpp
//  AdamantEngine::RPGDemo
//
//  Created by Bryan Monsalvatge on 8/28/12.
/*
   Copyright 2011-2012 Bryan Monsalvatge

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

#include "Sprite.h"
#include "AdamantEngine.h"

using namespace std;



class PlayerSprite : public CSprite
{
    //virtual bool Event(SDL_Event*);
    virtual bool Update(float deltaTime = 1.0f){Move(velocity);};
};

/*bool PlayerSprite::Event(SDL_Event* pEvent)
{
    if (pEvent->type == SDL_KEYDOWN) {
        switch (pEvent->key.keysym.sym){
            case SDLK_LEFT:
                velocity.x = 1;
                break;
            case SDLK_RIGHT:
                velocity.x = 1;
                break;
            case SDLK_UP:
                velocity.y = 1;
                break;
            case SDLK_DOWN:
                velocity.y = 1;
                break;
            default:
                break;
        }
    }
    if (pEvent->type == SDL_KEYUP) {
        switch (pEvent->key.keysym.sym){
            case SDLK_LEFT:
                velocity.x = 0;
                break;
            case SDLK_RIGHT:
                velocity.x = 0;
                break;
            case SDLK_UP:
                velocity.y = 0;
                break;
            case SDLK_DOWN:
                velocity.y = 0;
                break;
            default:
                break;
        }
    }
    return true;
}
*/

int main(int argc, char* argv[])
{
    CApp* theApp = new CApp();
    PlayerSprite* player1 = new PlayerSprite();
    player1->SetFileName("C:/Users/Gaming/Documents/GitHub/AdamantEngine/bin/Debug/Images/toon.bmp");
    player1->SetPosition(Pos2i(50,50));
    player1->SetVelocity(Pos2i(0,0));
    player1->EnableEvent(true);
    player1->EnableCleanup(true);
    player1->EnableRender(true);
    player1->EnableUpdate(true);
    theApp->BindSprite(player1);
    SDL_Surface* Test;
    Test = SDL_LoadBMP("Images/toon.bmp");
    //SDL_BlitSurface( Test, NULL, m_pSurfaceDisplay, NULL );

    return theApp->OnExecute();

}
