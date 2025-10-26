#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

/* Return 0 on success and negtive values on failure */
int sdl_init()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
	{
		std::cerr << "Can't initialize SDL: " << SDL_GetError() << "\n";
		return (-1);
	}

	if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		std::cerr << "Can't initialize SDL_image: " << IMG_GetError() << "\n";
		SDL_Quit();
		return (-2);
	}

	if (TTF_Init() != 0)
	{
		std::cerr << "Can't initialize SDL_ttf: " << TTF_GetError() << "\n";
		IMG_Quit();
		SDL_Quit();
		return (-3);
	}
	return (0);
}