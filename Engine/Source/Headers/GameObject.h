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

#include "PositionDataTypes.h"

class CGameObject
{
protected:
    //Position of GameObject X,Y,Z in Pos3i format
    Pos3i position;
    //Dimensions of Game Object W,H in Pos2i format
    Pos2i dimensions;
    //Dimensions of bounding box used for collisions in SDL_Rect format.
    SDL_Rect boundBox;
    //Velocity of object for use in update movement.
    Pos3i velocity;

public:
    //KMS: maybe make these private and have a const getter..
    bool m_bUsesCollision;
    bool m_bUsesUpdate;
    bool m_bUsesRender;
    bool m_bUsesEvent;
    bool m_bUsesCleanup;



    CGameObject(Pos3i iPosition = Pos3i(), Pos2i iDimensions = Pos2i(), SDL_Rect iBoundBox = (SDL_Rect)CDefault_Rect(),
               bool bUsesCollision = false, bool bUsesUpdate = false, bool bUsesRender = false,
               bool bUsesEvent = false, bool bUsesCleanup = false);


    //Main Functions

    //Move Object Directly
    bool Move(const Pos3i& pos);
    bool Move(const Pos2i& pos);
    bool Move(const Pos3f& pos);
    bool Move(const Pos2f& pos);

    //Set Positions
    bool SetPosition(const Pos3i& pos);
    bool SetPosition(const Pos2i& pos);
    bool SetPosition(const Pos3f& pos);
    bool SetPosition(const Pos2f& pos);

    //Get Position
    Pos3i GetPosition3i() const;

    //Get Dimensions
    Pos2i GetDimensions2i() const;

    //Get Velocity
    Pos3i GetVelocity3i() const;

    //Move Velocity
    bool MoveVelocity(const Pos3i& vel);
    bool MoveVelocity(const Pos2i& vel);
    bool MoveVelocity(const Pos3f& vel);
    bool MoveVelocity(const Pos2f& vel);

    //Set Velocity
    bool SetVelocity(const Pos3i& vel);
    bool SetVelocity(const Pos2i& vel);
    bool SetVelocity(const Pos3f& vel);
    bool SetVelocity(const Pos2f& vel);

    //Set Bounding Box for collision
    bool SetBoundingBox(const SDL_Rect& rect);

    //Enable Functions
    bool EnableCollision(bool bEnable);
    bool EnableUpdate(bool bEnable);
    bool EnableRender(bool bEnable);
    bool EnableEvent(bool bEnable);
    bool EnableCleanup(bool bEnable);

    //Overidable Virtual Function for creating object functionality.
    //These will be run by the engine based on the bool values above.
    //Update will be where velocity effects object position and other
    //update requirements are ran.
    virtual bool Update(float deltaTime = 0.0f);
    //Render time options, non-overrided function will just display the sprite.
    virtual bool Render();
    //Event handling.  This is where input and other events can be reacted to.
    //Note: Need to add event handling parameters.
    virtual bool Event();
    //Cleanup is to be called at end of the engine.  This is where you can do things
    //right before shutdown.
    virtual bool Cleanup();

    virtual ~CGameObject();
};

#include <vector>
using std::vector;

class CGameObjectPtrVector : public vector< CGameObject* >
{
    public:
    CGameObjectPtrVector() {}
    ~CGameObjectPtrVector()
    {
        ResetContent();
    }

    void ResetContent()
    {
        if ( size() == 0 ) return;

        CGameObject** ppObjects = data();
        for(size_t n = 0; n < size(); n++)
        {
            delete ppObjects[n];
        }

        clear();

        CGameObjectPtrVector().swap( *this );
    }

};



#endif // GAMEOBJECT_H_INCLUDED
