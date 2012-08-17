//
//  CApp_Sprite.cpp
//  SkyFarm
//
//  Created by Timothy Carlisle on 10/26/11.
//  Copyright 2011 EnvironTek Games, LLC. All rights reserved.
//

#include "CApp.h"


//update animation information
//This will house all of the animation systems for ensuring proper animation.
void Sprite::AnimationSystemUpdate()
{
    //Animation Updates here!
}
void Sprite::AnimationSystemInit(int startAnimation, int numberAnimation, int framesPerAnim)
{
    currentAnimation = startAnimation;
    numberOfAnimations = numberOfAnimations;
    //framesPerAnimation = framesPerAnim;
}

//Set the Tile size for animations
void Sprite::SetAnimTileSize(int h, int w)
{
    //tileSizeH = h;
    //tileSizeW = w;
}
//set the current frame.
void Sprite::SetCurrentFrame(int x)
{
    currentFrame = x;
}

void Sprite::SetFrames(int x)
{
    frames = x;
}

bool Sprite::Update()
{
    //Default Sprite Update
    MoveSprite(Sprite::spriteVelX, Sprite::spriteVelY);
    return true;
}


void Sprite::UpdateRenderSurf()
{

}

SDL_Rect Sprite::GetSpritePos()
{
    return rect;
}

void Sprite::SetSpritePosition(int x, int y, int w, int h)
{
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
}

void Sprite::SetSpritePosition(SDL_Rect nRect)
{
    rect.x = nRect.x;
    rect.y = nRect.y;
}

void Sprite::MoveSprite(int x,  int y)
{
    rect.x = rect.x + x;
    rect.y = rect.y + y;
}

void Sprite::NextAnimationFrame()
{
    currentFrame += 1;
    if (currentFrame > frames)
    {
        currentFrame = 1;
    }
    UpdateRenderSurf();
}

bool Sprite::DrawSprite(SDL_Surface *dst_Surf)
{
    if (SDL_BlitSurface(Render_Surf, NULL, dst_Surf, &rect) != 1)
    {
        return false;
    }
    else
    {
        return true;
    }

}

void Sprite::SetSpriteVel(int x, int y)
{
    spriteVelX = x;
    spriteVelY = y;
}

int Sprite::GetSpriteYVel()
{
    return spriteVelY;
}

int Sprite::GetSpriteXVel()
{
    return spriteVelX;
}

SDL_Rect Sprite::GetSpriteVel()
{
    SDL_Rect Temp;
    Temp.x = spriteVelX;
    Temp.y = spriteVelY;
    return Temp;
}

bool Sprite::CheckCollision(SDL_Rect otherRect)
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = rect.x;
    rightA = rect.x + rect.w;
    topA = rect.y;
    bottomA = rect.y + rect.h;

    //Calculate the sides of rect B
    leftB = otherRect.x;
    rightB = otherRect.x + otherRect.w;
    topB = otherRect.y;
    bottomB = otherRect.y + otherRect.h;
    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    OnCollision();
    return true;
}

bool Sprite::OnCollision()
{
    //Anything for when collision is thrown, typical action is played out by Check Collision, should really be changed to work inside here!
    return true;
}

unsigned short int Sprite::SideOfCollision(SDL_Rect otherRect)
{
        //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = rect.x;
    rightA = rect.x + rect.w;
    topA = rect.y;
    bottomA = rect.y + rect.h;

    //Calculate the sides of rect B
    leftB = otherRect.x;
    rightB = otherRect.x + otherRect.w;
    topB = otherRect.y;
    bottomB = otherRect.y + otherRect.h;
    //If any of the sides from A are inside of B
    if ((topA < bottomB) || (topB < bottomA))
    {
        return 1;
    }
    if ((rightA < leftB) || (rightB < leftA))
    {
        return 2;
    }
    //If none of the sides from A are inside B
    return 0;
}


void Sprite::SetLayer(int l)
{
    layer = l;
}
int Sprite::GetLayer()
{
    return layer;
}

Sprite::Sprite()
{
    usesRender = false;
    usesInput = false;
    usesGravity = false;
    usesCollision = false;

    spriteVelX = 0;
    spriteVelY = 0;
    frames = 0;
    tileSizeH = 0;
    tileSizeY = 0;
    layer = 0;

    rect.x = 0;
    rect.y = 0;
    rect.w = 0;
    rect.h = 0;

    Surf = NULL;
    Render_Surf = NULL;

    collisionRect.x = 0;
    collisionRect.y = 0;
    collisionRect.w = 0;
    collisionRect.h = 0;


}

Sprite::~Sprite()
{
    if (Surf != NULL)
    {
        SDL_FreeSurface(Surf);
    }
    if (Render_Surf != NULL)
    {
        SDL_FreeSurface(Render_Surf);
    }
}


