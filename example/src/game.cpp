#include <SDL2/SDL.h>
#include <iostream>
#include "game.hpp"
#include "game_timer.hpp"

void Game::handle_events(SDL_Event event)
{
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			running = false;
		if (event.type == SDL_KEYDOWN)
		{
			// Not Good but working Control Camera

			// Move with arrows
			if (event.key.keysym.sym == SDLK_DOWN)
				test_camera->position.y += 10;
			else if (event.key.keysym.sym == SDLK_UP)
				test_camera->position.y -= 10;
			else if (event.key.keysym.sym == SDLK_RIGHT)
				test_camera->position.x += 10;
			else if (event.key.keysym.sym == SDLK_LEFT)
				test_camera->position.x -= 10;

			// Zoom In (Z) and Out (X)
			if (event.key.keysym.sym == SDLK_z)
				std::cout << "Zoom In!" << "\n";
			else if (event.key.keysym.sym == SDLK_x)
				std::cout << "Zoom Out!" << "\n";
		}
	}
}

void Game::update(float fixed_dt)
{
	test_entity->update(fixed_dt);
}

void Game::render(float alpha)
{
	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
	SDL_RenderClear(renderer);

	test_entity->render(renderer, test_camera, alpha);

	SDL_RenderPresent(renderer);
}

void Game::run()
{
	SDL_Event	event;
	GameTimer	game_timer(60);
	float		fixed_dt;
	float		alpha;

	fixed_dt = game_timer.get_fixed_delta();
	while (running)
	{
		game_timer.update();

		handle_events(event);

		while (game_timer.can_fixed_update())
		{
			update(fixed_dt);
			game_timer.consume_fixed_update();
		}

		alpha = game_timer.get_alpha();
		render(alpha);

		game_timer.frame_limiter(120);
	}
}

Game::Game()
{
	running = false;

	window = SDL_CreateWindow(
		"Template SDL Project - by Lili",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720,
		0
	);
	if (!window)
	{
		std::cerr << "Can't Create Window: " << SDL_GetError() << "\n";
		return ;
	}
	
	renderer = SDL_CreateRenderer(
		window, -1, SDL_RENDERER_ACCELERATED
	);
	if (!renderer)
	{
		std::cerr << "Can't Create Renderer: " << SDL_GetError() << "\n";
		SDL_DestroyWindow(window);
		return ;
	}

	test_entity = new Entity(0, 0, 32, 32, 220, 200, 50);
	test_camera = new Camera2D(window);

	running = true;
}

Game::~Game()
{
	delete test_camera;
	delete test_entity;
	if (renderer)
		SDL_DestroyRenderer(renderer);
	if (window)
		SDL_DestroyWindow(window);
}
