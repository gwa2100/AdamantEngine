#ifndef TILEENGINE_H
#define TILEENGINE_H

#include <string>
#include "Sprite.h"

using namespace std;

//These set the maximums for the map loader.
const unsigned short int _TilesMaxX = 1000;
const unsigned short int _TilesMaxY = 1000;
const unsigned short int _TileTypesMax = 256;

//Holds the file information for each type of tile and if they are passable as in can an object pass through.
struct TileTypes
{
    string tileFileName;
    bool passable;
};

//Holds the map data for loading and storing of maps.
struct MapFile
{
    //Where you can name the map.
    string mapName;
    //Total map width in PIXELS
    int mapWidth;
    //Total map height in PIXELS
    int mapHeight;
    //Tile Width in PIXELS
    int tileWidth;
    //Tile Height in PIXELS
    int tileHeight;
    //Tile array to hold all of the tiles on the map. Holds an integer which maps to a TileType.
    int tiles[_TilesMaxX][_TilesMaxY];
    //A counter to keep up with the number of registered tile types.
    int numberOfTileTypes;
    //An array to hold all the different tile types loaded to the system.
    TileTypes tileTypes[_TileTypesMax];
};

//Safety encapsulation for the SDL_Surface* used in the TileSprites array.
class TileEngineTexturePtrVector : public vector< SDL_Surface* >
{
    public:
    TileEngineTexturePtrVector() {}
    ~TileEngineTexturePtrVector()
    {
        ResetContent();
    }

    void ResetContent()
    {
        if ( size() == 0 ) return;

        SDL_Surface** ppObjects = data();
        for(size_t n = 0; n < size(); n++)
        {
            delete ppObjects[n];
        }

        clear();

        TileEngineTexturePtrVector().swap( *this );
    }

};

//This is the core of the TileEngine.
class TileEngine
{
public:
    /** Default constructor */
    TileEngine(){tileScreen = NULL;};

    /** Default destructor */
    virtual ~TileEngine();

    //This sets the view port size.  Typically set to be what size the screen will be that will displaying the map.
    void SetViewPortSize(Pos2i vSize){viewPortSize = vSize;};
    //This sets the current view port position.
    void SetCurrentViewPortCoords(Pos2i cView){currentViewPortCoords = cView;};
    //To move the viewport.
    void MoveCurrentViewPortCoords(Pos2i moveXY){currentViewPortCoords.x += moveXY.x; currentViewPortCoords.y += moveXY.y;};
    //Return the current map size in type Pos2i.
    Pos2i GetMapSize(){return Pos2i(tileMap.mapWidth, tileMap.mapHeight);};
    //Return the current Tile Size in type Pos2i.
    Pos2i GetTileSize(){return Pos2i(tileMap.tileWidth, tileMap.tileHeight);};
    //Return the current view port size in type Pos2i.
    Pos2i GetViewPortSize(){return viewPortSize;};
    //Return the current view port postion in type Pos2i.
    Pos2i GetCurrentViewPortCoords(){return currentViewPortCoords;};

    //Primary way of getting the map.
    bool RenderCurrentViewPort(SDL_Surface* pDestSurf);

    //Load map from a given file name.
    void LoadMap(string fileName);
    //Generate the initial tile engine Surface -tileScreen.
    void GenerateMap();
    //Most likely will not be used, as you will only want a viewport.
    SDL_Surface* GetTileScreen(){return tileScreen;};

protected:
    //This is a CSprite that is used to draw all of the tiles on to the tileScreen Surface.
    CSprite TilePainterSprite;
    //This contains all of the loaded tile textures that have been loaded with the map.
    TileEngineTexturePtrVector TileSprites;
    //This is the actual map file.
    MapFile tileMap;
    //This is the primary generated map surface.  This is generated once and portions are rendered out to the main screen as requested.
    SDL_Surface* tileScreen;

    //The size in pixels of the window to display the map, it will show a piece of the map this size.
    Pos2i viewPortSize;
    //Top left corner of where the viewport is.
    Pos2i currentViewPortCoords;
};

#endif // TILEENGINE_H
