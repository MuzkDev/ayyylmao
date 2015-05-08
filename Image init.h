#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
SDL_Window* gWindow = NULL;
SDL_Texture* loadTexture(std::string path);
SDL_Renderer* gRenderer = NULL;
SDL_Texture* gTexture = NULL;
SDL_Surface* gCurrentSurface = NULL;
SDL_Surface* gScreenSurface = NULL;
bool init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL could not INIT EVERYTHING. SDL error type: \n" << SDL_GetError() << "\n";
	}
	else
		{
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				std::cout << "SDL_image could not initialize renderer. SDL error type:\n" << SDL_GetError() << "\n";
			}
		}
		std::cout << "Initializing window.\n";
		gScreenSurface = SDL_GetWindowSurface(gWindow);
	return true;
}