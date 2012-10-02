//
//  CSound.cpp
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

#ifndef CSound_h
#define CSound_h

struct _Mix_Music;
typedef struct _Mix_Music Mix_Music;


#include "SDL_stdinc.h"

#include <vector>
#include <algorithm>

using std::vector;

//Loads, Holds, and plays Music files.
class Music
{
protected:
    Mix_Music* m_pSample;
public:
    //Used for indexing purposes.
    int m_nIndex;
    const char* m_pszIndexName;

    Music();
    virtual ~Music();

    bool Load(const char* pszFilename);
    void Play();
    void Stop();
    void Pause();
    void Resume();
};

struct Mix_Chunk;

//Loads, Holds, and plays SoundFX.
class SoundFX
{
protected:
    Uint16 m_uChannel;
    Mix_Chunk* m_pSample;
public:
    //Used for indexing purposes.
    int m_nIndex;
    const char* m_pszIndexName;
    SoundFX();
    virtual ~SoundFX();

    bool Load(const char* pszFilename);
    void Play();
    void PlayTimed(int nLength);

    void Stop();
};

struct SortObject
{
    //If we change to string this needs recode.
    bool operator()( Music* pLeft, Music* pRight)
    {
        return strcmp(pLeft->m_pszIndexName , pRight->m_pszIndexName) < 0;
    }
    bool operator()(Music* pMusic, const char* IndexName)
    {
        return strcmp(pMusic->m_pszIndexName, IndexName) < 0;
    }

    bool operator()( SoundFX* pLeft, SoundFX* pRight)
    {
        return strcmp(pLeft->m_pszIndexName , pRight->m_pszIndexName) < 0;
    }
    bool operator()(SoundFX* pSoundFX, const char* IndexName)
    {
        return strcmp(pSoundFX->m_pszIndexName, IndexName) < 0;
    }
};

class CMusicPtrVector : public vector< Music* >
{
    public:
    CMusicPtrVector() {}
    ~CMusicPtrVector()
    {
        ResetContent();
    }

    void ResetContent()
    {
        if ( size() == 0 ) return;

        Music** ppObjects = data();
        for(size_t n = 0; n < size(); n++)
        {
            delete ppObjects[n];
        }

        clear();

        CMusicPtrVector().swap( *this );
    }
    void SortByName()
    {
        std::sort(begin(),end(),SortObject());
    }

    Music* FindByName(const char* pszIndexName)
    {
        SortObject SortObj;
        CMusicPtrVector::iterator test = std::lower_bound( begin(), end(), pszIndexName, SortObj );
        bool bFound = (test != end() && !(SortObj(*test,pszIndexName)));
        return bFound ? *test : NULL;
    }

};


class CSoundFXPtrVector : public vector< SoundFX* >
{
    public:
    CSoundFXPtrVector() {}
    ~CSoundFXPtrVector()
    {
        ResetContent();
    }

    void ResetContent()
    {
        if ( size() == 0 ) return;

        SoundFX** ppObjects = data();
        for(size_t n = 0; n < size(); n++)
        {
            delete ppObjects[n];
        }

        clear();

        CSoundFXPtrVector().swap( *this );
    }

    void SortByName()
    {
        std::sort(begin(),end(),SortObject());
    }

    SoundFX* FindByName(const char* pszIndexName)
    {
        SortObject SortObj;
        CSoundFXPtrVector::iterator test = std::lower_bound( begin(), end(), pszIndexName, SortObj );
        bool bFound = (test != end() && !(SortObj(*test,pszIndexName)));
        return bFound ? *test : NULL;
    }

};


//Used for total management of all SoundFX and Music loaded to it.
class AudioManager
{
protected:
    int m_nIndexedFiles;
    CMusicPtrVector m_arMusic;           //Check notation for vector.
    CSoundFXPtrVector m_arSoundFX;
public:
    AudioManager();
    ~AudioManager();
    //Music Functions
    bool LoadMusic(const char* pszFilename, const char* pszIndexName);
    bool PlayMusic(const char* pszIndexName);
    bool StopMusic(const char* pszIndexName);
    bool PauseMusic(const char* pszIndexName);
    bool ResumeMusic(const char* pszIndexName);
    int  GetIndexMusic(const char* pszIndexName);
    const char* GetIndexNameMusic(int nIndex);


    //SFX Functions
    bool LoadSFX(const char* pszFilename, const char* pszIndexName);
    bool PlaySFX(const char* pszIndexName);
    bool PlaySFXTimed(const char* pszIndexName, int nTimeLength);
    bool StopSFX(const char* pszIndexName);
    int  GetIndexSFX(const char* pszIndexName);
    const char* GetIndexNameSFX(int nIndex);
};

#endif


