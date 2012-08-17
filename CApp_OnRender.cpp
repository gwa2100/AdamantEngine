//
//  CApp_OnRender.cpp
//  SkyFarm
//
//  Created by Timothy Carlisle on 10/26/11.
//  Copyright 2011 EnvironTek Games, LLC. All rights reserved.
//

#include "CApp.h"

void CApp::OnRender(){
    DrawSurface(Surf_Background, Surf_Display, 1, 1);

    //SpriteList SpriteDrawing!

    for (unsigned int x = 0; x < SpriteList.size(); x++) {
        if (SpriteList[x]->usesRender)
        {
            SpriteList[x]->DrawSprite(Surf_Display);
        }
    }
   /* for (int x = 0; x < 10; x++)
    {


            Arr_Bricks[x].DrawSprite(Surf_Display);

    }
*/

    SDL_Flip(Surf_Display);


}
