#include <iostream>
#include "Game.hpp"

namespace cactaigotchi
{
	namespace Game
	{
		void Tick(WindowSystem &win)
		{
			sf::Event event;
			while (win.pollEvent(event))
			{
				if (event.type == sf::Event::MouseButtonPressed)
					std::cout << "click even" << std::endl;
			}
		}
	};
};