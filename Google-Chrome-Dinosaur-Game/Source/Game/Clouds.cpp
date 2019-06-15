#include "Clouds.h"

Clouds::Clouds()
	: spawnTime(3)
{
	randomSpawnPos = random.getIntInRange(0, SCREEN_HEIGHT / 2);
	
	m_cloudTexture.loadFromFile("res/Images/Cloud.png");
	m_cloud.setTexture(m_cloudTexture);
	m_cloud.setScale(2, 2);
	m_cloud.setPosition(SCREEN_WIDTH, randomSpawnPos);
}

void Clouds::reset()
{
	for (int i = 0; i < m_cloudVec.size(); i++) {
		while (m_cloudVec.size() != 0) {
			m_cloudVec.erase(m_cloudVec.begin() + i);
		}
	}
}

void Clouds::update(float dt)
{
	float elapsed = clock.getElapsedTime().asSeconds();

	if (elapsed >= spawnTime) {
		// Spawn a cloud
		randomSpawnPos = random.getIntInRange(0, SCREEN_HEIGHT / 2);
		m_cloud.setPosition(m_cloud.getPosition().x, randomSpawnPos);
		m_cloudVec.push_back(m_cloud);
		clock.restart();
	}

	for (auto& cloud : m_cloudVec) {
		cloud.move(-60 * dt, 0);
	}
}

void Clouds::show(sf::RenderTarget& target)
{
	for (auto& cloud : m_cloudVec) {
		target.draw(cloud);
	}
}