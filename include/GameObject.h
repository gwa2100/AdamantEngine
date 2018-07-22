#pragma once
//
//  GAMEOBJECT.H
//  AdamantEngine
//
//  Created by Timothy Carlisle on 02/15/15.
/*
Copyright 2011-2015 Timothy Carlisle

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
#include "PositionDataTypes.h"
#include <stdint.h>
#include <SDL2/SDL.h>
#include <vector>
#include <string>


//*********************************************************** OBJECT ***********************************************************
//This class is simply to allow access to position information through polymorphism.
class Object
{
public:
	virtual Pos3f GetPositionPrimitive(){ return position; };
protected:
	// Position of GameObject X, Y, Z in Pos3i format
	Pos3f position;
};
//*********************************************************** GAMEOBJECTCOMPONENT ***********************************************************

class GameObjectComponent
{
	class GameObject;
public:
	GameObjectComponent();  //-NEVER ALLOW TO DEFAULT-
	GameObjectComponent(Object* paramParentObject);
	virtual ~GameObjectComponent();

	//On creation run this
	virtual bool OnCreate();

	//Run this once per loop
	virtual bool OnLoop();

	//Run this upon exiting or destruction.
	virtual bool Cleanup();

	void SetParent(Object* paramParentObject) { parentObject = paramParentObject; };
protected:
	std::string componentName;
	std::string errorMessage;

	//Parent is the object this component is attached to.  Gives access to the parent for logic.
	Object* parentObject;

};


//This vector is used to store a custom vector for component pointers.
//*********************************************************** GAMEOBJECTPTRVECTOR ***********************************************************

using std::vector;
class GameObjectComponentPtrVector : public vector< GameObjectComponent* >
{
public:
	GameObjectComponentPtrVector() {}
	~GameObjectComponentPtrVector()
	{
		ResetContent();
	}

	GameObjectComponent* BindComponent(GameObjectComponent* paramGOC)
	{
		push_back(paramGOC);
		return back();
	}

	void ResetContent()
	{
		if (size() == 0) return;

		GameObjectComponent** ppObjects = data();
		for (size_t n = 0; n < size(); n++)
		{
			delete ppObjects[n];
		}

		clear();

		GameObjectComponentPtrVector().swap(*this);
	}

};


//*********************************************************** GAMEOBJECT ***********************************************************

class GameObject : public Object
{
public:
	//KMS: maybe make these private and have a const getter..

	GameObject(Pos3f iPosition = Pos3f());

	Pos3f GetPositionPrimitive(){ return position; };

	//On creation run this
	bool OnCreate();

	//Run this once per loop
	bool OnLoop();

	//Run this upon exiting or destruction.
	bool Cleanup();

	//Move Object Directly
	void Move(const Pos3f& pos);

	//Set Positions
	void SetPosition(const Pos3f& pos);

	//Get Position
	Pos3f GetPosition() const;

	//Set Dimensions -DEPRECATED[Moved into components]
	//void SetDimensions(const Pos2f& dim);

	//Get Dimensions -DEPRECATED[Moved into components]
	//Pos2f GetDimensions() const;

	//These components are just meant to help with component creation, they are not required to be used, as you can create and bind the components yourself.
	//Add Render Component
	bool AddRenderComponent(SDL_Surface* paramScreenPtr);
	bool AddRenderComponent(SDL_Surface* paramScreenPtr, std::string paramFileToLoad, Pos2f paramDimensions);

	//Add Player-Control Component
	bool AddPlayerComponent();

	//Add Event-Handling Component
	bool AddEventComponent();

	//Bind new component
	GameObjectComponent* BindComponent(GameObjectComponent* paramGameObjectComponentPtr);

	virtual ~GameObject();




protected:
	//Dimensions of Game Object W,H in Pos2i format -DEPRECATED[Moved into components]
	//Pos2f dimensions;
	//Dimensions of bounding box used for collisions in SDL_Rect format. -DEPRECATED [Moved into components]
	//CRect boundBox;
	//Velocity of object for use in update movement.-DEPRECATED [Moved into components]
	//Pos3f velocity;
	//Vector of Attached Components
	GameObjectComponentPtrVector attachedComponents;



};





//*********************************************************** RENDERCOMPONENT ***********************************************************

class RenderComponent : public GameObjectComponent
{
public:
	RenderComponent();
	RenderComponent(SDL_Surface* paramScreenPtr);  //ONLY PRESENT FOR MANUAL SETUP....PREFER USE OF BELOW CONSTRUCTOR
	RenderComponent(SDL_Surface* paramScreenPtr, std::string paramFileToLoad, Pos2f paramDimensions);
	~RenderComponent();
	//On creation run this
	bool OnCreate();

	//Run this once per loop
	bool OnLoop();

	//Run this upon exiting or destruction.
	bool Cleanup();



	//TODO: Maybe add scaling

	void SetDimensions(Pos2f paramDimensions) { dimensions = paramDimensions; };
	Pos2f GetDimensions(){ return dimensions; };
	bool CreateFromFile(const std::string& sFileName);
protected:
	Pos2f dimensions;
	SDL_Surface* screenPointer;
	SDL_Surface* sprite;
};
