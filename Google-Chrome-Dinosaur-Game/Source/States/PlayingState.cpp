#include "PlayingState.h"


PlayingState::PlayingState(Game* game)
	: m_game(game),
	  io(ImGui::GetIO())
{
	default_font = io.Fonts->AddFontFromFileTTF("res/Fonts/Pixel/Thick-Pixel.ttf", 30);
	ImGui::SFML::UpdateFontTexture();

}

void PlayingState::handleInput()
{
	sf::Event e;

	while (m_game->window.pollEvent(e))
	{
		ImGui::SFML::ProcessEvent(e);

		switch (e.type)
		{
		case sf::Event::Closed:
			m_game->window.close();
			break;


		case sf::Event::KeyPressed:
			if (e.key.code == sf::Keyboard::Escape)
				m_game->window.close();
			break;
		}
	}
}

void PlayingState::render()
{
	ground.show(m_game->window);
	dino.show(m_game->window);
}

void PlayingState::update(float dt)
{
	dino.update(dt);
	ground.update(dt);
}

void PlayingState::renderGUI()
{
	
}