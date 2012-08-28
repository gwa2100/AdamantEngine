//
//  main.cpp
//  AdamantEngine::BreakoutcloneDemo
//
//  Created by Timothy Carlisle on 8/28/12.
/*
   Copyright 2011-2012 Timothy Carlisle

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include "AdamantEngine.h"

int InitPlayer(CApp* app, Sprite* pl)
{

    pl->usesCollision = true;
    pl->collisionRect = app->RectFiller(10,10,20,40);
    pl->Render_Surf = app->LoadSprite("file.bmp");
    pl->usesInput = true;
    pl->usesRender = true;
    app->BindSprite(pl);
    return 0;
}


int main(int argc, char* argv[])
{
    //declare Sprite
    Sprite player;
    CApp theApp;
    InitPlayer(&theApp, &player);
    return theApp.OnExecute();
}
