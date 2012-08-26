//
//  DataHolders.h
//  AdamantEngine
//
//  Created by Timothy Carlisle on 08/26/12.
/*
   Copyright 2011-2012 Timothy Carlisle

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef DATAHOLDERS_H_INCLUDED
#define DATAHOLDERS_H_INCLUDED


//Pos3i is a three dimensional integer based position data holder.
class Pos3i
{
public:
    //Store a Pos2i into a Pos3i Container.
    void equals(Pos2i p){this->x = p.x; this->y = p.y; this->z = 0;};
    //Store a Pos3f into a Pos3i Container.
    void equals(pos3f p){this->x = int(p.x); this->y = int(p.y); this->z = int(p.z);};
    //Store a Pos2f into a Pos3i Container.
    void equals(pos2f p){this->x = int(p.x); this->y = int(p.y); this->z = 0;};
    int x;
    int y;
    int z;
};

//Pos2i is a two dimensional integer based position data holder.
class Pos2i
{
public:
    //Store a Pos3i into a Pos2i Container.
    void equals(Pos3i p){this->x = p.x; this->y = p.y;};
    //Store a Pos3f into a Pos2i Container.
    void equals(pos3f p){this->x = int(p.x); this->y = int(p.y);};
    //Store a Pos2f into a Pos2i Container.
    void equals(pos2f p){this->x = int(p.x); this->y = int(p.y);};
    int x;
    int y;
};

//Pos3f is a three dimensional float based position data holder.
class Pos3f
{
public:
    //Store a Pos2i into a Pos3f Container.
    void equals(Pos2i p){this->x = float(p.x); this->y = float(p.y); this->z = 0.00;};
    //Store a Pos3i into a Pos3f Container.
    void equals(pos3i p){this->x = float(p.x); this->y = float(p.y); this->z = float(p.z);};
    //Store a Pos2f into a Pos3f Container.
    void equals(pos2f p){this->x = p.x; this->y = p.y; this->z = 0.00};
    float x;
    float y;
    float z;
};

//Pos2f is a two dimensional float based position data holder.
class Pos2f
{
public:
    //Store a Pos2i into a Pos2f Container.
    void equals(Pos2i p){this->x = float(p.x); this->y = float(p.y);};
    //Store a Pos3i into a Pos2f Container.
    void equals(pos3i p){this->x = float(p.x); this->y = float(p.y);};
    //Store a Pos3f into a Pos2f Container.
    void equals(pos3f p){this->x = p.x; this->y = p.y;};
    float x;
    float y;
};


//***OPERATOR OVERLOADING***

//3i=3i+-2i
//Pos3i=Pos3i+Pos2i
Pos3i operator + (Pos3i& left,Pos2i& right)
{
    Pos3i temp;
	temp.x = left.x + right.x;
	temp.y = left.y + right.y;
	temp.z = left.z;
	return temp;
};
//Pos3i=Pos3i-Pos2i
Pos3i operator - (Pos3i& left,Pos2i& right)
{
    Pos3i temp;
	temp.x = left.x - right.x;
	temp.y = left.y - right.y;
	temp.z = left.z;
	return temp;
};
//Pos3i=Pos2i+Pos3i
Pos3i operator + (Pos2i& left,Pos3i& right)
{
    Pos3i temp;
	temp.x = left.x + right.x;
	temp.y = left.y + right.y;
	temp.z = right.z;
	return temp;
};
//Pos3i=Pos2i-Pos3i
Pos3i operator - (Pos2i& left,Pos3i& right)
{
    Pos3i temp;
	temp.x = left.x - right.x;
	temp.y = left.y - right.y;
	temp.z = right.z;
	return temp;
};


//3i=3i+-3f
//Pos3i=Pos3i+Pos3f
Pos3i operator + (Pos3i& left,Pos3f& right)
{
    Pos3i temp;
	temp.x = left.x + int(right.x);
	temp.y = left.y + int(right.y);
	temp.z = left.z + int(right.z);
	return temp;
};
//Pos3i=Pos3i-Pos3f
Pos3i operator - (Pos3i& left,Pos3f& right)
{
    Pos3i temp;
	temp.x = left.x - int(right.x);
	temp.y = left.y - int(right.y);
	temp.z = left.z - int(right.z);
	return temp;
};
//Pos3i=Pos3f+Pos3i
Pos3i operator + (Pos3f& left,Pos3i& right)
{
    Pos3i temp;
	temp.x = int(left.x) + right.x;
	temp.y = int(left.y) + right.y;
	temp.z = int(left.z) + right.z;
	return temp;
};
//Pos3i=Pos3f-Pos3i
Pos3i operator - (Pos3f& left,Pos3i& right)
{
    Pos3i temp;
	temp.x = int(left.x) - right.x;
	temp.y = int(left.y) - right.y;
	temp.z = int(left.z) - right.z;
	return temp;
};


//3i=3i+-2f
//Pos3i=Pos3i+Pos2f
Pos3i operator + (Pos3i& left,Pos2f& right)
{
    Pos3i temp;
	temp.x = left.x + int(right.x);
	temp.y = left.y + int(right.y);
	temp.z = left.z;
	return temp;
};
//Pos3i=Pos3i-Pos2f
Pos3i operator - (Pos3i& left,Pos2f& right)
{
    Pos3i temp;
	temp.x = left.x - int(right.x);
	temp.y = left.y - int(right.y);
	temp.z = left.z;
	return temp;
};
//Pos3i=Pos2f+Pos3i
Pos3i operator + (Pos2f& left,Pos3i& right)
{
    Pos3i temp;
	temp.x = int(left.x) + right.x;
	temp.y = int(left.y) + right.y;
	temp.z = right.z;
	return temp;
};
//Pos3i=Pos2f-Pos3i
Pos3i operator - (Pos2f& left,Pos3i& right)
{
    Pos3i temp;
	temp.x = int(left.x) - right.x;
	temp.y = int(left.y) - right.y;
	temp.z = right.z;
	return temp;
};



//2i=2i+-3i
//Pos2i=Pos2i+Pos3i
Pos2i operator + (Pos2i& left,Pos3i& right)
{
    Pos2i temp;
	temp.x = left.x + right.x;
	temp.y = left.y + right.y;
	return temp;
};
//Pos2i=Pos2i-Pos3i
Pos2i operator - (Pos2i& left,Pos3i& right)
{
    Pos2i temp;
	temp.x = left.x - right.x;
	temp.y = left.y - right.y;
	return temp;
};
//Pos2i=Pos3i+Pos2i
Pos2i operator + (Pos3i& left,Pos2i& right)
{
    Pos2i temp;
	temp.x = left.x + right.x;
	temp.y = left.y + right.y;
	return temp;
};
//Pos2i=Pos3i-Pos2i
Pos2i operator - (Pos3i& left,Pos2i& right)
{
    Pos2i temp;
	temp.x = left.x - right.x;
	temp.y = left.y - right.y;
	return temp;
};


//2i=2i+-3f
//Pos2i=Pos2i+Pos3f
Pos2i operator + (Pos2i& left,Pos3f& right)
{
    Pos2i temp;
	temp.x = left.x + int(right.x);
	temp.y = left.y + int(right.y);
	return temp;
};
//Pos2i=Pos2i-Pos3f
Pos2i operator - (Pos2i& left,Pos3f& right)
{
    Pos2i temp;
	temp.x = left.x - int(right.x);
	temp.y = left.y - int(right.y);
	return temp;
};
//Pos2i=Pos3f+Pos2i
Pos2i operator + (Pos3f& left,Pos2i& right)
{
    Pos2i temp;
	temp.x = int(left.x) + right.x;
	temp.y = int(left.y) + right.y;
	return temp;
};
//Pos2i=Pos3f-Pos2i
Pos2i operator - (Pos3f& left,Pos2i& right)
{
    Pos2i temp;
	temp.x = int(left.x) - right.x;
	temp.y = int(left.y) - right.y;
	return temp;
};


//2i=2i+-2f
//Pos2i=Pos2i+Pos2f
Pos2i operator + (Pos2i& left,Pos2f& right)
{
    Pos2i temp;
	temp.x = left.x + int(right.x);
	temp.y = left.y + int(right.y);
	return temp;
};
//Pos2i=Pos2i-Pos2f
Pos2i operator - (Pos2i& left,Pos2f& right)
{
    Pos2i temp;
	temp.x = left.x - int(right.x);
	temp.y = left.y - int(right.y);
	return temp;
};
//Pos2i=Pos2f+Pos2i
Pos2i operator + (Pos2f& left,Pos2i& right)
{
    Pos2i temp;
	temp.x = int(left.x) + right.x;
	temp.y = int(left.y) + right.y;
	return temp;
};
//Pos2i=Pos2f-Pos2i
Pos2i operator - (Pos2f& left,Pos2i& right)
{
    Pos2i temp;
	temp.x = int(left.x) - right.x;
	temp.y = int(left.y) - right.y;
	return temp;
};




//3f=3f+-3i
//Pos3f=Pos3f+Pos3i
Pos3f operator + (Pos3f& left,Pos3i& right)
{
    Pos3f temp;
	temp.x = left.x + right.x;
	temp.y = left.y + right.y;
	temp.z = left.z;
	return temp;
};
//Pos3f=Pos3f-Pos3i
Pos3f operator - (Pos3f& left,Pos3i& right)
{
    Pos3f temp;
	temp.x = left.x - right.x;
	temp.y = left.y - right.y;
	temp.z = left.z;
	return temp;
};
//Pos3f=Pos3i+Pos3f
Pos3f operator + (Pos3i& left,Pos3f& right)
{
    Pos3f temp;
	temp.x = left.x + right.x;
	temp.y = left.y + right.y;
	temp.z = right.z;
	return temp;
};
//Pos3f=Pos3i-Pos3f
Pos3f operator - (Pos3i& left,Pos3f& right)
{
    Pos3f temp;
	temp.x = left.x - right.x;
	temp.y = left.y - right.y;
	temp.z = right.z;
	return temp;
};


Pos3f operator + (Pos3f& left,Pos2i& right)
{
    Pos3f temp;
	temp.x = left.x + right.x;
	temp.y = left.y + right.y;
	temp.z = left.z;
	return temp;
};
//Pos3f=Pos3f-Pos2i
Pos3f operator - (Pos3f& left,Pos2i& right)
{
    Pos3f temp;
	temp.x = left.x - right.x;
	temp.y = left.y - right.y;
	temp.z = left.z;
	return temp;
};
//Pos3f=Pos2i+Pos3f
Pos3f operator + (Pos2i& left,Pos3f& right)
{
    Pos3f temp;
	temp.x = left.x + right.x;
	temp.y = left.y + right.y;
	temp.z = right.z;
	return temp;
};
//Pos3f=Pos2i-Pos3f
Pos3f operator - (Pos2i& left,Pos3f& right)
{
    Pos3f temp;
	temp.x = left.x - right.x;
	temp.y = left.y - right.y;
	temp.z = right.z;
	return temp;
};


//3f=3f+-2f
//Pos3f=Pos3f+Pos2f
Pos3f operator + (Pos3f& left,Pos2f& right)
{
    Pos3f temp;
	temp.x = left.x + right.x;
	temp.y = left.y + right.y;
	temp.z = left.z;
	return temp;
};
//Pos3f=Pos3f-Pos2f
Pos3f operator - (Pos3f& left,Pos2f& right)
{
    Pos3f temp;
	temp.x = left.x - right.x;
	temp.y = left.y - right.y;
	temp.z = left.z;
	return temp;
};
//Pos3f=Pos2f+Pos3f
Pos3f operator + (Pos2f& left,Pos3f& right)
{
    Pos3f temp;
	temp.x = left.x + right.x;
	temp.y = left.y + right.y;
	temp.z = right.z;
	return temp;
};
//Pos3f=Pos2f-Pos3f
Pos3f operator - (Pos2f& left,Pos3f& right)
{
    Pos3f temp;
	temp.x = left.x - right.x;
	temp.y = left.y - right.y;
	temp.z = right.z;
	return temp;
};



//2f=2f+-3i
//Pos2f=Pos2f+Pos3i
Pos2f operator + (Pos2f& left,Pos3i& right)
{
    Pos2f temp;
	temp.x = left.x + right.x;
	temp.y = left.y + right.y;
	return temp;
};
//Pos2f=Pos2f-Pos3i
Pos2f operator - (Pos2f& left,Pos3i& right)
{
    Pos2f temp;
	temp.x = left.x - right.x;
	temp.y = left.y - right.y;
	return temp;
};
//Pos2f=Pos3i+Pos2f
Pos2f operator + (Pos3i& left,Pos2f& right)
{
    Pos2f temp;
	temp.x = left.x + right.x;
	temp.y = left.y + right.y;
	return temp;
};
//Pos2f=Pos3i-Pos2f
Pos2f operator - (Pos3i& left,Pos2f& right)
{
    Pos2f temp;
	temp.x = left.x - right.x;
	temp.y = left.y - right.y;
	return temp;
};


//2f=2f+-3f
//Pos2f=Pos2f+Pos3f
Pos2f operator + (Pos2f& left,Pos3f& right)
{
    Pos2f temp;
	temp.x = left.x + right.x;
	temp.y = left.y + right.y;
	return temp;
};
//Pos2f=Pos2f-Pos3f
Pos2f operator - (Pos2f& left,Pos3f& right)
{
    Pos2f temp;
	temp.x = left.x - right.x;
	temp.y = left.y - right.y;
	return temp;
};
//Pos2f=Pos3f+Pos2f
Pos2f operator + (Pos3f& left,Pos2f& right)
{
    Pos2f temp;
	temp.x = left.x + right.x;
	temp.y = left.y + right.y;
	return temp;
};
//Pos2f=Pos3f-Pos2f
Pos2f operator - (Pos3f& left,Pos2f& right)
{
    Pos2f temp;
	temp.x = left.x - right.x;
	temp.y = left.y - right.y;
	return temp;
};


//2f=2f+-2i
//Pos2f=Pos2f+Pos2i
Pos2f operator + (Pos2f& left,Pos2i& right)
{
    Pos2f temp;
	temp.x = left.x + right.x;
	temp.y = left.y + right.y;
	return temp;
};
//Pos2f=Pos2f-Pos2i
Pos2f operator - (Pos2f& left,Pos2i& right)
{
    Pos2i temp;
	temp.x = left.x - right.x;
	temp.y = left.y - right.y;
	return temp;
};
//Pos2f=Pos2i+Pos2f
Pos2f operator + (Pos2i& left,Pos2f& right)
{
    Pos2f temp;
	temp.x = left.x + right.x;
	temp.y = left.y + right.y;
	return temp;
};
//Pos2f=Pos2i-Pos2f
Pos2f operator - (Pos2i& left,Pos2f& right)
{
    Pos2f temp;
	temp.x = left.x - right.x;
	temp.y = left.y - right.y;
	return temp;
};

#endif // DATAHOLDERS_H_INCLUDED
