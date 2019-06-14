#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "States/StateBase.h"
#include "Info/DisplayInfo.h"

#include "GUI/imgui.h"
#include "GUI/imgui_sfml/imgui-SFML.h"

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
	sf::Clock guiClock;
};