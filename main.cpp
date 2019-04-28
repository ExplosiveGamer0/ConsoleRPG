#include"Game.h"

int main()
{
	srand(static_cast<uint32_t>(time(NULL)));

	Game game;
	game.initGame();

	while (game.getPlaying())
	{
		game.mainMenu();
	}
	
	return 0;
}