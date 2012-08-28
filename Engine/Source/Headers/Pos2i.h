#ifndef POS2I_H_INCLUDED
#define POS2I_H_INCLUDED

//Pos2i is a two dimensional integer based position data holder.
class Pos2i
{
public:
    //Store a Pos3i into a Pos2i Container.
    //void equals(Pos3i& p){this->x = p.x; this->y = p.y;};
    //Store a Pos3f into a Pos2i Container.
    //void equals(Pos3f& p){this->x = int(p.x); this->y = int(p.y);};
    //Store a Pos2f into a Pos2i Container.
    //void equals(Pos2f& p){this->x = int(p.x); this->y = int(p.y);};
    int x;
    int y;
};

#endif // POS2I_H_INCLUDED
