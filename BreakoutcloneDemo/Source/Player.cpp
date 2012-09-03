#include "Headers/Player.h"

CPlayer::CPlayer()
{
    //ctor
}

CPlayer::~CPlayer()
{
    //dtor
}

bool CPlayer::Update(float deltaTime /*= 0.0f*/)
{
    Move( Pos2i(velocity.x, 0) );
    return true;
}
