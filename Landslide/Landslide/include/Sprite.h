class Sprite
{
public:

protected:

};

/*
#include <stdint.h>
#include "GameObject.h"
#include <string>
using std::string;

class Sprite : public GameObject
{
	friend class CApp;
	friend class TileEngine;

public:
	Sprite();
	~Sprite();

	//Create from a bmp file.
	bool CreateFromFile(const string& sFilename);

protected:
	//Draw the sprite!
	virtual void Render(HSURFACE hDestSurf);


	HSURFACE m_hSurf;
};

class AnimatedSprite : public Sprite
{
	friend class CApp;
public:
	AnimatedSprite();
	virtual ~AnimatedSprite();

	bool CreateFromFile(const string& sFilename, unsigned int nFrames, uint32_t uDelay);

protected:

	virtual void StartAnimation();
	virtual void StopAnimation();
	virtual void Update(float fDeltaTime = 0.0f);
	virtual void Render(HSURFACE hDestSurf);

private:


	uint32_t m_uAnimateMS;
	unsigned int m_nCurrentFrame;
	unsigned int m_nMaxFrames;
	uint32_t m_uStartTick;
	bool m_bAnitmating;
};
*/