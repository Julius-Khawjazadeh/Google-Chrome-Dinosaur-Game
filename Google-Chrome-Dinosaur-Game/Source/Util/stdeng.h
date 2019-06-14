#include <iostream>
#include <SFML/Graphics.hpp>

#include "../GUI/imgui.h"
#include "../GUI/imgui_sfml/imgui-SFML.h"
#include "../GUI/DefaultGuiSettings.h"


// standard engine includes basic stuff like time and more

namespace eng
{
	class stdeng
	{
	public:
		float getFPS();

		void showFPS();

	private:
		sf::Clock clock;
		float lastTime;
	};

	float pixels(float value);
	float scalarPixels(float value);

}