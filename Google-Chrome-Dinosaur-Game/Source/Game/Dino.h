#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "../Info/DisplayInfo.h"
#include "../Util/Animation.h"

class Dino
{
public:
	Dino();

	void update(float dt);
	void show(sf::RenderTarget& target);
	void logic();
	void jump();

private:
	float heightLimit;

private:
	bool canJump;
	bool walkingAnimation;
	float groundLevel;
	const float gravity;
	float velocityY;
	float jumpForce;

private:
	util::Animation dinoAnimation;
	sf::Sprite m_dino;
	sf::Texture m_dinoTexture;
};