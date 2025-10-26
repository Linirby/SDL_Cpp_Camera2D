#include "camera.hpp"
#include <iostream>

Camera2D::Camera2D(SDL_Window *window)
{
	SDL_GetWindowSize(window, &window_size.x, &window_size.y);
	position = {0, 0};
	zoom = 1.0f;
}

Camera2D::~Camera2D() {}

SDL_FPoint Camera2D::world_to_screen_pos(SDL_FPoint world_position)
{
	SDL_FPoint	screen_pos;

	screen_pos.x = (world_position.x - position.x) * zoom + window_size.x / 2;
	screen_pos.y = (world_position.y - position.y) * zoom + window_size.y / 2;
	return (screen_pos);
}
