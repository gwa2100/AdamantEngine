//
//  Sound.cpp
//  AdamantEngine
//
//  Created by Timothy Carlisle on 08/30/12.
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



//Music Implementation
Music::Music()
 : m_pSample(NULL)
{
}

Music::~Music()
{
    if ( m_pSample != NULL )
    {
        Mix_FreeMusic(m_pSample);
        m_pSample = NULL;
    }
    return;
}

bool Music::Load(const char* pszFilename)
{
	// load the MP3 file "music.mp3" to play as music
	m_pSample = Mix_LoadMUS(pszFilename);
	if(!m_pSample)
	{
        printf("Mix_LoadMUS fail: in Sound : %s\n", Mix_GetError());
        return false;// this might be a critical error...
	}

	return true;
}

void Music::Play()
{
	if (!Mix_PlayMusic(m_pSample, -1))
    {
        printf("Mix_PlayMusic fail: in Sound : %s\n", Mix_GetError());
    }
}

void Music::Stop()
{
    if (!Mix_HaltMusic())
    {
        printf("Mix_HaltMusic fail: in Sound : %s\n", Mix_GetError());
    }
}

//This will pause the music, but if the music is already paused it will resume it.
void Music::Pause()
{
    if (Mix_PausedMusic())
    {
        //ALREADY PAUSED, UNPAUSE MUSIC
        Mix_ResumeMusic();
    }
    else
    {
        Mix_PauseMusic();
    }
}

//Can be used to even resume halted music.
void Music::Resume()
{
    Mix_ResumeMusic();
}


//SoundFX Implementation
SoundFX::SoundFX()
 : m_pSample(NULL)
{
}

SoundFX::~SoundFX()
{
    if ( m_pSample != NULL )
    {
        Mix_FreeChunk(m_pSample);
        m_pSample = NULL;
    }
    return;
}

bool SoundFX::Load(const char* pszFilename)
{
	// load the MP3 file "music.mp3" to play as music
	m_pSample = Mix_LoadWAV(pszFilename);
	if(!m_pSample)
	{
        printf("Mix_LoadWAV fail: in Sound : %s\n", Mix_GetError());
        return false;// this might be a critical error...
	}

	return true;
}

//Plays the sound once.  It will play on first available channel and return that by m_uChannel.
void SoundFX::Play()
{
    m_uChannel = Mix_PlayChannel(-1,m_pSample, 0);
	if (m_uChannel < 0)
    {
        printf("Mix_PlayChannel fail: in Sound : %s\n", Mix_GetError());
        m_uChannel = 0;
    }
}

//Plays the sound in loop for so many miliseconds as passed by parameter nLength.  It will play on first available channel and return that by m_uChannel.
void SoundFX::PlayTimed(int nLength)
{
    m_uChannel = Mix_PlayChannelTimed(-1,m_pSample, -1, nLength);
	if (m_uChannel < 0)
    {
        printf("Mix_PlayChannelTimed fail: in Sound : %s\n", Mix_GetError());
        m_uChannel = 0;
    }
}

void SoundFX::Stop()
{
    if (!Mix_HaltChannel(m_uChannel))
    {
        printf("Mix_HaltChannel fail: in Sound : %s\n", Mix_GetError());
    }
}



//Audio Manager
AudioManager::AudioManager()
{

}
AudioManager::~AudioManager()
{

}

//Music Functions
bool AudioManager::LoadMusic(const char* pszFilename, const char* pszIndexName)
{
    return false;
}
bool AudioManager::PlayMusic(int nIndex)
{
    return false;
}
bool AudioManager::PlayMusic(const char* pszIndexName)
{
    return false;
}
bool AudioManager::StopMusic(int nIndex)
{
    return false;
}
bool AudioManager::StopMusic(const char* pszIndexName)
{
    return false;
}
bool AudioManager::PauseMusic(int nIndex)
{
    return false;
}
bool AudioManager::PauseMusic(const char* pszIndexName)
{
    return false;
}
bool AudioManager::ResumeMusic(int nIndex)
{
    return false;
}
bool AudioManager::ResumeMusic(const char* pszIndexName)
{
    return false;
}
int  AudioManager::GetIndexMusic(const char* pszIndexName)
{
    return -1;
}
const char* AudioManager::GetIndexNameMusic(int nIndex)
{
    return NULL;
}


//SFX Functions
bool AudioManager::LoadSFX(const char* pszFilename, const char* pszIndexName)
{
    return false;
}
bool AudioManager::PlaySFX(int nIndex)
{
    return false;
}
bool AudioManager::PlaySFX(const char* pszIndexName)
{
    return false;

}
bool AudioManager::PlaySFXTimed(int nIndex, int nTimeLength)
{
    return false;

}
bool AudioManager::PlaySFXTimed(const char* pszIndexName, int nTimeLength)
{
    return false;

}
bool AudioManager::StopSFX(int nIndex)
{
    return false;

}
bool AudioManager::StopSFX(const char* pszIndexName)
{
    return false;

}
int  AudioManager::GetIndexSFX(const char* pszIndexName)
{
    return -1;
}
const char* AudioManager::GetIndexNameSFX(int nIndex)
{
    return NULL;
}
