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
#include "TileEngine.h"
#include "../include/adamantengine.hpp"
#include "Timer.hpp"
#include "GameObjectPtrVector.hpp"
#include <stdint.h>

using std::vector;

const unsigned int MOVE_SPD = 5;

struct SDL_Surface;
union SDL_Event;

class CApp : public IEngine
{
    bool m_bRunning;
    //Tells the system if we are using the tileengine.
    bool m_bUseTileEngine;
public:

    CApp();

    //Engine Core!
    int Execute();
    bool Initialize();
    void Bind(CGameObject* pBindMe);

private:

    SDL_Surface* m_pSurfDisplay;
    //Some nice helper functions for graphics!
    SDL_Surface* LoadSprite(const char* pszFileName) const;
    bool DrawSurface(SDL_Surface* pSrc, SDL_Surface* pDst);
    bool DrawSurface(SDL_Surface* pSrc, int16_t nSrcX, int16_t nSrcY, SDL_Surface* pDst, int16_t nDstX, int16_t nDstY);
    bool DrawSurface(SDL_Surface* pSrc, SDL_Surface* pDst, int16_t nDstX, int16_t nDstY);
    void OnEvent( SDL_Event* pEvent);
    void OnLoop();
    void OnRender();
    void OnCleanup();

    //KMS:  Should this really be public data??
    //TAC:  No it really should all be gone through and put in private or protected.
    //      Just need to take the time to actually go through and fix it.

    //Input data.
    Pos2f m_inputVelocity;
    short unsigned int m_uMovementSpeed;
    //Timing and Event System Stuff alot of of it needs a cleanup, as most likely it is all not needed.
    CTimer m_timer;
    uint32_t m_uPrevTime;
    uint32_t m_uCurrTime;
    uint32_t m_uAccTime;
    int m_nGravRate;
    int m_nGravFrame;

    bool m_bJump;
    bool m_bAlreadyJump;
    int m_nJumpTime;
    int m_nJumpPower;

    //Used for the Sprite Pointer Vector for automated rendering and updating, etc.
    //You will pretty much always bind a new Sprite to this system. Just use BindSprite, passing it the pointer to the sprite object.
    CGameObjectPtrVector m_arObjectList;

    //The tile engine object.
    TileEngine m_TileEngine;
    //Turn on or off the tileEngine.
    void SetUseTileEngine(bool pA){m_bUseTileEngine = pA;};

    //CSound m_TestSound;

    //Screen Resolution
    const static unsigned int m_ciScreenResoultionX = 1920;
    const static unsigned int m_ciScreenResolutionY = 1080;
};

bool operator < (const CGameObject& left, const CGameObject& right);

#endif
