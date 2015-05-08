#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#ifndef _LOADSURFACE_H_
#define _LOADSURFACE_H_

SDL_Surface* loadSurface(std::string path)
{

	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		std::cout << "Unable to load image. SDL error type:\n" << path.c_str() << SDL_GetError();
	}
	else
	{
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, NULL);
		if (optimizedSurface == NULL)
		{
			std::cout << "Unable to optimize image %s! SDL Error: \n" << path.c_str() << "\n" << SDL_GetError() << "\n";
		}
		SDL_FreeSurface(loadedSurface);
	}
	return optimizedSurface;
};

#endif