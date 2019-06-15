#include "PlayingState.h"


PlayingState::PlayingState(Game* game)
	: m_game(game),
 	  resetGame(false),
	  score(0)
{
	gameOverTexture.loadFromFile("res/Images/GameOver.png");
	gameOverImage.setTexture(gameOverTexture);

	gameOverImage.setScale(3, 3);

	scoreFont.loadFromFile("res/Fonts/Pixel/Thick-Pixel.ttf");
	scoreText.setFont(scoreFont);

	scoreText.setCharacterSize(20);
	scoreText.setFillColor({64, 64, 64});

	
	gameOverImage.setPosition(SCREEN_WIDTH  / 2 - 
		                     (gameOverImage.getLocalBounds().width  / 2 * gameOverImage.getScale().x),
		                      SCREEN_HEIGHT / 2 - 
		                     (gameOverImage.getLocalBounds().height / 2 * gameOverImage.getScale().y));

}

void PlayingState::handleInput()
{
	sf::Event e;

	while (m_game->window.pollEvent(e))
	{
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
	cactus.show(m_game->window);
	clouds.show(m_game->window);
	dino.show(m_game->window);
	
	if (!dino.isAlive()) {
		m_game->window.draw(gameOverImage);
	}

	scoreText.setString(std::to_string((int)(score)));
	scoreText.setPosition(SCREEN_WIDTH / 2 - (scoreText.getLocalBounds().width / 2), 0);	
	m_game->window.draw(scoreText);
}


void PlayingState::update(float dt)
{
	dino.update(dt);
	cactus.update(dt);
	clouds.update(dt);


	for (int i = 0; i < cactus.allCactuses(); i++) {
		if (dino.getGlobalBounds().intersects(cactus.getGlobalBounds(i)))
		{
			// Collision between dinosaur and cactus
			dino.setAlive(false);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !dino.isAlive()) {
		// Reset the game if enter is pressed
		score = 0;
		dino.setAlive(true);
		cactus.reset();
		clouds.reset();
	}

	cactus.isDinoAlive = dino.isAlive();

	if (dino.isAlive()) {
		score += 0.1;
	}

	cactus.score = score;
}

void PlayingState::renderGUI()
{

}