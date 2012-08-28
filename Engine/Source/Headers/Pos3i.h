#ifndef POS3I_H_INCLUDED
#define POS3I_H_INCLUDED


//Pos3i is a three dimensional integer based position data holder.
class Pos3i
{
public:
    //Store a Pos2i into a Pos3i Container.
    //void equals(Pos2i& p){this->x = p.x; this->y = p.y; this->z = 0;};
    //Store a Pos3f into a Pos3i Container.
    //void equals(Pos3f& p){this->x = int(p.x); this->y = int(p.y); this->z = int(p.z);};
    //Store a Pos2f into a Pos3i Container.
    //void equals(Pos2f& p){this->x = int(p.x); this->y = int(p.y); this->z = 0;};
    int x;
    int y;
    int z;



    //Overloads Operator
    /*
    Pos3i operator + (Pos3i& left,Pos2i& right);
    Pos3i operator - (Pos3i& left,Pos2i& right);
    Pos3i operator + (Pos2i& left,Pos3i& right);
    Pos3i operator - (Pos2i& left,Pos3i& right);
    Pos3i operator + (Pos3i& left,Pos3f& right);
    Pos3i operator - (Pos3i& left,Pos3f& right);
    Pos3i operator + (Pos3f& left,Pos3i& right);
    Pos3i operator - (Pos3f& left,Pos3i& right);
    Pos3i operator + (Pos3i& left,Pos2f& right);
    Pos3i operator - (Pos3i& left,Pos2f& right);
    Pos3i operator + (Pos2f& left,Pos3i& right);
    Pos3i operator - (Pos2f& left,Pos3i& right);
    */

};

#endif // POS3I_H_INCLUDED
