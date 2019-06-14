#pragma once


#include <SFML/Graphics.hpp>



namespace col
{
	class MouseCollision
	{
	public:
		static bool isMouseColliding(sf::RenderWindow& window, sf::Vector2f size, sf::Vector2f pos)
		{
			if (checkCollision(window, size, pos)) {
				return true;
			}

			return false;
		}
		
		static bool isMouseClicked(sf::Event e, sf::RenderWindow& window, sf::Vector2f size, sf::Vector2f pos)
		{
			switch (e.type)
			{
			case sf::Event::MouseButtonPressed:
				if (e.mouseButton.button == sf::Mouse::Left) {
					if (checkCollision(window, size, pos)) {
						return true;
					}

				}
			}

			return false;
		}

	private:		
		static bool checkCollision(sf::RenderWindow& window, sf::Vector2f size, sf::Vector2f pos)
		{
			sf::FloatRect range(pos, size);

			auto mouse_pos = sf::Mouse::getPosition(window);
			auto pixel_pos = window.mapPixelToCoords(mouse_pos);

			if (range.contains(pixel_pos)) {
				return true;
			}

			return false;
		}

	};
}

