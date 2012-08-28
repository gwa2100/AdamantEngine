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
