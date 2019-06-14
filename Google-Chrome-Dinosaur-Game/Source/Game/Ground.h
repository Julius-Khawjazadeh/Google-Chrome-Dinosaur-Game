#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "../Info/DisplayInfo.h"
#include "../Util/Animation.h"

class Ground
{
public:
	Ground();

	void update(float dt);
	void show(sf::RenderTarget& target);

private:
	int groundCount = 0;

private:
	sf::Clock clock;
	std::vector<sf::Sprite> m_groundVec;

	sf::Sprite m_ground;
	sf::Texture m_groundTexture;
};