#pragma once

#include <SDL2/SDL.h>
#include "entity.hpp"
#include "camera.hpp"

class Game
{
private:
	SDL_Window		*window;
	SDL_Renderer	*renderer;

	Entity			*test_entity;
	Camera2D		*test_camera;

	bool			running;

	void	handle_events(SDL_Event event);
	void	update(float fixed_dt);
	void	render(float alpha);

public:
	Game();
	~Game();

	void	run();
};
