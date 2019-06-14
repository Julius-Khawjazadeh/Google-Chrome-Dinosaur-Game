#include "Ground.h"

Ground::Ground()
{
	m_groundTexture.loadFromFile("res/Images/Ground.png");
	m_ground.setTexture(m_groundTexture);
	m_ground.setScale(2, 2);

	m_ground.setPosition(0, 
    SCREEN_HEIGHT - m_ground.getLocalBounds().height * m_ground.getScale().y);

	m_groundVec.push_back(m_ground);
}

void Ground::update(float dt)
{

	if (clock.getElapsedTime().asSeconds() > 2.5) {
		m_ground.setPosition(SCREEN_WIDTH, m_ground.getPosition().y);
		m_groundVec.push_back(m_ground);
		clock.restart();
	}

	for (int i = 0; i < m_groundVec.size(); i++) {
		if (m_groundVec[i].getPosition().x + 
		    m_groundVec[i].getLocalBounds().width *
			m_groundVec[i].getScale().x < 0) {
			m_groundVec.erase(m_groundVec.begin() + i);
		}
	}

	for (auto& ground : m_groundVec) {
		ground.move(-300 * dt, 0);
	}
}

void Ground::show(sf::RenderTarget& target)
{
	for (const auto& ground : m_groundVec) {
		target.draw(ground);
	}
}
