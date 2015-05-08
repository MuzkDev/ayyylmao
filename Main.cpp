#include <iostream>
#include <SDL.h>
#include "Cursor Change.h"
#include "Image init.h"
#include "LoadMenu.h"
#include "Termination.h"
int main(int argc, char* args[])
{
	if (!init())
	{
		std::cout << "Failed to initialize.\n" << SDL_GetError();
	}
	else
	{
		if (!hideCursor())
		{
			std::cout << "Failed to hide cursor\n" << SDL_GetError();
		}
		else if (!createCursor())
		{
			std::cout << "Failed to create cursor\n" << SDL_GetError();
		}
		std::cout << "Initializing user input.\n";
		SDL_Event eventHandler;
		bool quit = false;
		while (!quit)
		{
			while (SDL_PollEvent(&eventHandler) != 0)
			{
				if (eventHandler.type == SDL_QUIT)
				{
					quit = true;
				}
				else if (!loadPreMainMenu())
				{
					std::cout << "Failed to load pre main menu.\n" << SDL_GetError();
				}
				else if (!loadMainmenu())
				{
					std::cout << "Failed to load main menu.\n" << SDL_GetError();
				}
			}
		}
	}
	close();
	return 0;
}