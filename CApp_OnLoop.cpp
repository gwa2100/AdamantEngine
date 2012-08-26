//
//  CApp_OnLoop.cpp
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
//#include <iostream>

using namespace std;

void CApp::OnLoop(){
    SDL_Rect Temp;
    Temp = Spr_Player.GetSpritePos();
    Spr_Player.oldX = Temp.x;
    Spr_Player.oldY = Temp.y;

//NOT USED RIGHT NOW!!!
/*
    gravFrame += 1;
    //Jump works as jetpack right now, if we want standard jump, it needs work.
    if (jump)
    {
        jump = false;
        inputVelocityY = -1;
    }
*/

    //SpriteList UserInput!

    for (unsigned int x = 0; x < SpriteList.size(); x++) {
        if (SpriteList[x]->usesInput)
        {
            SpriteList[x]->SetSpriteVel(inputVelocityX * movementSpeed ,0);     //(inputVelocityX * movementSpeed, inputVelocityY * movementSpeed);
        }
    }

//NOT USED RIGHT NOW!
/*
    if (gravFrame >= gravRate)
    {
        gravFrame = 0;
        //SpriteList GravityInput!

        for (unsigned int x = 0; x < SpriteList.size(); x++) {
            if (SpriteList[x]->usesGravity)
            {
                SpriteList[x]->SetSpriteVel(SpriteList[x]->GetSpriteXVel(),SpriteList[x]->GetSpriteYVel() + 1);
            }
        }

    }
*/

    //Run Update
    for (unsigned int x = 0; x < SpriteList.size(); x++) {
        if (SpriteList[x]->needUpdate)
        {
            SpriteList[x]->Update();
        }
    }



    //SpriteList UpdatePosition!
/*
    for (unsigned int x = 0; x < SpriteList.size(); x++) {
        SpriteList[x]->MoveSprite(SpriteList[x]->GetSpriteXVel(), SpriteList[x]->GetSpriteYVel());
    }
*/

    //Check Paddle and ball collision.
    if (Spr_Ball.CheckCollision(Spr_Player.GetSpritePos()))
    {
        bool impactSolved = false;
        if ((Spr_Player.GetSpritePos().x + (Spr_Player.GetSpritePos().w / 2)) > (Spr_Ball.GetSpritePos().x + (Spr_Ball.GetSpritePos().w / 2)))
        {
            if (Spr_Ball.GetSpriteVel().x > 0)
            {
                Spr_Ball.SetSpriteVel(int(Spr_Ball.GetSpriteVel().x * - 1.5), int(Spr_Ball.GetSpriteVel().y * 1.2));
                Spr_Ball.OnCollision(1);
                impactSolved = true;
            }
        }

        if ((Spr_Player.GetSpritePos().x + (Spr_Player.GetSpritePos().w / 2)) < (Spr_Ball.GetSpritePos().x + (Spr_Ball.GetSpritePos().w / 2)))
        {
            if (Spr_Ball.GetSpriteVel().x < 0)
            {
                Spr_Ball.SetSpriteVel(int(Spr_Ball.GetSpriteVel().x * - 1.5), int(Spr_Ball.GetSpriteVel().y * 1.2));
                Spr_Ball.OnCollision(1);
                impactSolved = true;
            }
        }

        if (((Spr_Player.GetSpritePos().x + (Spr_Player.GetSpritePos().w / 2)) - 7 ) < (Spr_Ball.GetSpritePos().x + (Spr_Ball.GetSpritePos().w / 2) > (Spr_Player.GetSpritePos().x + (Spr_Player.GetSpritePos().w / 2)) + 7 ))
        {
            if (Spr_Ball.GetSpriteVel().x < 0)
            {
                Spr_Ball.SetSpriteVel(Spr_Ball.GetSpriteVel().x, int(Spr_Ball.GetSpriteVel().y * 1.5));
                Spr_Ball.OnCollision(1);
                impactSolved = true;
            }
        }

        if (!impactSolved)
        {
            Spr_Ball.OnCollision(1);
        }
    }

    //Check bricks for collision.

    for (unsigned short int x = 0; x < 10; x++)
    {
        if (Arr_Bricks[x].usesCollision)
        {
            if (Spr_Ball.CheckCollision(Arr_Bricks[x].GetSpritePos()))
            {
                SDL_Rect brickRect = Arr_Bricks[x].GetSpritePos();
                SDL_Rect ballRect = Spr_Ball.GetSpritePos();
                Spr_Ball.OnCollision(1);
                Arr_Bricks[x].OnCollision();
                /*if (((ballRect.x + ballRect.w) > brickRect.x) && (ballRect.x < (brickRect.x + brickRect.w)))
                {
                    Spr_Ball.OnCollision(2);
                    Arr_Bricks[x].OnCollision();
                }
                if (((ballRect.y + ballRect.h) > brickRect.y) && (ballRect.y < (brickRect.y + brickRect.h)))
                {
                    Spr_Ball.OnCollision(1);
                    Arr_Bricks[x].OnCollision();
                }
                */
                //(ballRect.x + ballRect.w) >= (brickRect.x) && ((ballRect.x) <= (brickRect.x + brickRect.w))
                //(ballRect.y + ballRect.h) >= (brickRect.y) && ((ballRect.y) <= (brickRect.y + brickRect.h))
            }
        }
    }





// Check Ball for wall collisions with bounce walls.

    if (Spr_Ball.GetSpritePos().x <= 0)
    {
        Spr_Ball.OnCollision(2);
    }
    if (Spr_Ball.GetSpritePos().x + Spr_Ball.GetSpritePos().w >= 1920)
    {
        Spr_Ball.OnCollision(2);
    }
    if (Spr_Ball.GetSpritePos().y <= 0)
    {
        Spr_Ball.OnCollision(1);
    }
    if (Spr_Ball.GetSpritePos().y + Spr_Ball.GetSpritePos().h >= 1080)
    {
        CApp::Running = false;
    }






//Collision checking... For now we will just do per item collision checking, if the need arises we will implement an automatic system.
/*
    if (Spr_Player.CheckCollision(Spr_Ball.GetSpritePos()))
    {
        Spr_Player.SetSpritePosition(RectFiller(Spr_Player.oldX, Spr_Player.oldY, 0, 0));
    }
*/


//Run Animation updates
//NOT USED RIGHT NOW!
/*
    for (unsigned int x = 0; x < SpriteList.size(); x++) {
        if (SpriteList[x]->usesAnimation)
        {
            //SpriteList[x]->AnimationUpdate();
        }
    }
*/

    //Sort the sprites into order
    //sort(SpriteList.begin(), SpriteList.end());



}


//NOTES: NEED TO ADD ability to translate sprite vel to movement!
