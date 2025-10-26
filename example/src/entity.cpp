#include <iostream>
#include "entity.hpp"
#include "utils.hpp"
#include "camera.hpp"

Entity::Entity(float x, float y, int width, int height, Uint8 r, Uint8 g, Uint8 b)
{
	position = {x, y};
	prev_pos = position;
	this->width = width;
	this->height = height;
	color = {r, g, b, 255};
}

Entity::~Entity() {}

void Entity::update(float fixed_dt)
{
	(void)fixed_dt;
	prev_pos = position;
	// position.x += 300 * fixed_dt;
	// position.y += 165 * fixed_dt;
}

void Entity::render(SDL_Renderer *renderer, Camera2D *camera, float alpha)
{
	SDL_FPoint	render_pos;
	SDL_FRect	render_rect;

	render_pos = lerp_point(prev_pos, position, alpha);
	render_pos = camera->world_to_screen_pos(render_pos);
	render_rect = {render_pos.x, render_pos.y, (float)width, (float)height};
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRectF(renderer, &render_rect);
}
