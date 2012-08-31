#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include "Sprite.h"

class CAnimatedSprite : public CSprite
{
    public:
        CAnimatedSprite();
        virtual ~CAnimatedSprite();

        virtual void StartAnimation();

        virtual bool Update(float fDeltaTime = 0.0f);
        virtual bool Render(SDL_Surface* pDestSurf);

        bool CreateFromFile( const string& sFilename, unsigned int nFrames, Uint32 uDelay );

    protected:
    private:


    Uint32 m_uAnimateMS;
    unsigned int m_nCurrentFrame;
    unsigned int m_nMaxFrames;
    Uint32 m_uStartTick;
};

#endif // ANIMATEDSPRITE_H
