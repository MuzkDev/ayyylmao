#include <SDL.h>
#include <iostream>
#include "LoadSurface.h"
#include <SDL_image.h>
bool hideCursor()
{
	SDL_ShowCursor(SDL_DISABLE);
	return true;
}

bool createCursor()
{
	SDL_Surface *cursorSurface = NULL;
	SDL_Surface *SDL_DisplayFormat(SDL_Surface *cursorSurface);
	if (!loadSurface("Assets/egun.png"))
	{
		std::cout << "SDL could not load egunCursor png data. SDL error type: \n" << SDL_GetError() << "\n";
	}
	else
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		SDL_Rect DestR;
		DestR.x = x;
		DestR.y = y - 11;
		cursorSurface = loadSurface("Assets/egun.png");
		SDL_BlitSurface(cursorSurface, NULL, gScreenSurface, &DestR);
	}
	return true;
}