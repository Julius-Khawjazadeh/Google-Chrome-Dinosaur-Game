#pragma once

#include <cstdlib>
#include <ctime>
#include <random>

namespace util
{
	class Random
	{
	public:
		int getIntInRange(int min, int max)
		{
			static bool pickSeeding = true;

			if (pickSeeding) {
				srand(time(NULL));
				pickSeeding = false;
			}

			int value = ((max + 1) - min);
			return min + rand() % value;
		}

		float getFloatInRange(float min, float max)
		{
			static bool pickSeeding = true;

			if (pickSeeding) {
				srand(time(NULL));
				pickSeeding = false;
			}

			float values = ((max - min) + min);
			return ((float)rand() / RAND_MAX) * values;
		}
	};
}