//
//  CApp.h
//  AdamantEngine
//
//  Created by Timothy Carlisle on 10/26/11.
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

#ifndef CApp_h
#define CApp_h

#include <vector>
#include <SDL/SDL_events.h>

#include "Sound.h"
#include "Timer.h"
#include "PositionDataTypes.h"
#include "GameObject.h"

using std::vector;

const unsigned int MOVE_SPD = 5;

struct SDL_Surface;

class CApp
{
    bool m_bRunning;

public:

    CApp();

    //Engine Core!
    int OnExecute();
    bool OnInit();
    void OnEvent( SDL_Event* pEvent);
    void OnLoop();
    void OnRender();
    void OnCleanup();

    SDL_Surface* m_pSurfDisplay;


    //Some nice helper functions for graphics!
    SDL_Surface* LoadSprite(const char* pszFileName);
    bool DrawSurface(SDL_Surface* pSrc, SDL_Surface* pDst);
    bool DrawSurface(SDL_Surface* pSrc, Sint16 nSrcX, Sint16 nSrcY, SDL_Surface* pDst, Sint16 nDstX, Sint16 nDstY);
    bool DrawSurface(SDL_Surface* pSrc, SDL_Surface* pDst, Sint16 nDstX, Sint16 nDstY);

    //KMS: Should this really be public data??
    //Input data.
    Pos2i m_inputVelocity;
    short unsigned int m_uMovementSpeed;
    //Timing and Event System Stuff alot of of it needs a cleanup, as most likely it is all not needed.
    CTimer m_timer;
    SDL_Event m_event;
    Uint32 m_uPrevTime;
    Uint32 m_uCurrTime;
    Uint32 m_uAccTime;
    int m_nGravRate;
    int m_nGravFrame;

    bool m_bJump;
    bool m_bAlreadyJump;
    int m_nJumpTime;
    int m_nJumpPower;

    //Used for the Sprite Pointer Vector for automated rendering and updating, etc.
    //You will pretty much always bind a new Sprite to this system. Just use BindSprite, passing it the pointer to the sprite object.
    CGameObjectPtrVector m_arObjectList;
    void BindSprite(CGameObject* pBindMe);

    //CSound m_TestSound;

    //Screen Resolution
    const static unsigned int m_ciScreenResoultionX = 1920;
    const static unsigned int m_ciScreenResolutionY = 1080;
};

bool operator < (const CGameObject& left, const CGameObject& right);

#endif
