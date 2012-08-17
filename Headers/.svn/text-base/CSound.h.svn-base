#ifndef SkyFarm_CSound_h
#define SkyFarm_CSound_h

#include "CApp.h"
#include <SDL_Mixer.h>


class CSound{
private:
	Mix_Music* sample;
public:
    CSound();
    ~CSound();

	bool loadSound(const char *filename);
	void play();
	void freeMusic();
};

#endif


