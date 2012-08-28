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

#include "CApp.h"




CSound::CSound()
{
    sample = NULL;
}
CSound::~CSound()
{
    Mix_FreeMusic(sample);
    sample = NULL;
}


bool CSound::loadSound(const char *filename)
{
	// load the MP3 file "music.mp3" to play as music
	sample = Mix_LoadMUS(filename);
	if(!sample)
	{
    printf("Mix_LoadMUS(\"music.ogg\"): %s\n", Mix_GetError());
	return false;
    // this might be a critical error...
	}
	return true;
}

void CSound::play()
{
	//Mix_PlayMusic(sample, -1);
    printf("Mix_LoadMUS(\"music.ogg\"): %s\n", Mix_GetError());
}

void CSound::freeMusic()
{
	Mix_FreeMusic(sample);
}
