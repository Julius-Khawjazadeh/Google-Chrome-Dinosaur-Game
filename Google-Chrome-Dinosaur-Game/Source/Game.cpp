#include "Game.h"


Game::Game()
{
	window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Google Chrome Dinosaur Game", sf::Style::Close);
	window.setVerticalSyncEnabled(true);
}

Game::~Game()
{
	while (!states.empty())
		popState();
}

void Game::pushState(StateBase* newState)
{
	states.push_back(newState);
}

void Game::popState()
{
	states.back();
	delete states.back();
	states.pop_back();
}

void Game::gameLoop()
{
	sf::Clock frameclock;

	sf::Time elapsed  = sf::Time::Zero;
	sf::Time timestep = sf::seconds(1.0f / (FPS));

	while (window.isOpen())
	{
		elapsed += frameclock.restart();
		
		if (activeState() == nullptr) {
			continue;
		}

		// Events and GUI
		activeState()->handleInput();
		activeState()->renderGUI();
		 
		// Timestep
		while (elapsed >= timestep) {
			elapsed -= timestep;
		}

		// Update
		activeState()->update(timestep.asSeconds());

		window.clear(sf::Color::White);

		// Render 
		activeState()->render();
	
		window.display();
	}
}

StateBase* Game::activeState()
{
	if (states.empty()) {
		return nullptr;
	}
	else {
		return states.back();
	}
}