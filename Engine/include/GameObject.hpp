//
//  Objects.h
//  AdamantEngine
//
//  Created by Timothy Carlisle on 08/9/12.
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

#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED

#include "PositionDataTypes.hpp"
#include "CollisionItem.hpp"
#include <stdint.h>

typedef void* HSURFACE;

class CGameObject
{
    friend class CApp;
    friend class TileEngine;

protected:
    //Position of GameObject X,Y,Z in Pos3i format
    Pos3f position;
    //Dimensions of Game Object W,H in Pos2i format
    Pos2f dimensions;
    //Dimensions of bounding box used for collisions in SDL_Rect format.
    CRect boundBox;
    //Velocity of object for use in update movement.
    Pos3f velocity;
    //The timer
    uint32_t m_uOldTick;
    uint32_t m_uCurrentTick;

    bool m_bCollision;
    bool m_bUpdate;
    bool m_bRender;
    bool m_bEvent;
    bool m_bCleanup;
    bool m_bTime;

public:
    //KMS: maybe make these private and have a const getter..

    CGameObject(Pos3f iPosition = Pos3f(), Pos2f iDimensions = Pos2f(), CRect rcBoundBox = CRect(),
               bool bCollision = false, bool bUpdate = false, bool bRender = false,
               bool bEvent = false, bool bCleanup = false);


    //Move Object Directly
    void Move(const Pos3f& pos);
    //Set Positions
    void SetPosition(const Pos3f& pos);
    //Get Position
    Pos3f GetPosition() const;

    //Get Dimensions
    Pos2f GetDimensions() const;

    //Get Velocity
    Pos3f GetVelocity() const;
    //Move Velocity
    void MoveVelocity(const Pos3f& vel);
    //Set Velocity
    void SetVelocity(const Pos3f& vel);

    //Set Bounding Box for collision
    void SetBoundingBox(const CRect& rect);

    void SetCollision(bool bEnable) { m_bCollision = bEnable; }
    bool GetCollision() const { return m_bCollision; }


    void SetUpdate(bool bEnable) { m_bUpdate = bEnable; }
    bool GetUpdate() const { return m_bUpdate; }

    void SetRender(bool bEnable) { m_bRender = bEnable; }
    bool GetRender() const { return m_bRender; }

    void SetEvent(bool bEnable) { m_bEvent = bEnable; }
    bool GetEvent() const { return m_bEvent; }

    void SetCleanup(bool bEnable) { m_bCleanup = bEnable; }
    bool GetCleanup() const { return m_bCleanup; }

    void SetTime(bool bEnable) { m_bTime = bEnable; }
    bool GetTime() const { return m_bTime; }

    virtual ~CGameObject();

protected:

    //Update the object
    virtual void Update(float deltaTime = 0.0f);
    //Render, do not use
    virtual void Render(HSURFACE hDestSurf);
    //if you want to control the input do it here
    inline virtual void Event(const Pos3f& inputVelocity) { SetVelocity( inputVelocity ); }
    //this is always called?
    virtual void Cleanup();
    //object collision.
    inline virtual void OnCollision( ECollision eCollision, float fXAmt, float fYAmt) { return; }
	inline virtual void OnTimer( uint32_t uCurrentTick ) 
	{ 
		m_uOldTick = m_uCurrentTick;
		m_uCurrentTick = uCurrentTick;
	}
};




#endif // GAMEOBJECT_H_INCLUDED
