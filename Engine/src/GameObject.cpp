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
#include "../include/GameObject.hpp"
#include "App.hpp"

CGameObject::CGameObject(Pos3f iPosition, Pos2f iDimensions, CRect rcBoundBox,
            bool bCollision, bool bUpdate, bool bRender,
            bool bEvent, bool bCleanup)
{
    position = iPosition;
    dimensions = iDimensions;
    boundBox = rcBoundBox;
    m_bCollision = bCollision;
    m_bUpdate = bUpdate;
    m_bRender = bRender;
    m_bEvent = bEvent;
    m_bCleanup = bCleanup;
    return;
}

CGameObject::~CGameObject()
{


}

//Main Functions

//Move Object Directly
void CGameObject::Move(const Pos3f& pos)
{
    position.x += pos.x;
    position.y += pos.y;
    position.z += pos.z;
}

void CGameObject::SetPosition(const Pos3f& pos)
{
    position.x = pos.x;
    position.y = pos.y;
    position.z = pos.z;
}

//Get Position
Pos3f CGameObject::GetPosition() const
{
    return position;
}

//Get Dimensions
Pos2f CGameObject::GetDimensions() const
{
    return dimensions;
}

//Get Velocity
Pos3f CGameObject::GetVelocity() const
{
    return velocity;
}

void CGameObject::MoveVelocity(const Pos3f& vel)
{
    velocity.x += vel.x;
    velocity.y += vel.y;
    velocity.z += vel.z;
}

void CGameObject::SetVelocity(const Pos3f& vel)
{
    velocity.x = vel.x;
    velocity.y = vel.y;
    velocity.z = vel.z;
}

//Set Bounding Box for collision
void CGameObject::SetBoundingBox(const CRect& box)
{
    boundBox = box;
}

//Overidable Virtual Function for creating object functionality.
//These will be run by the engine based on the bool values above.
//Update will be where velocity effects object position and other
//update requirements are ran.
void CGameObject::Update(float deltaTime)
{
    Move(velocity);
}
//Render time options, non-overrided function will just display the sprite.
void CGameObject::Render(HSURFACE hDestSurf)
{

}
//Event handling.  This is where input and other events can be reacted to.
//Note: Need to add event handling parameters.
//Cleanup is to be called at end of the engine.  This is where you can do things
//right before shutdown.
void CGameObject::Cleanup()
{
    return;
}
