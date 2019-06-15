#include "Dino.h"

Dino::Dino()
	: jumpForce(500),
	  gravity(40),
	  canJump(true),
	  walkingAnimation(true),
	  heightLimit(160),
	  alive(true)
{
	m_dinoTexture.loadFromFile("res/Images/Dino.png");

	m_dino.setTexture(m_dinoTexture);
	m_dino.setScale(2, 2);
	groundLevel = SCREEN_HEIGHT - m_dino.getGlobalBounds().height;
	dinoAnimation.setSettings(m_dinoTexture, { 4, 1 });
	m_dino.setPosition((m_dino.getGlobalBounds().width / 3), groundLevel);
}

void Dino::setPosition(sf::Vector2f pos)
{
	m_dino.setPosition(pos);
}

sf::Vector2f Dino::getPosition()
{
	return m_dino.getPosition();
}

sf::FloatRect Dino::getGlobalBounds()
{
	return m_dino.getGlobalBounds();
}

sf::FloatRect Dino::getLocalBounds()
{
	return m_dino.getLocalBounds();
}

void Dino::jump()
{
	velocityY = -jumpForce;
}

void Dino::setAlive(bool ToF)
{
	alive = ToF;
}

void Dino::logic()
{
	// add gravity if player is jumping
	if (m_dino.getPosition().y < groundLevel || velocityY < 0) {
		velocityY += gravity;
		walkingAnimation = false;
	} else {
		// else: set it on the ground
		walkingAnimation = true;
		canJump = true;
		m_dino.setPosition(m_dino.getPosition().x, groundLevel);
		velocityY = 0;
	}

	if (m_dino.getPosition().y + m_dino.getLocalBounds().height < heightLimit) {
		canJump = false;
	}
}

bool Dino::isAlive()
{
	return alive;
}

void Dino::update(float dt)
{
	if (isAlive()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && canJump)    jump();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump) jump();
		logic();
		m_dino.move(0.0f, velocityY * dt);


		if (walkingAnimation) {
			if (dinoAnimation.timeReaches(80)) {
				dinoAnimation.currentImage.x++;
			}
			if (dinoAnimation.currentImage.x > 2) {
				dinoAnimation.currentImage.x = 0;
			}
		} else {
			dinoAnimation.currentImage.x = 0;
		}
	} else {
		dinoAnimation.currentImage.x = 3;
	}
}

void Dino::show(sf::RenderTarget& target)
{
	m_dino.setTextureRect(dinoAnimation.rect());
	target.draw(m_dino);
}

