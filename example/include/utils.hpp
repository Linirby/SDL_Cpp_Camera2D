#pragma once

#include <SDL2/SDL.h>

SDL_FPoint	lerp_point(SDL_FPoint &a, SDL_FPoint &b, float alpha);
float		get_distance_point(SDL_FPoint &a, SDL_FPoint &b);
