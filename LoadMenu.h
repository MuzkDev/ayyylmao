#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
bool loadPreMainMenu()
{

		int wWidth = 1600;
		int wHeight = 900;
		std::cout << "Initializing window.\n";
		gWindow = SDL_CreateWindow("Warden's Plight", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, wWidth, wHeight, SDL_WINDOW_FULLSCREEN);
		if (gWindow == NULL)
		{
			std::cout << "SDL could not CreateWindow. SDL error type: \n" << SDL_GetError() << "\n";
		}
		else
		{
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				std::cout << "SDL_image rendering could not initizialie. SDL error type:\n" << SDL_GetError() << "\n";
			}
		}
		std::cout << "Placing global surface in window.\n";
		gScreenSurface = SDL_GetWindowSurface(gWindow);
		SDL_Delay(5000);
		return true;
};

bool loadMainmenu()
{
	bool success = true;
	{
		int wWidth = 1600;
		int wHeight = 900;
		std::cout << "Initializing engine.\n";
		gWindow = SDL_CreateWindow("Warden's Plight", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, wWidth, wHeight, SDL_WINDOW_FULLSCREEN);
		if (gWindow == NULL)
		{
			std::cout << "SDL could not CreateWindow. SDL error type: \n" << SDL_GetError() << "\n";
			success = false;
		}
		SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);
		return success;
	}
};