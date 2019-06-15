#pragma once

#include "../Game.h"
#include "StateBase.h"
#include "../Util/Animation.h"

#include "../Mouse/MouseCollision.h"
#include "../Util/stdeng.h"
#include "../Game/Dino.h"
#include "../Game/Cactus.h"
#include "../Game/MovingObject.h"
#include "../Game/Clouds.h"


class PlayingState : public StateBase
{
public:
	PlayingState(Game* game);

	virtual void handleInput();
	virtual void update(float dt);
	virtual void render();
	virtual void renderGUI();

	bool resetGame;

	float score;

private:
	Clouds clouds;
	Dino dino;
	Cactus cactus;

private:
	sf::Sprite gameOverImage;
	sf::Texture gameOverTexture;

private:
	sf::Font scoreFont;
	sf::Text scoreText;

	Game* m_game;
	eng::stdeng mainEngine;
};
