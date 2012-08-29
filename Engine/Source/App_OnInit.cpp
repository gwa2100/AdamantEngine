//
//  CApp_OnInit.cpp
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

#include "App.h"
#include <SDL/SDL.h>


bool CApp::OnInit() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }



// load support for the OGG and MOD sample/music formats
    int flags = MIX_INIT_OGG|MIX_INIT_MOD;
    int initted = Mix_Init(flags);
    if((initted & flags) != flags) {
        printf("Mix_Init: Failed to init required ogg and mod support!\n");
        printf("Mix_Init: %s\n", Mix_GetError());
        // handle error
    }


    if ((m_pSurfDisplay = SDL_SetVideoMode(m_ciScreenResoultionX, m_ciScreenResolutionY, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN)) == NULL)
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Adamant Engine by: Timothy Carlisle. Copyright All Rights Reserved 2011-2012", NULL);

    m_inputVelocity.x = 0;
    m_inputVelocity.y = 0;
    m_uMovementSpeed = MOVE_SPD;
    m_uPrevTime = 0;
    m_uCurrTime = 0;
    m_uAccTime = 0;
    m_nGravRate = 7;
    m_nGravFrame = 0;

    //Jump stuff
    m_bJump = false;
    m_bAlreadyJump = false;
    m_nJumpTime = 0;
    m_nJumpPower = 7;

    return true;
}
