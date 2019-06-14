#include <iostream>

#include "States/PlayingState.h"
#include "Game.h"


int main()
{
	Game game;
	game.pushState(new PlayingState(&game));
	game.gameLoop();
}