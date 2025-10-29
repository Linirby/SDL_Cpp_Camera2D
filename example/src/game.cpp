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
			if (!test_camera->has_target)
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
			}

			// Zoom In (Z) and Out (X)
			if (event.key.keysym.sym == SDLK_z)
			{
				test_camera->zoom += 0.01;
			}
			else if (event.key.keysym.sym == SDLK_x)
			{
				test_camera->zoom -= 0.01;
			}

			// Next target (N) Previous (B)
			if (event.key.keysym.sym == SDLK_b)
			{
				--target_entity;
				if (target_entity < 0)
				{
					target_entity = 4;
				}
				
			}
			if (event.key.keysym.sym == SDLK_n)
			{
				++target_entity;
				if (target_entity > 4)
				{
					target_entity = 0;
				}
			}

			// Swap Target Mode
			if (event.key.keysym.sym == SDLK_LSHIFT)
			{
				++test_camera->has_target;
				if (test_camera->has_target > 1)
				{
					test_camera->has_target = 0;
				}
			}
		}
		entities[0]->handle_events(event);
	}
}

void Game::update(float fixed_dt)
{
	size_t	entity_index = 0;
	while (entity_index < entities.size())
	{
		entities[entity_index]->update(fixed_dt);
		++entity_index;
	}
	test_camera->follow_pos(entities[target_entity]->position, fixed_dt);
}

void Game::render(float alpha)
{
	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
	SDL_RenderClear(renderer);

	size_t	entity_index = 0;
	while (entity_index < entities.size())
	{
		entities[entity_index]->render(renderer, test_camera, alpha);
		++entity_index;
	}

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

	entities.insert(entities.end(), new Entity(0, 0, 64, 64, 255, 0, 0));
	entities.insert(entities.end(), new Entity(100, 100, 64, 64, 0, 255, 0));
	entities.insert(entities.end(), new Entity(-250, -300, 64, 64, 0, 0, 255));
	entities.insert(entities.end(), new Entity(500, -250, 64, 64, 255, 255, 0));
	entities.insert(entities.end(), new Entity(-300, 200, 64, 64, 0, 255, 255));

	test_camera = new Camera2D(window);
	target_entity = 0;

	running = true;
}

Game::~Game()
{
	size_t	entity_index = 0;
	while (entity_index < entities.size())
	{
		delete entities[entity_index];
		++entity_index;
	}
	entities.clear();

	delete test_camera;

	if (renderer)
		SDL_DestroyRenderer(renderer);
	if (window)
		SDL_DestroyWindow(window);
}
