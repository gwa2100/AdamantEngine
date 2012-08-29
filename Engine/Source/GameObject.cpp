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
#include "GameObject.h"

CGameObject::CGameObject(Pos3i iPosition, Pos2i iDimensions, SDL_Rect iBoundBox,
            bool bUsesCollision, bool bUsesUpdate, bool bUsesRender,
            bool bUsesEvent, bool bUsesCleanup)
{
    position = iPosition;
    dimensions = iDimensions;
    boundBox = iBoundBox;
    m_bUsesCollision = bUsesCollision;
    m_bUsesUpdate = bUsesUpdate;
    m_bUsesRender = bUsesRender;
    m_bUsesEvent = bUsesEvent;
    m_bUsesCleanup = bUsesCleanup;
    return;
}

CGameObject::~CGameObject()
{


}

//Main Functions

//Move Object Directly
bool CGameObject::Move(const Pos3i& pos)
{
    position.x += pos.x;
    position.y += pos.y;
    position.z += pos.z;
    return true;
}

bool CGameObject::Move(const Pos2i& pos)
{
    position.x += pos.x;
    position.y += pos.y;
    return true;
}

bool CGameObject::Move(const Pos3f& pos)
{
    position.x += pos.x;
    position.y += pos.y;
    position.z += pos.z;
    return true;
}

bool CGameObject::Move(const Pos2f& pos)
{
    position.x += pos.x;
    position.y += pos.y;
    return true;
}

//Set Positions
bool CGameObject::SetPosition(const Pos3i& pos)
{
    position.x = pos.x;
    position.y = pos.y;
    position.z = pos.z;
    return true;
}

bool CGameObject::SetPosition(const Pos2i& pos)
{
    position.x = pos.x;
    position.y = pos.y;
    return true;
}

bool CGameObject::SetPosition(const Pos3f& pos)
{
    position.x = pos.x;
    position.y = pos.y;
    position.z = pos.z;
    return true;
}

bool CGameObject::SetPosition(const Pos2f& pos)
{
    position.x = pos.x;
    position.y = pos.y;
    return true;
}

//Get Position
Pos3i CGameObject::GetPosition3i() const
{
    return position;
}

//Get Dimensions
Pos2i CGameObject::GetDimensions2i() const
{
    return dimensions;
}

//Get Velocity
Pos3i CGameObject::GetVelocity3i() const
{
    return velocity;
}

//Move Velocity
bool CGameObject::MoveVelocity(const Pos3i& vel)
{
    velocity.x += vel.x;
    velocity.y += vel.y;
    velocity.z += vel.z;
    return true;
}

bool CGameObject::MoveVelocity(const Pos2i& vel)
{
    velocity.x += vel.x;
    velocity.y += vel.y;
    return true;
}

bool CGameObject::MoveVelocity(const Pos3f& vel)
{
    velocity.x += vel.x;
    velocity.y += vel.y;
    velocity.z += vel.z;
    return true;
}

bool CGameObject::MoveVelocity(const Pos2f& vel)
{
    velocity.x += vel.x;
    velocity.y += vel.y;
    return true;
}

//Set Velocity
bool CGameObject::SetVelocity(const Pos3i& vel)
{
    velocity.x = vel.x;
    velocity.y = vel.y;
    velocity.z = vel.z;
    return true;
}

bool CGameObject::SetVelocity(const Pos2i& vel)
{
    velocity.x = vel.x;
    velocity.y = vel.y;
    return true;
}

bool CGameObject::SetVelocity(const Pos3f& vel)
{
    velocity.x = vel.x;
    velocity.y = vel.y;
    velocity.z = vel.z;
    return true;
}
bool CGameObject::SetVelocity(const Pos2f& vel)
{
    velocity.x = vel.x;
    velocity.y = vel.y;
    return true;
}

//Set Bounding Box for collision
bool CGameObject::SetBoundingBox(const SDL_Rect& box)
{
    boundBox = box;
    return true;
}

//Enable Functions
bool CGameObject::EnableCollision(bool bEnable)
{
    m_bUsesCollision = bEnable;
    return true;
}

bool CGameObject::EnableUpdate(bool bEnable)
{
    m_bUsesUpdate = bEnable;
    return true;
}

bool CGameObject::EnableRender(bool bEnable)
{
    m_bUsesRender = bEnable;
    return true;
}

bool CGameObject::EnableEvent(bool bEnable)
{
    m_bUsesEvent = bEnable;
    return true;
}

bool CGameObject::EnableCleanup(bool bEnable)
{
    m_bUsesCleanup = bEnable;
    return true;
}

//Overidable Virtual Function for creating object functionality.
//These will be run by the engine based on the bool values above.
//Update will be where velocity effects object position and other
//update requirements are ran.
bool CGameObject::Update(float deltaTime)
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
bool CGameObject::Render()
{
    return true;
}
//Event handling.  This is where input and other events can be reacted to.
//Note: Need to add event handling parameters.
bool CGameObject::Event()
{
    return true;
}
//Cleanup is to be called at end of the engine.  This is where you can do things
//right before shutdown.
bool CGameObject::Cleanup()
{
    return true;
}
