#ifndef ENGINE_H
#define ENGINE_H

#include "constants.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_events.h>
#include <vector>
//#include "TileEngine.h"
#include "ATimer.h"
//#include "GameObjectPtrVector.h"
#include <stdint.h>

using std::vector;

class Engine
{
    public:
        /** Default constructor */
        Engine();
        /** Default destructor */
        virtual ~Engine();

        int Execute();
        bool Init();
        //void Bind(GameObject* pBindMe);


    private:
        ATimer m_timer;
        bool m_bRunning;
};

#endif // ENGINE_H
