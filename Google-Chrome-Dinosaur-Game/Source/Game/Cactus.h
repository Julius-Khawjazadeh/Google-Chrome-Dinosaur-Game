#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Info/DisplayInfo.h"
#include "../Util/Animation.h"
#include "../Util/Random.h"
#include "MovingObject.h"

class Cactus : public MovingObject
{
public:
	Cactus();

	void update(float dt);
	void show(sf::RenderTarget& target);
	void reset();
	int allCactuses();

	int score;
	
	sf::FloatRect getGlobalBounds(int i);
	sf::FloatRect getLocalBounds(int i);
	sf::Vector2f  getPosition(int i);

	bool isDinoAlive;

private:
	float groundLevel;
	float spawnTime;
	float scaleX;
	float scaleY;

	int cactusSpawn;
	int maxCactusPerSpawn;
	int minCactusPerSpawn;
	
private:
	void changeDifficulty();

private:
	sf::Clock clock;

private:
	util::Random random;
	util::Animation CactusAnimation;

	std::vector<sf::Sprite> m_cactusVec;
	sf::Sprite m_cactus;
	sf::Texture m_cactusTexture;

};