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

#ifndef CSound_h
#define CSound_h

struct _Mix_Music;
typedef struct _Mix_Music Mix_Music;
#include <vector>
using namespace std::vector;

class CSound
{
protected:
	Mix_Music* m_pSample;
public:
    CSound();
    virtual ~CSound();

	virtual bool Load(const char* pszFilename);
	virtual void Play();
};

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

//Used for total management of all SoundFX and Music loaded to it.
class AudioManager
{
protected:
    int m_nIndexedFiles;
    vector<Music*> m_vpMusic;           //Check notation for vector.
    vector<SoundFX*> m_vpSoundFX;
public:
    AudioManager();
    ~AudioManager();
    //Music Functions
    bool LoadMusic(const char* pszFilename, const char* pszIndexName);
    bool PlayMusic(int nIndex);
    bool PlayMusic(const char* pszIndexName);
    bool StopMusic(int nIndex);
    bool StopMusic(const char* pszIndexName);
    bool PauseMusic(int nIndex);
    bool PauseMusic(const char* pszIndexName);
    bool ResumeMusic(int nIndex);
    bool ResumeMusic(const char* pszIndexName);
    int  GetIndexMusic(const char* pszIndexName);
    const char* GetIndexNameMusic(int nIndex);


    //SFX Functions
    bool LoadSFX(const char* pszFilename, const char* pszIndexName);
    bool PlaySFX(int nIndex);
    bool PlaySFX(const char* pszIndexName);
    bool PlaySFXTimed(int nIndex, int nTimeLength);
    bool PlaySFXTimed(const char* pszIndexName, int nTimeLength);
    bool StopSFX(int nIndex);
    bool StopSFX(const char* pszIndexName);
    int  GetIndexSFX(const char* pszIndexName);
    const char* GetIndexNameSFX(int nIndex);




};

#endif


