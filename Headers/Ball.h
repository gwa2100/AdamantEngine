//
//  Ball.h
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

#ifndef BALL_H
#define BALL_H

#include <CApp.h>


class Ball : public Sprite
{
    public:
        virtual bool OnCollision(int side);
        virtual bool Update();
        int direction; //1 NW 2 NE 3 SW 4 SE 0 STILL
        /** Default constructor */
        Ball();
        /** Default destructor */
        virtual ~Ball();
    protected:
    private:


};

#endif // BALL_H
