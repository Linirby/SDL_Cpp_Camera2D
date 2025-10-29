#pragma once

#include <SDL2/SDL.h>
#include "utils.hpp"

class Camera2D
{
private:
	SDL_Point	window_size;

public:
	SDL_FPoint	position;
	float		zoom;
	int			has_target;

	Camera2D(SDL_Window *window);
	~Camera2D();

	void		follow_pos(SDL_FPoint target, float fixed_dt);
	SDL_FPoint	world_to_screen_pos(SDL_FPoint world_position);
};
