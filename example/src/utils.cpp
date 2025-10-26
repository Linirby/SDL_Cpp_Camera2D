#include "utils.hpp"

SDL_FPoint lerp_point(SDL_FPoint &a, SDL_FPoint &b, float alpha)
{
	SDL_FPoint	result;

	result.x = (int)(a.x + (b.x - a.x) * alpha);
	result.y = (int)(a.y + (b.y - a.y) * alpha);
	return result;
}

float get_distance_point(SDL_FPoint &a, SDL_FPoint &b)
{
	float	dx;
	float	dy;

	dx = SDL_abs(a.x - b.x);
	dy = SDL_abs(a.y - b.y);
	return (sqrt(powf(dx, 2) + powf(dy, 2)));
}
