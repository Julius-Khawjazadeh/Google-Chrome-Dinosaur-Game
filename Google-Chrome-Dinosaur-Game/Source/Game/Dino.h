#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "../Info/DisplayInfo.h"

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
	float groundLevel;
	const float gravity;
	float velocityY;
	float jumpForce;

private:
	sf::RectangleShape m_dino;
};