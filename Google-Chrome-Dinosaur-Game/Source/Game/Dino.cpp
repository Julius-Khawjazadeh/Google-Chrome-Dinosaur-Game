#include "Dino.h"

Dino::Dino()
	: jumpForce(400),
	  gravity(30),
	  canJump(true),
	  heightLimit(300)
{
	m_dino.setSize({ 60, 60 });
	m_dino.setFillColor(sf::Color::Black);
	groundLevel = SCREEN_HEIGHT - m_dino.getSize().y;
	m_dino.setPosition(m_dino.getSize().x * 2, groundLevel);
}

void Dino::jump()
{
	velocityY = -jumpForce;
}

void Dino::logic()
{

	if (m_dino.getPosition().y < groundLevel || velocityY < 0) {
		velocityY += gravity;
	} else {
		canJump = true;
		m_dino.setPosition(m_dino.getPosition().x, groundLevel);
		velocityY = 0;
	}

	if (m_dino.getPosition().y + m_dino.getSize().y < heightLimit) {
		canJump = false;
	}
}

void Dino::update(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && canJump) jump();

	logic();
	m_dino.move(0.0f, velocityY * dt);
}

void Dino::show(sf::RenderTarget& target)
{
	target.draw(m_dino);
}

