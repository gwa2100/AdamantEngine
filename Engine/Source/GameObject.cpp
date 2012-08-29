//
//  Objects.cpp
//  AdamantEngine
//
//  Created by Timothy Carlisle on 08/29/12.
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
#include "PositionDataTypes.h"
#include "GameObject.h"
#include "CApp.h"


GameObject::GameObject(Pos3i iPosition, Pos2i iDimensions, SDL_Rect iBoundBox,
            bool iUsesCollision, bool iUsesUpdate, bool iUsesRender,
            bool iUsesEvent, bool iUsesCleanup)
{
    position = iPosition;
    dimensions = iDimensions;
    boundBox = iBoundBox;
    usesCollision = iUsesCollision;
    usesUpdate = iUsesUpdate;
    usesRender = iUsesRender;
    usesEvent = iUsesEvent;
    usesCleanup = iUsesCleanup;
    return;
}


//Main Functions

//Move Object Directly
bool GameObject::Move(Pos3i p)
{
    position.x += p.x;
    position.y += p.y;
    position.z += p.z;
    return true;
}
bool GameObject::Move(Pos2i p)
{
    position.x += p.x;
    position.y += p.y;
    return true;
}
bool GameObject::Move(Pos3f p)
{
    position.x += p.x;
    position.y += p.y;
    position.z += p.z;
    return true;
}
bool GameObject::Move(Pos2f p)
{
    position.x += p.x;
    position.y += p.y;
    return true;
}

//Set Positions
bool GameObject::SetPosition(Pos3i p)
{
    position.x = p.x;
    position.y = p.y;
    position.z = p.z;
    return true;
}
bool GameObject::SetPosition(Pos2i p)
{
    position.x = p.x;
    position.y = p.y;
    return true;
}
bool GameObject::SetPosition(Pos3f p)
{
    position.x = p.x;
    position.y = p.y;
    position.z = p.z;
    return true;
}
bool GameObject::SetPosition(Pos2f p)
{
    position.x = p.x;
    position.y = p.y;
    return true;
}

//Get Position
Pos3i GameObject::GetPosition3i()
{
    return position;
}

//Get Dimensions
Pos2i GameObject::GetDimensions2i()
{
    return dimensions;
}

//Get Velocity
Pos3i GameObject::GetVelocity3i()
{
    return velocity;
}

//Move Velocity
bool GameObject::MoveVelocity(Pos3i v)
{
    velocity.x += v.x;
    velocity.y += v.y;
    velocity.z += v.z;
    return true;
}
bool GameObject::MoveVelocity(Pos2i v)
{
    velocity.x += v.x;
    velocity.y += v.y;
    return true;
}
bool GameObject::MoveVelocity(Pos3f v)
{
    velocity.x += v.x;
    velocity.y += v.y;
    velocity.z += v.z;
    return true;
}
bool GameObject::MoveVelocity(Pos2f v)
{
    velocity.x += v.x;
    velocity.y += v.y;
    return true;
}

//Set Velocity
bool GameObject::SetVelocity(Pos3i v)
{
    velocity.x = v.x;
    velocity.y = v.y;
    velocity.z = v.z;
    return true;
}
bool GameObject::SetVelocity(Pos2i v)
{
    velocity.x = v.x;
    velocity.y = v.y;
    return true;
}
bool GameObject::SetVelocity(Pos3f v)
{
    velocity.x = v.x;
    velocity.y = v.y;
    velocity.z = v.z;
    return true;
}
bool GameObject::SetVelocity(Pos2f v)
{
    velocity.x = v.x;
    velocity.y = v.y;
    return true;
}

//Set Bounding Box for collision
bool GameObject::SetBoundingBox(SDL_Rect box)
{
    boundBox = box;
    return true;
}

//Enable Functions
bool GameObject::EnableCollision(bool e)
{
    usesCollision = e;
    return true;
}
bool GameObject::EnableUpdate(bool e)
{
    usesUpdate = e;
    return true;
}
bool GameObject::EnableRender(bool e)
{
    usesRender = e;
    return true;
}
bool GameObject::EnableEvent(bool e)
{
    usesEvent = e;
    return true;
}
bool GameObject::EnableCleanup(bool e)
{
    usesCleanup = e;
    return true;
}

//Overidable Virtual Function for creating object functionality.
//These will be run by the engine based on the bool values above.
//Update will be where velocity effects object position and other
//update requirements are ran.
bool GameObject::Update(float deltaTime)
{
    if (deltaTime > 0.00)
    {
        Pos3i temp;
        temp.x = int(velocity.x * deltaTime);
        temp.y = int(velocity.y * deltaTime);
        temp.z = int(velocity.z * deltaTime);

        Move(temp);
        return true;
    }
    else
    {
        return false;
    }
}
//Render time options, non-overrided function will just display the sprite.
bool GameObject::Render()
{
    return true;
}
//Event handling.  This is where input and other events can be reacted to.
//Note: Need to add event handling parameters.
bool GameObject::Event()
{
    return true;
}
//Cleanup is to be called at end of the engine.  This is where you can do things
//right before shutdown.
bool GameObject::Cleanup()
{
    return true;
}
