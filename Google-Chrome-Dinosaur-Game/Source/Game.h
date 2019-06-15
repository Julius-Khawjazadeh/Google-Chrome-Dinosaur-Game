#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "States/StateBase.h"
#include "Info/DisplayInfo.h"

class Game
{
public:
	Game();
	~Game();

	void pushState(StateBase* newState);
	void popState();
	void gameLoop();

	std::vector<StateBase*> states;

	StateBase* activeState();
	sf::RenderWindow window;

private:


	sf::Clock clock;
};