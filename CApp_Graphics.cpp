//
//  graphics.cpp
//  SkyFarm
//
//  Created by Timothy Carlisle on 10/27/11.
//  Copyright 2011 EnvironTek Games, LLC. All rights reserved.
//

#include "CApp.h"

SDL_Surface* CApp::LoadSprite(const char *fileName)
{
    SDL_Surface* Surf_Temp = NULL;
    SDL_Surface* Surf_Return = NULL;

    if ((Surf_Temp = SDL_LoadBMP(fileName)) == NULL) {
        return NULL;
    }

    Surf_Return = SDL_DisplayFormat(Surf_Temp);

    SDL_FreeSurface(Surf_Temp);


    //Uint32 colorKey = SDL_MapRGB( Surf_Return->format,0, 0xFF, 0xFF);
    //SDL_SetColorKey(Surf_Return, SDL_RLEACCEL | SDL_SRCCOLORKEY, colorKey);

    SDL_SetColorKey(Surf_Return, SDL_SRCCOLORKEY, SDL_MapRGB(Surf_Return->format, 153,217,234));


    return Surf_Return;

}

bool CApp::DrawSurface(SDL_Surface *src, SDL_Surface *dst)
{
    if (SDL_BlitSurface(src, NULL, dst, NULL) != 1)
    {
        return false;
    }
    else
    {
        return true;
    }

}


bool CApp::DrawSurface(SDL_Surface *src, SDL_Surface *dst, int dst_x, int dst_y)
{
    SDL_Rect dst_rect;

    dst_rect.x = dst_x;
    dst_rect.y = dst_y;

    if (SDL_BlitSurface(src, NULL, dst, &dst_rect) != 1)
    {
        return false;
    }
    else
    {
        return true;
    }

}


bool CApp::DrawSurface(SDL_Surface *src, int src_x, int src_y, SDL_Surface *dst, int dst_x, int dst_y)
{
    SDL_Rect src_rect;
    SDL_Rect dst_rect;

    src_rect.x = src_x;
    src_rect.y = src_y;
    dst_rect.x = dst_x;
    dst_rect.y = dst_y;

    if (SDL_BlitSurface(src, &src_rect, dst, &dst_rect) != 1)
    {
        return false;
    }
    else
    {
        return true;
    }

}

