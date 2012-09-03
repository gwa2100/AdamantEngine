#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"


class CPlayer : public CSprite
{
    public:
        CPlayer();
        virtual ~CPlayer();

        virtual bool Update(float deltaTime = 0.0f);
        virtual bool OnCollision( ECollision eCollision) { return true; }

    protected:
    private:
};

#endif // PLAYER_H
