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

#ifndef POSITIONDATATYPES_HPP_INCLUDED
#define POSITIONDATATYPES_HPP_INCLUDED

#include <cmath>
#include <math.h>
struct Pos2f
{
    Pos2f( float nX = 0.00, float nY = 0.00) : x(nX), y(nY) {}
    float x,y;
};

struct Pos3f
{
    Pos3f( float nX = 0.00, float nY = 0.00, float nZ = 0.00) : x(nX), y(nY), z(nZ) {}
	Pos3f( const Pos2f& pos ) : x(pos.x), y(pos.y), z(0.0f) {}
    float x,y,z;
};

struct CRect
{
    CRect(float t = 0.0f, float l = 0.0f, float b = 0.0f, float r = 0.0f)
    : top(t)
    , left(l)
    , bottom(b)
    , right(r)
    {


    }

    CRect( const Pos3f& position, const Pos2f& dimension )
        : top( position.y )
        , left( position.x )
        , bottom( top + dimension.y)
        , right( left + dimension.x )
    {

    }

    CRect( const CRect& rect)
        : top( rect.top)
        , left( rect.left)
        , bottom( rect.bottom)
        , right( rect.right )
    {


    }

    inline float Height()
    {
        return fabs(bottom - top);
    }

    inline float Width()
    {
        return fabs(right - left);
    }

    float top;
    float left;
    float bottom;
    float right;
};

#endif // POSITIONDATATYPES_HPP_INCLUDED
