#ifndef BALL_H
#define BALL_H

#include <CApp.h>


class Ball : public Sprite
{
    public:
        virtual bool OnCollision(int side);
        virtual bool Update();
        int direction; //1 NW 2 NE 3 SW 4 SE 0 STILL
        /** Default constructor */
        Ball();
        /** Default destructor */
        virtual ~Ball();
    protected:
    private:


};

#endif // BALL_H
