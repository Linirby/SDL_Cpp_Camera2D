#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "entity.hpp"
#include "camera.hpp"

class Game
{
private:
	SDL_Window				*window;
	SDL_Renderer			*renderer;

	std::vector<Entity *>	entities;
	Camera2D				*test_camera;
	int						target_entity;

	bool			running;

	void	handle_events(SDL_Event event);
	void	update(float fixed_dt);
	void	render(float alpha);

public:
	Game();
	~Game();

	void	run();
};
