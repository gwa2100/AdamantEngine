#ifndef BRICKS_H
#define BRICKS_H

#include <CApp.h>


class Bricks : public Sprite
{
    public:
        virtual bool OnCollision();
        virtual bool Update();
        /** Default constructor */
        Bricks();
        /** Default destructor */
        virtual ~Bricks();
    protected:
        bool Impact();
    private:
};

#endif // BRICKS_H
