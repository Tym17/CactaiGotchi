#include <iostream>
#include "Game.hpp"
#include "DrawHelper.hpp"

namespace cactaigotchi
{
	Game::Game(WindowSystem &_win) :
		win(_win), helper(_win)
	{
	}

	void Game::render()
	{
		DrawHelper helper(win);
		sf::Event event;
		
		while (win.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
				std::cout << "click even" << std::endl;
		}
	}

	void Game::tick()
	{
		std::cout << "tick" << std::endl;
	}
};