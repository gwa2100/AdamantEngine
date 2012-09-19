#ifndef __ANIMATEDSPRITE_HPP__
#define __ANIMATEDSPRITE_HPP__

#include "Sprite.hpp"
#include <stdint.h>

class CAnimatedSprite : public CSprite
{
    friend class CApp;
    public:
        CAnimatedSprite();
        virtual ~CAnimatedSprite();

		bool CreateFromFile( const string& sFilename, unsigned int nFrames, uint32_t uDelay );

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

#endif // ANIMATEDSPRITE_H
