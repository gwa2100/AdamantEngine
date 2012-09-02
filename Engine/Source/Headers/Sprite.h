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

#include "GameObject.h"

#include <string>
using std::string;

class SDL_Surface;

class CSprite : public CGameObject
{

    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Functions<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
public:
    CSprite();
    ~CSprite();

    //Update Function
    virtual bool Update(float deltaTime = 0.0f) { return false;}

    //On Collision Function
    virtual bool OnCollision();

    //Draw the sprite!
    virtual bool Render(SDL_Surface* pDestSurf);

    virtual bool CreateFromFile( const string& sFilename );

protected:
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Variables<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    //Our surface pointers for holding the surface!
    //Surf will hold the sprite image.
    SDL_Surface* m_pSurf;


private:

};


#endif
