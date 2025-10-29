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
	velocity.x = 0;
	velocity.y = 0;
}

Entity::~Entity() {}

void Entity::handle_events(SDL_Event event)
{
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_l)
		{
			velocity.x = 300;
		}
		else if (event.key.keysym.sym == SDLK_j)
		{
			velocity.x = -300;
		}
		if (event.key.keysym.sym == SDLK_i)
		{
			velocity.y = -300;
		}
		else if (event.key.keysym.sym == SDLK_k)
		{
			velocity.y = 300;
		}
	}
}

void Entity::update(float fixed_dt)
{
	(void)fixed_dt;
	prev_pos = position;
	position.x += velocity.x * fixed_dt;
	position.y += velocity.y * fixed_dt;
}

void Entity::render(SDL_Renderer *renderer, Camera2D *camera, float alpha)
{
	SDL_FPoint	render_pos;
	SDL_FRect	render_rect;

	render_pos = lerp_point(prev_pos, position, alpha);
	render_pos = camera->world_to_screen_pos(render_pos);
	render_rect = {render_pos.x, render_pos.y, (float)width * camera->zoom, (float)height * camera->zoom};
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRectF(renderer, &render_rect);
}
