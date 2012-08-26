//
//  CApp_OnInit.cpp
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

bool CApp::OnInit() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }



// load support for the OGG and MOD sample/music formats
    int flags=MIX_INIT_OGG|MIX_INIT_MOD;
    int initted=Mix_Init(flags);
    if((initted&flags) != flags) {
        printf("Mix_Init: Failed to init required ogg and mod support!\n");
        printf("Mix_Init: %s\n", Mix_GetError());
        // handle error
    }


    if ((Surf_Display = SDL_SetVideoMode(CApp::ScreenResoultionX, CApp::ScreenResolutionY, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN)) == NULL)
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "SkyFarm by: EnvironTek Games, LLC Copyright All Rights Reserved 2011, This", NULL);

    Spr_Player.SetSpritePosition(960, 940, 100, 20);
    Spr_Player.Surf = LoadSprite("paddle.bmp");
    Spr_Player.Render_Surf = LoadSprite("paddle.bmp");
    Spr_Player.usesRender = true;
    Spr_Player.usesInput = true;
    Spr_Player.usesGravity= false;
    Spr_Player.usesCollision = true;
    Spr_Player.needUpdate = true;
    Spr_Player.usesAnimation = false;
    Spr_Player.SetFrames(1);
    Spr_Player.SetCurrentFrame(1);
    Spr_Player.bindID = 100;

    Spr_Ball.SetSpritePosition(200, 20,43,44);
    Spr_Ball.Surf = LoadSprite("ball.bmp");
    Spr_Ball.Render_Surf = LoadSprite("ball.bmp");
    Spr_Ball.usesRender = true;
    Spr_Ball.usesInput = false;
    Spr_Ball.usesGravity = false;
    Spr_Ball.usesCollision = true;
    Spr_Ball.needUpdate = true;
    Spr_Ball.usesAnimation = false;
    Spr_Ball.bindID = 50;
    Spr_Ball.SetSpriteVel(-4,-4);

    for (int x = 0; x < 10; x++)
    {
        Arr_Bricks[x].SetSpritePosition((x*105)+ 30, 200,100,25);
        Arr_Bricks[x].Surf = LoadSprite("bricks.bmp");
        Arr_Bricks[x].Render_Surf = LoadSprite("bricks.bmp");
        Arr_Bricks[x].usesRender = true;
        Arr_Bricks[x].usesInput = false;
        Arr_Bricks[x].usesGravity = false;
        Arr_Bricks[x].usesCollision = true;
        Arr_Bricks[x].needUpdate = true;
        Arr_Bricks[x].usesAnimation = false;
        Arr_Bricks[x].bindID = 200 + x;
        BindSprite(&Arr_Bricks[x]);
    }

    Surf_Background = LoadSprite("sky1080p.bmp");

    BindSprite(&Spr_Player);
    BindSprite(&Spr_Ball);

    CApp::inputVelocityX = 0;
    CApp::inputVelocityY = 0;
    CApp::movementSpeed = MOVE_SPD;
    CApp::prevTime = 0;
    CApp::currTime = 0;
    CApp::accTime = 0;
    CApp::gravRate = 7;
    CApp::gravFrame = 0;

    //Jump stuff
    jump = false;
    alreadyJump = false;
    jumpTime = 0;
    jumpPower = 7;

    TopWall = RectFiller(0,0,2,1920);
    LeftWall = RectFiller(0,2,1088,2);
    RightWall = RectFiller(1918,2,1078,2);
    BottomWall = RectFiller(0,1078,2,1920);

    return true;
}
