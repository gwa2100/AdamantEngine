#ifndef POS2F_H_INCLUDED
#define POS2F_H_INCLUDED

//Pos2f is a two dimensional float based position data holder.
class Pos2f
{
public:
    //Store a Pos2i into a Pos2f Container.
    //void equals(Pos2i& p){this->x = float(p.x); this->y = float(p.y);};
    //Store a Pos3i into a Pos2f Container.
    //void equals(Pos3i& p){this->x = float(p.x); this->y = float(p.y);};
    //Store a Pos3f into a Pos2f Container.
    //void equals(Pos3f& p){this->x = p.x; this->y = p.y;};
    float x;
    float y;
};

#endif // POS2F_H_INCLUDED
