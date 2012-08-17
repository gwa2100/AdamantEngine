#include "CApp.h"

bool Ball::OnCollision(int side)
{
    //Act on collision
    if (side == 1)
    {
        //flip y
        Ball::SetSpriteVel(GetSpriteXVel(),GetSpriteYVel() * -1);
    }
    if (side == 2)
    {
        //flip x
        Ball::SetSpriteVel(GetSpriteXVel() * - 1,GetSpriteYVel());
    }
    if (side == 3)
    {
        //flip x and y
        Ball::SetSpriteVel(GetSpriteXVel() * - 1,GetSpriteYVel() * - 1);
    }

    return true;
}

bool Ball::Update()
{
    Ball::MoveSprite(GetSpriteXVel(),GetSpriteYVel());
    return true;
}

Ball::Ball()
{
    Ball::direction = 0;
}

Ball::~Ball()
{
    //dtor
}
