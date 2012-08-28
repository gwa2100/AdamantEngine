//
//  Objects.h
//  AdamantEngine
//
//  Created by Timothy Carlisle on 08/9/12.
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

#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED

#include <CApp.h>
#include "CSound.h"
#include <SDL.h>
#include <vector>
#include <algorithm>
#include "PositionDataTypes.h"

class GameObject
{
protected:
    Pos3i position;
    Pos2i dimensions;

    bool collidable;
    SDL_Rect boundBox;

};


#endif // GAMEOBJECT_H_INCLUDED
