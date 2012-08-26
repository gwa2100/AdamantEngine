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

struct Pos3i
{
    int x;
    int y;
    int z;
};

struct Pos2i
{
    int x;
    int y;
};

struct Pos3f
{
    float x;
    float y;
    float z;
};

struct Pos2f
{
    float x;
    float y;
};

Pos3i operator + (Pos3i& left,Pos3i& right)
{
    Pos3i temp;
	temp.x = left.x + right.x;
	temp.y = left.y + right.y;
	temp.z = left.z + right.z;
	return temp;
};

Pos3i operator - (Pos3i& left,Pos3i& right)
{
    Pos3i temp;
	temp.x = left.x - right.x;
	temp.y = left.y - right.y;
	temp.z = left.z - right.z;
	return temp;
};

Pos2i operator + (Pos2i& left,Pos2i& right)
{
    Pos2i temp;
	temp.x = left.x + right.x;
	temp.y = left.y + right.y;
	return temp;
};

Pos2i operator - (Pos2i& left,Pos2i& right)
{
    Pos2i temp;
	temp.x = left.x - right.x;
	temp.y = left.y - right.y;
	return temp;
};

Pos3i operator + (Pos3i& left,Pos2i& right)
{
    Pos3i temp;
	temp.x = left.x + right.x;
	temp.y = left.y + right.y;
	temp.z = left.z;
	return temp;
};

Pos3i operator - (Pos3i& left,Pos2i& right)
{
    Pos3i temp;
	temp.x = left.x - right.x;
	temp.y = left.y - right.y;
	temp.z = left.z;
	return temp;
};

//Need to make ability to assign different types.

#endif // DATAHOLDERS_H_INCLUDED
