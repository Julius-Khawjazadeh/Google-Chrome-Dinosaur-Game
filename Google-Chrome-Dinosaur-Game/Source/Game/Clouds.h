#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Info/DisplayInfo.h"
#include "../Util/Random.h"

class Clouds
{
public:
	Clouds();

	void update(float dt);
	void show(sf::RenderTarget& target);
	void reset();

private:
	float spawnTime;
	float randomSpawnPos;

private:
	sf::Clock clock;
	util::Random random;

private:
	std::vector<sf::Sprite> m_cloudVec;
	sf::Sprite m_cloud;
	sf::Texture m_cloudTexture;
};