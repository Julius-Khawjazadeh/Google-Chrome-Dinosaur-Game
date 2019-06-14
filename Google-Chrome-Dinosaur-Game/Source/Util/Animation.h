#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

namespace util
{
	class Animation
	{
	public:
		Animation() = default;

		Animation(const sf::Texture& texture, sf::Vector2u entity)
			: m_entitys(entity)
		{
			m_entity.width = texture.getSize().x / m_entitys.x;
			m_entity.height = texture.getSize().y / m_entitys.y;
		}

		void setSettings(const sf::Texture& texture, sf::Vector2u entity)
		{
			m_entitys.x = entity.x;
			m_entitys.y = entity.y;

			m_entity.width = texture.getSize().x / (m_entitys.x);
			m_entity.height = texture.getSize().y / (m_entitys.y);
		}

		sf::IntRect getImageSpace()
		{
			return m_entity;
		}

		bool timeReaches(float max)
		{
			float timeValue = static_cast<float>(m_clock.getElapsedTime().asMilliseconds());

			if (timeValue >= max) {
				m_clock.restart();
				return true;
			}
			else {
				return false;
			}
		}

		bool isLastImageX()
		{
			if (currentImage.x >= m_entitys.x) {
				return true;
			}


			return false;
		}

		bool isLastImageY()
		{
			if (currentImage.y >= m_entitys.y) {
				return true;
			}

			return false;
		}

		sf::IntRect rect()
		{
			return sf::IntRect(currentImage.x * m_entity.width,
							   currentImage.y * m_entity.height,
							   m_entity.width,  m_entity.height);

		}

	public:
		sf::Vector2u currentImage;

	private:
		sf::Clock m_clock;
		sf::Vector2u m_entitys;
		sf::IntRect m_entity;
	};
}