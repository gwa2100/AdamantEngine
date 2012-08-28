//
//  Bricks.cpp
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

bool Bricks::OnCollision()
{
    Bricks::Impact();
    return true;
}

bool Bricks::Impact()
{
    //Destroy on impact!
    //We will just make it uncollidable.
    Bricks::usesCollision = false;
    Bricks::usesRender = false;
    return true;
}

bool Bricks::Update()
{
    //No required update at this time.
    return true;
}

Bricks::Bricks()
{
    //ctor
    Surf = NULL;
}

Bricks::~Bricks()
{
    //dtor
}
