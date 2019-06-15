#include "Cactus.h"

Cactus::Cactus()
	: spawnTime(1),
	  cactusSpawn(0),
	  scaleX(2),
	  scaleY(2),
	  maxCactusPerSpawn(2),
	  minCactusPerSpawn(1)
{
	m_cactusTexture.loadFromFile("res/Images/BigCactus.png");
	m_cactus.setTexture(m_cactusTexture);

	m_cactus.setScale(scaleX, scaleY);
	groundLevel = SCREEN_HEIGHT - m_cactus.getGlobalBounds().height;
	m_cactus.setPosition(SCREEN_WIDTH, groundLevel);
}

sf::FloatRect Cactus::getGlobalBounds(int i)
{
	return m_cactusVec[i].getGlobalBounds();
}

sf::FloatRect Cactus::getLocalBounds(int i)
{
	return m_cactusVec[i].getLocalBounds();
}

sf::Vector2f Cactus::getPosition(int i)
{
	return m_cactusVec[i].getPosition();
}

int Cactus::allCactuses()
{
	return m_cactusVec.size();
}

void Cactus::reset()
{
	for (int i = 0; i < m_cactusVec.size(); i++) {
		while (m_cactusVec.size() != 0) {
			m_cactusVec.erase(m_cactusVec.begin() + i);
		}
	}
}

void Cactus::changeDifficulty()
{
	if (score > 50) {
		maxCactusPerSpawn = 3;
	}

	if (score > 100) {
		minCactusPerSpawn = 2;
		spawnTime = 0.8;
	}

	std::cout << maxCactusPerSpawn << std::endl;
}

void Cactus::update(float dt)
{

	if (clock.getElapsedTime().asSeconds() > spawnTime) {
		cactusSpawn = random.getIntInRange(minCactusPerSpawn, maxCactusPerSpawn);
		for (int i = 0; i < cactusSpawn; i++) {
			m_cactus.setPosition(i * (m_cactus.getGlobalBounds().width + 10) + SCREEN_WIDTH, m_cactus.getPosition().y);
			m_cactusVec.push_back(m_cactus);
		}
		clock.restart();
	}


	for (int i = 0; i < m_cactusVec.size(); i++) {
		if (m_cactusVec[i].getPosition().x +
			m_cactusVec[i].getLocalBounds().width *
			m_cactusVec[i].getScale().x < 0) {
			m_cactusVec.erase(m_cactusVec.begin() + i);
		}
	}

	changeDifficulty();

	if (isDinoAlive) {
		for (auto& cactus : m_cactusVec) {
			cactus.move(-moveSpeed * dt, 0);
		}
	} else {
		cactusSpawn = 0;
		maxCactusPerSpawn = 2;
		minCactusPerSpawn = 1;
		spawnTime = 1;
	}
}

void Cactus::show(sf::RenderTarget& target)
{
	for (auto& cactus : m_cactusVec) {
		target.draw(cactus);
	}
}