//
//  POSITIONDATATYPES.h
//  AdamantEngine
//
//  Created by Timothy Carlisle on 08/26/12.
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

#ifndef POSITIONDATATYPES_H_INCLUDED
#define POSITIONDATATYPES_H_INCLUDED

#include <SDL/SDL.h>

struct Pos3i
{
    Pos3i( int nX = 0, int nY = 0, int nZ = 0) : x(nX), y(nY), z(nZ) {}
    int x,y,z;
};

struct Pos2i
{
    Pos2i( int nX = 0, int nY = 0) : x(nX), y(nY) {}
    int x, y;
};

struct Pos3f
{
    Pos3f( float nX = 0.00, float nY = 0.00, float nZ = 0.00) : x(nX), y(nY), z(nZ) {}
    float x,y,z;
};

struct Pos2f
{
    Pos2f( float nX = 0.00, float nY = 0.00) : x(nX), y(nY) {}
    float x,y;
};

class CDefault_Rect : public SDL_Rect
{
public:
    CDefault_Rect( Sint16 nX = 0, Sint16 nY = 0, Uint16 uW = 0, Uint16 uH = 0) { x = nX; y = nY; w = uW; h = uH;};
};

#endif // POSITIONDATATYPES_H_INCLUDED
