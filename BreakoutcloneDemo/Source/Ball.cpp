//
//  Ball.cpp
//  AdamantEngine
//
//  Created by Timothy Carlisle on 07/26/12.
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

#include "Headers/main.h"

bool Ball::OnCollision( ECollision eCollision)
{
    //i dont get this logic..but okay
    //Act on collision
    if (eCollision & (eCOLLISION_BOTTOM | eCOLLISION_TOP) )
    {
        //flip y
        velocity.y *= -1;
        //SetSpriteVel(GetSpriteXVel(),GetSpriteYVel() * -1);
    }
    if (eCollision & (eCOLLISION_LEFT_SIDE | eCOLLISION_RIGHT_SIDE))
    {
        //flip x
        velocity.x *= -1;
        //SetSpriteVel(GetSpriteXVel() * - 1,GetSpriteYVel());
    }
    /*if (eCollision & )
    {
        //flip x and y
        velocity.x *= -1;
        velocity.y *= -1;
        //SetSpriteVel(GetSpriteXVel() * - 1,GetSpriteYVel() * - 1);
    }*/

    return true;
}

bool Ball::Update(float deltaTime /*= 0.0f*/)
{
    Move( Pos2i(velocity.x , velocity.y) );
    return true;
}

Ball::Ball()
{
    direction = 0;

}

Ball::~Ball()
{
    //dtor
}
