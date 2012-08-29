//
//  Sprite.h
//  AdamantEngine
//
//  Created by Timothy Carlisle on 11/6/11.
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

#ifndef Sprite_h
#define Sprite_h

#include "CApp.h"
#include "GameObject.h"
#include "CSound.h"
#include <vector>
#include <algorithm>

//Definetly the most mixed up class! Needs a lot of cleanup!
class Sprite : public GameObject
{
protected:
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Variables<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

    //Our surface pointers for holding the surface!
    //Surf will hold the sprite image.
    SDL_Surface* Surf;

    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Functions<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
public:
    //Update Function
    virtual bool Update();

    //On Collision Function
    virtual bool OnCollision();

    //Draw the sprite!
    bool DrawSprite(SDL_Surface* dst_Surf);

    Sprite();
    virtual ~Sprite();



};


#endif
