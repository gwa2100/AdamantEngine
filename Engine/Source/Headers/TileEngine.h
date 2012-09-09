#ifndef TILEENGINE_H
#define TILEENGINE_H

#include

class TileEngine
{
    public:
        /** Default constructor */
        TileEngine();

        /** Default destructor */
        virtual ~TileEngine();

        /** Access tileScreen
         * \return The current value of tileScreen
         */
        SDL_Surface* GettileScreen() { return tileScreen; }

        /** Set tileScreen
         * \param val New value to set
         */
        void SettileScreen(SDL_Surface* val) { tileScreen = val; }

        /** Access mapSize
         * \return The current value of mapSize
         */
        Pos2i GetmapSize() { return mapSize; }

        /** Set mapSize
         * \param val New value to set
         */
        void SetmapSize(Pos2i val) { mapSize = val; }

        /** Access tileSize
         * \return The current value of tileSize
         */
        Pos2i GettileSize() { return tileSize; }

        /** Set tileSize
         * \param val New value to set
         */
        void SettileSize(Pos2i val) { tileSize = val; }

        /** Access viewPortSize
         * \return The current value of viewPortSize
         */
        Pos2i GetviewPortSize() { return viewPortSize; }

        /** Set viewPortSize
         * \param val New value to set
         */
        void SetviewPortSize(Pos2i val) { viewPortSize = val; }

        /** Access currentViewPort
         * \return The current value of currentViewPort
         */
        Pos2i GetcurrentViewPort() { return currentViewPort; }

        /** Set currentViewPort
         * \param val New value to set
         */
        void SetcurrentViewPort(Pos2i val) { currentViewPort = val; }

    protected:

        vector<SDL_Surface*> TileSprites; //!< Member variable "TileSprites"
        SDL_Surface* tileScreen; //!< Member variable "tileScreen"
        Pos2i mapSize; //!< Member variable "mapSize"
        Pos2i tileSize; //!< Member variable "tileSize"
        Pos2i viewPortSize; //!< Member variable "viewPortSize"
        Pos2i currentViewPort; //!< Member variable "currentViewPort"
    private:

};

#endif // TILEENGINE_H
