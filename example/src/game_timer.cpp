#include "game_timer.hpp"

GameTimer::GameTimer(float tick_per_second)
{
	fixed_dt = 1.0f / tick_per_second;
	accumulator = 0;
	last_time = (float)SDL_GetPerformanceCounter() / (float)SDL_GetPerformanceFrequency();
	alpha = 0;
}

GameTimer::~GameTimer() {}

void GameTimer::update()
{
	float	now;
	float	frame_time;

	now = (float)SDL_GetPerformanceCounter() / (float)SDL_GetPerformanceFrequency();
	frame_time = now - last_time;
	last_time = now;
	accumulator += frame_time;
}

bool GameTimer::can_fixed_update()
{
	return (accumulator >= fixed_dt);
}

void GameTimer::consume_fixed_update()
{
	accumulator -= fixed_dt;
}

/* Useful for physics updates */
float GameTimer::get_fixed_delta()
{	
	return (fixed_dt);
}

/* Useful for smooth rendering */
float GameTimer::get_alpha()
{
	return (accumulator / fixed_dt);
}

/* Useful to avoid burning CPU */
void GameTimer::frame_limiter(float fps)
{
	Uint64	frame_end;
	float	elapsed;
	Uint32	delay_ms;
	float	target_frame_time;

	frame_end = SDL_GetPerformanceCounter();
	elapsed = (frame_end - last_time) / (float)SDL_GetPerformanceFrequency();
	target_frame_time = 1.0 / fps;
	if (elapsed < target_frame_time)
	{
		delay_ms = (Uint32)((target_frame_time - elapsed) * 1000.0f);
		SDL_Delay(delay_ms);
	}
}
