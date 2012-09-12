//
//  TileEngine.cpp
//  AdamantEngine
//
//  Created by Timothy Carlisle on 09/12/12.
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
#include "TileEngine.h"
#include <iostream>
#include <fstream>
using namespace std;

void TileEngine::LoadMap(string fileName)
{
    //Load the parameter file name.
    ifstream inFile(fileName.c_str());

    //Stream out the data into the mapfile.
    inFile >> tileMap.mapName >> tileMap.mapWidth >> tileMap.mapHeight >> tileMap.tileWidth
        >> tileMap.tileHeight;

    //We have to get the number of tiles in the map file and run through to set up the tiles array.
    int tilesX = tileMap.mapWidth / tileMap.tileWidth;
    int tilesY = tileMap.mapHeight / tileMap.tileHeight;
    //Set up tiles array.
    for (int x = 0; x < tilesX; x++)
    {
        for (int y = 0; y < tilesY; y++)
        {
            inFile >> tileMap.tiles[x][y];
        }
    }
    //Stream in the number of tile types.
    inFile >> tileMap.numberOfTileTypes;

    //Using the number of tile types, stream in there data into the tiletypes array.
    for (int x = 0; x < tileMap.numberOfTileTypes; x++)
    {
        inFile >> tileMap.tileTypes[x].passable >> tileMap.tileTypes[x].tileFileName;
    }

    //DONE LOADING NOW WE NEED TO LOAD THE SPRITE FILES
    //TAC:  I think if I do not use SDL_FreeSurface at the end it will allow the surface memory to remain, I will just lose the pointer to it when i re NULL.
    //      I am going to commment out the SDL_FreeSurface.  Then on the TileEngine Deconstructor, I am going to make a cleanup portion for these.
    for (int x = 0; x < tileMap.numberOfTileTypes; x++)
    {
        //Create a temporary surface to hold the tile texture in to load, then NULL it out.
        SDL_Surface* tempSurf = NULL;
        //Load the file given into the tempSurface.
        tempSurf = SDL_LoadBMP(tileMap.tileTypes[x].tileFileName.c_str());

        //Store the new surface into the TileSprites array.
        TileSprites.push_back(tempSurf);
        //Clean up temp surface.
        //TAC:COMMENTED OUT SO WE DO NOT LOSE THE DATA.
        //SDL_FreeSurface(tempSurf);
    }
}
void TileEngine::GenerateMap()
{
    //Find out how many tiles we have in the X,Y dimensions.
    int tilesX = tileMap.mapWidth / tileMap.tileWidth;
    int tilesY = tileMap.mapHeight / tileMap.tileHeight;

    //Run through all positions of tiles.
    for (int x = 0; x < tilesX; x++)
    {
        for (int y = 0; y < tilesY; y++)
        {
            //Gets the current tiles type.
            int tileTypeNumber = tileMap.tiles[x][y];
            //Pulls the current tiles filename for loading.
            string tileFileName = tileMap.tileTypes[tileTypeNumber].tileFileName.c_str();
            //Loads the current tiles filename into the CSprite painter.
            TilePainterSprite.SetFileName(tileFileName);
            //Initializes the painter.
            TilePainterSprite.OnInit();
            //Create a Pos2i to hold tile position in PIXELS.
            Pos2i tilePos;
            //Get the pixel position by multiplying tileheight and widths by the current tile position.
            tilePos.x = tileMap.tileWidth * x;
            tilePos.y = tileMap.tileHeight * y;
            //Set the painters position to the found Pixel position.
            TilePainterSprite.Move(tilePos);

            //Set up the map surf
            tileScreen=SDL_CreateRGBSurface(SDL_SWSURFACE,tileMap.mapWidth,tileMap.mapHeight,32,0,0,0,0);

            //Paint.
            TilePainterSprite.Render(tileScreen);

        }
    }
}

//Renders to target surface using set viewport portion.
bool TileEngine::RenderCurrentViewPort(SDL_Surface* pDestSurf)
{
    //Sets a SDL_Rect for the current viewport information.
    SDL_Rect viewRect = CDefault_Rect(currentViewPortCoords.x, currentViewPortCoords.y, viewPortSize.x, viewPortSize.y);

    //Renders the current viewport from tilescreen to the target Surface.
    if (SDL_BlitSurface(tileScreen, &viewRect, pDestSurf, NULL) != 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

