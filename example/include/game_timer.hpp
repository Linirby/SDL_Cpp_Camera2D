#pragma once

#include <SDL2/SDL.h>

class GameTimer
{
private:
	float	fixed_dt;
	float	accumulator;
	float	last_time;
	float	alpha;

public:
	GameTimer(float tick_per_second);
	~GameTimer();

	void	update();
	bool	can_fixed_update();
	void	consume_fixed_update();
	float	get_fixed_delta();
	float	get_alpha();
	void	frame_limiter(float fps);
};
