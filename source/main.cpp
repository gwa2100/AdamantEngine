#include "main.h"
#include "SDL2/SDL.h"
#include <iostream>
#include "GameObject.h"
#include "GameObjectComponent.h"
#include "GameObjectComponent-Renderer.h"
#include "GameObject.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	SDL_Window* window = NULL;

	SDL_Surface* mainScreenSurface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL COUD NOT INIT! ERROR: " << SDL_GetError();
	}
	else
	{
		window = SDL_CreateWindow("Landslide", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			std::cout << "COULD NOT CREATE WINDOW! ERROR : " << SDL_GetError();
		}
		else
		{
			//Get window surface
			mainScreenSurface = SDL_GetWindowSurface(window);

			//Fill the surface white
			SDL_FillRect(mainScreenSurface, NULL, SDL_MapRGB(mainScreenSurface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(window);

			//Wait two seconds
			std::cout << "START DELAY!";
			SDL_Delay(2000);

			GameObject* TestObject = new GameObject(Pos3f(1, 1, 1));
			TestObject->AddRenderComponent(mainScreenSurface, "AdamantLogo.bmp", Pos2f(105, 91));

			std::cout << "BEGIN LOOP 10x";
			for (int x = 0; x < 10; ++x)
			{
				SDL_FillRect(mainScreenSurface, NULL, SDL_MapRGB(mainScreenSurface->format, 0xFF, 0xFF, 0xFF));
				TestObject->Move(Pos3f(10, 10, 0));
				TestObject->OnLoop();
				SDL_UpdateWindowSurface(window);
				SDL_Delay(250);
			}
			std::cout << "LOOP COMPLETE! WAITING 5 seconds!";
			delete TestObject;
			SDL_Delay(5000);
		}
	}
	return 0;
}
