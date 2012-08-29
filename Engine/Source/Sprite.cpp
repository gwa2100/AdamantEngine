//
//  Sprite.cpp
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

#include "Sprite.h"
#include "PositionDataTypes.h"




bool Sprite::DrawSprite(SDL_Surface *dst_Surf)
{
    Pos3i pos = GetPosition3i();
    Pos2i dim = GetDimensions2i();
    SDL_Rect temp;
    temp.x = pos.x;
    temp.y = pos.y;
    temp.w = dim.x;
    temp.h = dim.y;
    if (SDL_BlitSurface(Surf, NULL, dst_Surf, &temp) != 1)
    {
        return false;
    }
    else
    {
        return true;
    }

}


bool Sprite::OnCollision()
{
    //Anything for when collision is thrown, typical action is played out by Check Collision, should really be changed to work inside here!
    return true;
}

Sprite::Sprite()
{
    Surf = NULL;
}

Sprite::~Sprite()
{
    if (Surf != NULL)
    {
        SDL_FreeSurface(Surf);
    }
}


