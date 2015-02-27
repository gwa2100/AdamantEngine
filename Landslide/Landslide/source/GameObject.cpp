//
//  GAMEOBJECT.CPP
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



#include "GameObject.h"
#include <SDL/SDL.h>


//*********************************************************** GAMEOBJECT ***********************************************************

GameObject::GameObject(Pos3f iPosition)
{
	position = iPosition;
}

GameObject::~GameObject()
{

}

bool GameObject::OnCreate()
{
	return true;
}

bool GameObject::OnLoop()
{
	//TODO: Make sure this fits right, may need to change coding.
	attachedComponents.back()->OnLoop();
	return true;
}

bool GameObject::Cleanup()
{
	return true;
}

void GameObject::Move(const Pos3f& pos)
{
	position.x += pos.x;
	position.y += pos.y;
	position.z += pos.z;
}

void GameObject::SetPosition(const Pos3f& pos)
{
	position.x = pos.x;
	position.y = pos.y;
	position.z = pos.z;
}

//Get Position
Pos3f GameObject::GetPosition() const
{
	return position;
}


//Set Dimensions -DEPRECATED[Moved into components]
/*
void GameObject::SetDimensions(const Pos2f& dim)
{
	dimensions = dim;
}

//Get Dimensions -DEPRECATED[Moved into components]
Pos2f GameObject::GetDimensions() const
{
	return dimensions;
}
*/

//These components are just meant to help with component creation, they are not required to be used, as you can create and bind the components yourself.
//Add Render Component
bool GameObject::AddRenderComponent(SDL_Surface* paramScreenPtr)
{
	RenderComponent* newRenderComponent = new RenderComponent(paramScreenPtr);
	newRenderComponent->SetParent(this);
	if (attachedComponents.BindComponent(newRenderComponent) != nullptr)
		return true;
	else
		return false;
}

bool GameObject::AddRenderComponent(SDL_Surface* paramScreenPtr, std::string paramFileToLoad, Pos2f paramDimensions)
{
	RenderComponent* newRenderComponent = new RenderComponent(paramScreenPtr, paramFileToLoad, paramDimensions);
	newRenderComponent->SetParent(this);
	if (attachedComponents.BindComponent(newRenderComponent) != nullptr)
		return true;
	else
		return false;
}

//Add Player-Control Component
bool GameObject::AddPlayerComponent()
{
	return false;
}

//Add Event-Handling Component
bool GameObject::AddEventComponent()
{
	return false;
}

GameObjectComponent* GameObject::BindComponent(GameObjectComponent* paramGameObjectComponentPtr)
{
	return attachedComponents.BindComponent(paramGameObjectComponentPtr);
}












//***********************************************************COMPONENT***********************************************************
GameObjectComponent::GameObjectComponent(Object* paramParentObject)
{
	parentObject = paramParentObject;
}

GameObjectComponent::GameObjectComponent()
{

}

GameObjectComponent::~GameObjectComponent()
{

}

//On creation run this
bool GameObjectComponent::OnCreate()
{
	return true;
}

//Run this once per loop
bool GameObjectComponent::OnLoop()
{
	return true;
}

//Run this upon exiting or destruction.
bool GameObjectComponent::Cleanup()
{
	return true;
}

//***********************************************************RENDER COMPONENT***********************************************************
RenderComponent::RenderComponent()
{

}

RenderComponent::~RenderComponent()
{

}

RenderComponent::RenderComponent(SDL_Surface* paramScreenPtr)
{
	screenPointer = paramScreenPtr;
}

RenderComponent::RenderComponent(SDL_Surface* paramScreenPtr, std::string paramFileToLoad, Pos2f paramDimensions)
{
	screenPointer = paramScreenPtr;
	CreateFromFile(paramFileToLoad);
	SetDimensions(paramDimensions);
}


//On creation run this
bool RenderComponent::OnCreate()
{
	return true;
}

//Run this once per loop
bool RenderComponent::OnLoop()
{
	SDL_Rect tempRect;
	Pos3f tempPos3f;
	tempPos3f = parentObject->GetPositionPrimitive();
	tempRect.x = tempPos3f.x;
	tempRect.y = tempPos3f.y;
	tempRect.w = dimensions.x;
	tempRect.h = dimensions.y;
	if (SDL_BlitScaled(sprite, NULL, screenPointer, &tempRect) == 0)
		return true;
	else
		return false;
}

//Run this upon exiting or destruction.
bool RenderComponent::Cleanup()
{
	return true;
}


bool RenderComponent::CreateFromFile(const std::string& sFilename)
{
	SDL_Surface* pTemp = SDL_LoadBMP(sFilename.c_str());
	if (pTemp == NULL) return false;

	SDL_Surface* pSurface = SDL_ConvertSurface(pTemp, screenPointer->format, NULL);

	dimensions.x = pSurface->w;
	dimensions.y = pSurface->h;

	bool bValid = pSurface != NULL;

	SDL_FreeSurface(pTemp);

	if (bValid)
	{
		sprite = pSurface;
	}

	return bValid;

}