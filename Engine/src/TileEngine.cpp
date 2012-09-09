#include "TileEngine.h"
#include <iostream>
#include <fstream>
using namespace std;
void TileEngine::LoadMap(string fileName)
{
    ifstream inFile(fileName.c_str());

    inFile >> tileMap.mapName >> tileMap.mapWidth >> tileMap.mapHeight >> tileMap.tileWidth
        >> tileMap.tileHeight;

    int tilesX = tileMap.mapWidth / tileMap.tileWidth;
    int tilesY = tileMap.mapHeight / tileMap.tileHeight;

    for (int x = 0; x < tilesX; x++)
    {
        for (int y = 0; y < tilesY; y++)
        {
            inFile >> tileMap.tiles[x][y];
        }
    }

    inFile >> tileMap.numberOfTileTypes;

    for (int x = 0; x < tileMap.numberOfTileTypes; x++)
    {
        inFile >> tileMap.tileTypes[x].passable >> tileMap.tileTypes[x].tileFileName;
    }
    //DONE LOADING NOW WE NEED TO LOAD THE SPRITE FILES
    for (int x = 0; x < tileMap.numberOfTileTypes; x++)
    {
        SDL_Surface* tempSurf = NULL;
        tempSurf = SDL_LoadBMP(tileMap.tileTypes[x].tileFileName.c_str());

        TileSprites.push_back(tempSurf);
        SDL_FreeSurface(tempSurf);
    }
}
void TileEngine::GenerateMap()
{
    int tilesX = tileMap.mapWidth / tileMap.tileWidth;
    int tilesY = tileMap.mapHeight / tileMap.tileHeight;

    for (int x = 0; x < tilesX; x++)
    {
        for (int y = 0; y < tilesY; y++)
        {
            int tileTypeNumber = tileMap.tiles[x][y];
            string tileFileName = tileMap.tileTypes[tileTypeNumber].tileFileName.c_str();
            TilePainterSprite.SetFileName(tileFileName);
            TilePainterSprite.OnInit();
            Pos2i tilePos;
            tilePos.x = tileMap.mapWidth * x;
            tilePos.y = tileMap.mapHeight * y;
            TilePainterSprite.Move(tilePos);

            //Set up the map surf
            tileScreen=SDL_CreateRGBSurface(SDL_SWSURFACE,tileMap.mapWidth,tileMap.mapHeight,32,0,0,0,0);

            TilePainterSprite.Render(tileScreen);

        }
    }
}

//Renders to target surface using set viewport portion.
bool TileEngine::RenderCurrentViewPort(SDL_Surface* pDestSurf)
{
    SDL_Rect viewRect = CDefault_Rect(currentViewPortCoords.x, currentViewPortCoords.y, viewPortSize.x, viewPortSize.y);
    //SDL_Rect rect = CDefault_Rect(pos.x, pos.y, dim.x, dim.y);

    if (SDL_BlitSurface(viewPort, &viewRect, pDestSurf, NULL) != 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

