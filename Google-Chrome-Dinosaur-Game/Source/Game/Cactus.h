#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Info/DisplayInfo.h"
#include "../Util/Animation.h"
#include "MovingObject.h"

class Cactus : public MovingObject
{
public:
	Cactus();

	void update(float dt);
	void show(sf::RenderTarget& target);
	
private:
	float groundLevel;

private:
	sf::Clock clock;

private:

	util::Animation CactusAnimation;

	std::vector<sf::Sprite> m_cactusVec;
	sf::Sprite m_cactus;
	sf::Texture m_cactusTexture;

};