#include "CApp.h"

bool Bricks::OnCollision()
{
    Bricks::Impact();
    return true;
}

bool Bricks::Impact()
{
    //Destroy on impact!
    //We will just make it uncollidable.
    Bricks::usesCollision = false;
    Bricks::usesRender = false;
    return true;
}

bool Bricks::Update()
{
    //No required update at this time.
    return true;
}

Bricks::Bricks()
{
    //ctor
    Surf = NULL;
}

Bricks::~Bricks()
{
    //dtor
}
