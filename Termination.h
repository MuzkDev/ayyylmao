#include <SDL.h>
#include <SDL_image.h>

void close()
{
	IMG_Quit();
	SDL_Quit();
}