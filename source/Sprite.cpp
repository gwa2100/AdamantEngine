
/*
#include "Sprite.h"
#include <SDL/SDL_video.h>

void Sprite::Render(HSURFACE hDestSurf)
{
	Pos3f pos = GetPosition();
	Pos2f dim = GetDimensions();
	CRect dst(pos, dim);

	AmtBlit(m_hSurf, NULL, hDestSurf, &dst);
}

Sprite::CSprite()
	: m_hSurf(NULL)
{

}

Sprite::~CSprite()
{
	if (m_hSurf != NULL)
	{
		SDL_FreeSurface((SDL_Surface*)m_hSurf);
	}
}

bool Sprite::CreateFromFile(const string& sFilename)
{
	SDL_Surface* pTemp = SDL_LoadBMP(sFilename.c_str());
	if (pTemp == NULL) return false;

	SDL_Surface* pSurface = SDL_DisplayFormat(pTemp);

	dimensions.x = pSurface->w;
	dimensions.y = pSurface->h;

	bool bValid = pSurface != NULL;

	SDL_FreeSurface(pTemp);

	if (bValid)
	{
		m_hSurf = pSurface;
	}

	return bValid;

}


#include "../include/adamantengine.hpp"

CAnimatedSprite::CAnimatedSprite()
	: m_nCurrentFrame(0)
	, m_bAnitmating(false)
{
	//ctor
}

CAnimatedSprite::~CAnimatedSprite()
{
	//dtor
}

void CAnimatedSprite::Update(float fDeltaTime *//*= 0.0f*//*)
{
	CSprite::Update(fDeltaTime);
	if (!m_bAnitmating) return;

	uint32_t uCurrentMs = m_uCurrentTick - m_uStartTick;

	if (uCurrentMs > m_uAnimateMS)
	{
		uint32_t nFrameSkip = uCurrentMs / m_uAnimateMS;
		m_uStartTick = m_uCurrentTick;
		m_nCurrentFrame = (m_nCurrentFrame + nFrameSkip) % m_nMaxFrames;
	}
}

void CAnimatedSprite::Render(HSURFACE hDstSurf)
{
	Pos3f pos = GetPosition();
	Pos2f dim = GetDimensions();

	CRect rect(pos, dim);

	CRect src;
	src.left = dimensions.x * m_nCurrentFrame;
	src.right = src.left + dimensions.x;
	src.bottom = dimensions.y;

	AmtBlit(m_hSurf, &src, hDstSurf, &rect);
}

void CAnimatedSprite::StartAnimation()
{
	m_uStartTick = m_uCurrentTick;
	m_bAnitmating = true;
}

void CAnimatedSprite::StopAnimation()
{
	m_bAnitmating = false;
}

bool CAnimatedSprite::CreateFromFile(const string& sFilename, unsigned int nFrames, uint32_t uDelayInMS)
{
	bool bValid = CSprite::CreateFromFile(sFilename);
	if (!bValid) return bValid;

	dimensions.x = dimensions.x / nFrames;

	m_nMaxFrames = nFrames;
	m_nCurrentFrame = 0;
	m_uAnimateMS = uDelayInMS;

	return bValid;
}
*/