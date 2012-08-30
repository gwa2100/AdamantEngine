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

class CSound
{
	Mix_Music* m_pSample;
public:
    CSound();
    ~CSound();

	bool Load(const char* pszFilename);
	void Play();
	void UnLoad();
};

#endif


