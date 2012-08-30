//
//  CSound.cpp
//  AdamantEngine
//
//  Created by Timothy Carlisle on 11/05/11.
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
#include "Sound.h"
#include <SDL/SDL_mixer.h>

CSound::CSound()
 : m_pSample(NULL)
{
}

CSound::~CSound()
{
    UnLoad();
}

bool CSound::Load(const char* pszFilename)
{
	// load the MP3 file "music.mp3" to play as music
	m_pSample = Mix_LoadMUS(pszFilename);
	if(!m_pSample)
	{
        printf("Mix_LoadMUS(\"music.ogg\"): %s\n", Mix_GetError());
        return false;// this might be a critical error...
	}

	return true;
}

void CSound::Play()
{
	//Mix_PlayMusic(sample, -1);
    printf("Mix_LoadMUS(\"music.ogg\"): %s\n", Mix_GetError());
}

void CSound::UnLoad()
{
    if ( m_pSample == NULL ) return;
	Mix_FreeMusic(m_pSample);
	m_pSample = NULL;
}
