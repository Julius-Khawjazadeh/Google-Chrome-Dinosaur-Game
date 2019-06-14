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
	

}

void PlayingState::update(float dt)
{
	


}

void PlayingState::renderGUI()
{
	ImGui::PushFont(default_font);
	mainEngine.showFPS();
	ImGui::PopFont();
}