#ifndef POS3F_H_INCLUDED
#define POS3F_H_INCLUDED

//Pos3f is a three dimensional float based position data holder.
class Pos3f
{
public:
    //Store a Pos2i into a Pos3f Container.
    //void equals(Pos2i& p){this->x = float(p.x); this->y = float(p.y); this->z = 0.00;};
    //Store a Pos3i into a Pos3f Container.
    //void equals(Pos3i& p){this->x = float(p.x); this->y = float(p.y); this->z = float(p.z);};
    //Store a Pos2f into a Pos3f Container.
    //void equals(Pos2f& p){this->x = p.x; this->y = p.y; this->z = 0.00};
    float x;
    float y;
    float z;
};

#endif // POS3F_H_INCLUDED
