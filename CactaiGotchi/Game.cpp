#include <iostream>
#include "Game.hpp"
#include "DrawHelper.hpp"

namespace cactaigotchi
{
	Game::Game(WindowSystem &_win) :
		win(_win), helper(_win)
	{
		sensitiveAera.push_back(sensitiveZone(0, 0, 100, 100, 1));
	}

	void Game::render()
	{
		DrawHelper helper(win);
		sf::Event event;
		
		while (win.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				std::cout << "click even" << std::endl;
				clickTrigger(event.mouseButton.x, event.mouseButton.y);
			}
		}
	}

	void Game::clickTrigger(int x, int y)
	{
		for (std::vector<sensitiveZone>::iterator it = sensitiveAera.begin();
			it != sensitiveAera.end(); ++it)
		{
			if (it->isIn(x, y))
			{
				// Should change this to a pointer to member thing inside
				std::cout << "ActiveArea :" << it->getZoneId() << std::endl;
			}
		}
	}

	void Game::tick()
	{
		std::cout << "tick" << std::endl;
	}
};