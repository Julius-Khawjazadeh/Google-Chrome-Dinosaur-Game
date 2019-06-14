#include "Dino.h"

Dino::Dino()
	: jumpForce(400),
	  gravity(30),
	  canJump(true),
	  walkingAnimation(true),
	  heightLimit(300)
{
	m_dinoTexture.loadFromFile("res/Images/Dino.png");
	dinoAnimation.setSettings(m_dinoTexture, { 3, 1 });

	m_dino.setTexture(m_dinoTexture);
	m_dino.setScale(2, 2);
	groundLevel = SCREEN_HEIGHT - m_dino.getLocalBounds().height * m_dino.getScale().y;
	m_dino.setPosition(m_dino.getLocalBounds().width * 2, groundLevel);
}

void Dino::jump()
{
	velocityY = -jumpForce;
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

void Dino::update(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && canJump) jump();
	logic();
	m_dino.move(0.0f, velocityY * dt);

	if (walkingAnimation) {
		if (dinoAnimation.timeReaches(100)) {
			dinoAnimation.currentImage.x++;
		}
		if (dinoAnimation.isLastImageX()) {
			dinoAnimation.currentImage.x = 0;
		}
	} else {
		dinoAnimation.currentImage.x = 0;
	}
}

void Dino::show(sf::RenderTarget& target)
{
	m_dino.setTextureRect(dinoAnimation.rect());
	target.draw(m_dino);
}

