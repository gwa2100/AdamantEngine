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
#include "Sprite.h"
#include "Headers/Ball.h"
#include "Headers/Player.h"

int InitPlayer(CApp& app, CSprite* pl)
{
    pl->EnableCollision(true);
    pl->SetBoundingBox(CDefault_Rect(10,10,20,40));
    pl->EnableEvent( true );
    pl->EnableRender(true);
    pl->EnableUpdate( true );
    pl->SetFileName( "C:\\Users\\kevin\\Documents\\GitHub\\AdamantEngine\\bin\\Debug\\file.bmp" );
    pl->Move( Pos2i( 0, 550) );
    app.BindSprite(pl);
    return 0;
}


int main(int argc, char* argv[])
{
    //declare Sprite
    CPlayer* player = new CPlayer;
    CApp theApp;
    InitPlayer(theApp, player);
    Ball* pBall = new Ball;
    pBall->SetFileName("C:\\Users\\kevin\\Documents\\GitHub\\AdamantEngine\\bin\\Debug\\ball.bmp");
    pBall->EnableRender(true);
    pBall->EnableCollision(true);
    pBall->EnableUpdate(true);
    pBall->Move( Pos2i(0,0));
    pBall->SetVelocity( Pos2i( 0,1 ) );
    theApp.BindSprite( pBall );

    return theApp.OnExecute();
}
