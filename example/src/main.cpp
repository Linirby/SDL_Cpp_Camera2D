#include "game.hpp"
#include "sdl_init.hpp"

int main(int argc, char *argv[])
{
	Game	*game = new Game();;

	if (sdl_init() != 0)
		return (-1);
	if (!game)
		return (-2);

	game->run();
	delete game;

	(void)argc;
	(void)argv;
	return (0);
}
