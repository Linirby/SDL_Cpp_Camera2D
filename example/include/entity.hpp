#pragma once

#include <SDL2/SDL.h>
#include "camera.hpp"

class Entity
{
private:
	SDL_FPoint	prev_pos;
	SDL_FPoint	position;
	int			width;
	int			height;
	SDL_Color	color;
public:
	Entity(float x, float y, int width, int height, Uint8 r, Uint8 g, Uint8 b);
	~Entity();

	void	update(float fixed_dt);
	void	render(SDL_Renderer *renderer, Camera2D *camera, float alpha);
};
