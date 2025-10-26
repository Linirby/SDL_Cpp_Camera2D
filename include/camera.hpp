#pragma once

#include <SDL2/SDL.h>
#include "utils.hpp"

class Camera2D
{
private:
	SDL_Point	window_size;

public:
	SDL_Point	position;
	float		zoom;

	Camera2D(SDL_Window *window);
	~Camera2D();

	SDL_FPoint	world_to_screen_pos(SDL_FPoint world_position);
};
