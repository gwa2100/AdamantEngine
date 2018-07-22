#include "GameAppLayer.h"
#include "PositionDataTypes.h"

GameAppLayerInput::GameAppLayerInput()
{

}

GameAppLayerInput::~GameAppLayerInput()
{

}



GameAppLayerFileSystem::GameAppLayerFileSystem()
{

}

GameAppLayerFileSystem::~GameAppLayerFileSystem()
{

}



GameAppLayerTime::GameAppLayerTime()
{

}

GameAppLayerTime::~GameAppLayerTime()
{

}



GameAppLayerThreads::GameAppLayerThreads()
{

}

GameAppLayerThreads::~GameAppLayerThreads()
{

}



GameAppLayerSystem::GameAppLayerSystem()
{

}

GameAppLayerSystem::~GameAppLayerSystem()
{

}

//----------------------------------------------GAME ENGINE----------------------------------------------------------------

GameAppLayerEngine::GameAppLayerEngine()
{

}

GameAppLayerEngine::~GameAppLayerEngine()
{

}

bool GameAppLayerEngine::Start()
{
	return Loop();
}
bool GameAppLayerEngine::Stop()
{
	m_running = false;
	return true;
}
bool GameAppLayerEngine::Loop()
{
	while (m_running)
	{
		//If any subsystems return a false flag, return a false flag, effectively ending the engine loop.
		if (!Update())
			return false;
	}
	return true;
}

bool GameAppLayerEngine::Update()
{
	return true;
}

void GameAppLayerEngine::BlitScreen(SDL_Surface hSrcSurface, CRect* pSrcRect, SDL_Surface hDstSurface, CRect* pDstRect)
{
	SDL_Rect source = { 0 };
	SDL_Rect* pSourceRC = NULL;
	if (pSrcRect != NULL)
	{
		pSourceRC = &source;
		source.x = pSrcRect->left;
		source.y = pSrcRect->top;
		source.h = pSrcRect->Height();
		source.w = pSrcRect->Width();
	}

	SDL_Rect dest = { 0 };
	SDL_Rect* pDestRC = NULL;
	if (pDstRect != NULL)
	{
		pDestRC = &dest;
		dest.x = pDstRect->left;
		dest.y = pDstRect->top;
		dest.h = pDstRect->Height();
		dest.w = pDstRect->Width();
	}

	//SDL_Surface* pSource = (SDL_Surface*)hSrcSurface;
	SDL_BlitSurface(&hSrcSurface, pSourceRC, &hDstSurface, pDestRC);
}







GameAppLayer::GameAppLayer()
{

}

GameAppLayer::~GameAppLayer()
{

}
