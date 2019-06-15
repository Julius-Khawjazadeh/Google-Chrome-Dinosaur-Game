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

	bool isAlive();

	void setAlive(bool ToF);
	void setPosition(sf::Vector2f pos);

	sf::FloatRect getGlobalBounds();
	sf::FloatRect getLocalBounds();
	sf::Vector2f getPosition();

private:
	float heightLimit;

private:
	bool alive;
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