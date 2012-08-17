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
    //This is broken gotta figure it out!
	//Mix_PlayMusic(sample, -1);
    printf("Mix_LoadMUS(\"music.ogg\"): %s\n", Mix_GetError());
}

void CSound::freeMusic()
{
	Mix_FreeMusic(sample);
}
