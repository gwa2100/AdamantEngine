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
#include "CApp.h"

struct CDefault_Rect;
class GameObject
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
    bool usesCollision;
    bool usesUpdate;
    bool usesRender;
    bool usesEvent;
    bool usesCleanup;



    GameObject(Pos3i iPosition = Pos3i(), Pos2i iDimensions = Pos2i(), SDL_Rect iBoundBox = CDefault_Rect,
               bool iUsesCollision = false, bool iUsesUpdate = false, bool iUsesRender = false,
               bool iUsesEvent = false, bool iUsesCleanup = false);


    //Main Functions

    //Move Object Directly
    bool Move(Pos3i);
    bool Move(Pos2i);
    bool Move(Pos3f);
    bool Move(Pos2f);

    //Set Positions
    bool SetPosition(Pos3i);
    bool SetPosition(Pos2i);
    bool SetPosition(Pos3f);
    bool SetPosition(Pos2f);

    //Get Position
    Pos3i GetPosition3i();

    //Get Dimensions
    Pos2i GetDimensions2i();

    //Get Velocity
    Pos3i GetVelocity3i();

    //Move Velocity
    bool MoveVelocity(Pos3i);
    bool MoveVelocity(Pos2i);
    bool MoveVelocity(Pos3f);
    bool MoveVelocity(Pos2f);

    //Set Velocity
    bool SetVelocity(Pos3i);
    bool SetVelocity(Pos2i);
    bool SetVelocity(Pos3f);
    bool SetVelocity(Pos2f);

    //Set Bounding Box for collision
    bool SetBoundingBox(SDL_Rect);

    //Enable Functions
    bool EnableCollision(bool);
    bool EnableUpdate(bool);
    bool EnableRender(bool);
    bool EnableEvent(bool);
    bool EnableCleanup(bool);

    //Overidable Virtual Function for creating object functionality.
    //These will be run by the engine based on the bool values above.
    //Update will be where velocity effects object position and other
    //update requirements are ran.
    virtual bool Update(float deltaTime);
    //Render time options, non-overrided function will just display the sprite.
    virtual bool Render();
    //Event handling.  This is where input and other events can be reacted to.
    //Note: Need to add event handling parameters.
    virtual bool Event();
    //Cleanup is to be called at end of the engine.  This is where you can do things
    //right before shutdown.
    virtual bool Cleanup();

    virtual ~GameObject();
};


#endif // GAMEOBJECT_H_INCLUDED
