#pragma once
#include <SDL2/SDL_video.h>
#include "PositionDataTypes.h"


class GameAppLayerInput
{
	GameAppLayerInput();
	~GameAppLayerInput();
};

class GameAppLayerFileSystem
{
	GameAppLayerFileSystem();
	~GameAppLayerFileSystem();
};

class GameAppLayerTime
{
	GameAppLayerTime();
	~GameAppLayerTime();
};

class GameAppLayerThreads
{
	GameAppLayerThreads();
	~GameAppLayerThreads();
};

class GameAppLayerSystem
{
	GameAppLayerSystem();
	~GameAppLayerSystem();
};

class GameAppLayerEngine
{
public:
	GameAppLayerEngine();
	~GameAppLayerEngine();
	bool Start();
	bool Stop();
protected:
	bool Loop();
	bool Update();
	bool m_running;
	//This is used to put a surface onto the screen.
	void BlitScreen(SDL_Surface hSrcSurface, CRect* pSrcRect, SDL_Surface hDstSurface, CRect* pDstRect);

};

class GameAppLayer
{
public:
	GameAppLayer();
	~GameAppLayer();
};

