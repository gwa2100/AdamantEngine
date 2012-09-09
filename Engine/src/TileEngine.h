#ifndef TILEENGINE_H
#define TILEENGINE_H

#include <string>
#include "Sprite.h"

using namespace std;

const unsigned short int _TilesMaxX = 1000;
const unsigned short int _TilesMaxY = 1000;
const unsigned short int _TileTypesMax = 256;

struct TileTypes
{
    string tileFileName;
    bool passable;
};

struct MapFile
{
    string mapName;
    int mapWidth;
    int mapHeight;
    int tileWidth;
    int tileHeight;
    int tiles[_TilesMaxX][_TilesMaxY];
    int numberOfTileTypes;
    TileTypes tileTypes[_TileTypesMax];
};

class TileEngine
{
public:
    /** Default constructor */
    TileEngine(){tileScreen = NULL;};

    /** Default destructor */
    virtual ~TileEngine();

    void SetViewPortSize(Pos2i vSize){viewPortSize = vSize;};
    void SetCurrentViewPortCoords(Pos2i cView){currentViewPortCoords = cView;};

    Pos2i GetMapSize(){return Pos2i(tileMap.mapWidth, tileMap.mapHeight);};
    Pos2i GetTileSize(){return Pos2i(tileMap.tileWidth, tileMap.tileHeight);};
    Pos2i GetViewPortSize(){return viewPortSize;};
    Pos2i GetCurrentViewPortCoords(){return currentViewPortCoords;};

    //Primary way of getting the map.
    bool RenderCurrentViewPort(SDL_Surface* pDestSurf);

    void LoadMap(string fileName);
    void GenerateMap();
    //Most likely will not be used, as you will only want a viewport.
    SDL_Surface* GetTileScreen(){return tileScreen;};

protected:
    CSprite TilePainterSprite;          //Will use this sprite for bliting the tiles to the tileScreen.
    vector<SDL_Surface*> TileSprites;
    MapFile tileMap;
    SDL_Surface* tileScreen;
    SDL_Surface* viewPort;
    //The size in pixels of the window to display the map, it will show a piece of the map this size.
    Pos2i viewPortSize;
    //Top left corner of where the viewport is.
    Pos2i currentViewPortCoords;
};


#endif // TILEENGINE_H
