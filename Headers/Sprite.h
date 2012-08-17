//
//  Sprite.h
//  SkyFarm
//
//  Created by Timothy Carlisle on 11/6/11.
//  Copyright 2011 EnvironTek Games, LLC. All rights reserved.
//

#ifndef SkyFarm_Sprite_h
#define SkyFarm_Sprite_h

#include <CApp.h>
#include "CSound.h"
#include <SDL.h>
#include <vector>
#include <algorithm>

/*
Notes:
<Use this format>
Your Name
Date/Time
Notes
<IE>
Tim Carlisle
11:11 11/11/11
This is an Example.
<END>

Tim Carlisle
5:47PM 11/28/2011
Going to be adding support for the sprite sheet loading.
*/

//Definetly the most mixed up class! Needs a lot of cleanup!
class Sprite {
public:
    //Positional x,y   Surf Info h,w
    SDL_Rect rect;

    //Used to determine which will be on top upon drawing.
    int layer;

    //Movement Velocity
    int spriteVelX;
    int spriteVelY;

    //Number of frames for animation!
    int frames;

    //current frame
    int currentFrame;

    //Size of Animatin tile.
    int tileSizeH;
    int tileSizeY;

    //Not used yet, not sure where I am going with this one.
    //Original idea was to call this to move to the next frame of animation...Not sure yet.
    //Maybe call it to check if it is ready for animation change?
    //Only time will tell!
    void UpdateRenderSurf();

public:
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Variables<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

    //Our surface pointers for holding the surface!
    //The Surf is designed to hold the entire graphic,
    //while Render_Surf is meant to hold the portion to be
    //Rendered.  Would probably be great for using for animation.
    //But I need to figure out how I am going to go about the animation
    //system.  For now the system just Render_Surf = Surf in the init
    //portion of the engine.  So no portion control.
    //Work in progress.
    SDL_Surface* Surf;
    SDL_Surface* Render_Surf;

    //Collision stuff.  Just so we know where it was before it collided to move it back.
    //This idea sucks, need to find another way.
    int oldX;
    int oldY;

    //Will be set when binded.
    unsigned int bindID;
    //Needs to be rendered
    bool usesRender;

    //Needs userinput
    bool usesInput;

    //Needs Gravity
    bool usesGravity;

    //Collidable
    bool usesCollision;

    //Does it need Animation?
    bool usesAnimation;

    //Tells the OnLoop System if this Sprite will be requiring updates.
    bool needUpdate;

    //If it is a GUI, it gets updated position by Camera.
    bool isGUI;

    SDL_Rect animationFrame;
    int currentAnimation;
    int numberOfAnimations;
    int framesPerAnimation;


    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Functions<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

    //To go to next Animation frame and get it set up in Render.
    void NextAnimationFrame();

    //Check collision between this sprite and a target rect.
    bool CheckCollision(SDL_Rect otherRect);

    //Check collision between this sprite and target and return side hit 1 TOP 2 RIGHT 3 BOTTOM 4 LEFT 0 NONE
    unsigned short int SideOfCollision(SDL_Rect otherRect);

    unsigned short int sideOfImpact; //1 TOP 2 RIGHT 3 BOTTOM 4 LEFT 0 NONE
    //Update Function
    virtual bool Update();

    //On Collision Function
    virtual bool OnCollision();

    //Layer Stuff
    void SetLayer(int l);
    int GetLayer();

    //The rect that holds the collision box.
    SDL_Rect collisionRect;

    //Our lovely function set.
    //Returns the sprite position as a Rect
    SDL_Rect GetSpritePos();

    //Set Sprite Position using ints, kind of deprecated as we have FillRect(int, int, int ,int) now.
    //You could just call SetSpritePosition(FillRect(int,int,int,int) and it would work.
    void SetSpritePosition(int x, int y, int w, int h);
    void SetSpritePosition(SDL_Rect nRect);

    //Moves the sprite so many units.
    void MoveSprite(int x, int y);

    //Draw the sprite!
    bool DrawSprite(SDL_Surface* dst_Surf);

    //Set sprites velocity...Not sure...
    void SetSpriteVel(int x, int y);

    //returns sprite velocity in SDL_Rect format.
    SDL_Rect GetSpriteVel();

    int GetSpriteYVel();
    int GetSpriteXVel();

    //Set the Tile size for animations
    void SetAnimTileSize(int h, int w);
    //set the current frame.
    void SetCurrentFrame(int x);
    //set number of frames
    void SetFrames(int x);

    //update animation information
    //This will house all of the animation systems for ensuring proper animation.
    void AnimationSystemUpdate();
    void AnimationSystemInit(int startAnimation, int numberAnimation, int framesPerAnim);



    Sprite();
    virtual ~Sprite();



};


#endif
