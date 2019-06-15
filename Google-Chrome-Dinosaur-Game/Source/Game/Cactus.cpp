#include "Cactus.h"

Cactus::Cactus()
{
	m_cactusTexture.loadFromFile("res/Images/BigCactus.png");
	m_cactus.setTexture(m_cactusTexture);

	m_cactus.setScale(2, 2);
	groundLevel = SCREEN_HEIGHT - (m_cactus.getLocalBounds().height * m_cactus.getScale().y) * 1.3;
	m_cactus.setPosition(SCREEN_WIDTH, groundLevel);
}

void Cactus::update(float dt)
{
	if (clock.getElapsedTime().asSeconds() > 2) {
		m_cactusVec.push_back(m_cactus);
		clock.restart();
	}

	for (int i = 0; i < m_cactusVec.size(); i++) {
		if (m_cactusVec[i].getPosition().x +
			m_cactusVec[i].getLocalBounds().width *
			m_cactusVec[i].getScale().x < 0) {
			m_cactusVec.erase(m_cactusVec.begin() + i);
		}
	}

	std::cout << m_cactusVec.size() << std::endl;


	for (auto& cactus : m_cactusVec) {
		cactus.move(-moveSpeed * dt, 0);
	}
}

void Cactus::show(sf::RenderTarget& target)
{
	for (auto& cactus : m_cactusVec) {
		target.draw(cactus);
	}
}