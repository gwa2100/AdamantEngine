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

#include "GameObject.hpp"
#include <string>
using std::string;

class CApp;

class CSprite : public CGameObject
{
    friend class CApp;
    friend class TileEngine;

public:
    CSprite();
    ~CSprite();

    //Create from a bmp file.
    bool CreateFromFile( const string& sFilename );

protected:
    //Draw the sprite!
    virtual void Render(HSURFACE hDestSurf);


    HSURFACE m_hSurf;
};


#endif
