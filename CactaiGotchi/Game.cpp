#include <iostream>
#include "Game.hpp"
#include "DrawHelper.hpp"
#include "Config.hpp"

namespace cactaigotchi
{
	Game::Game(WindowSystem &_win) :
		win(_win), helper(_win)
	{
		state = Normal;
		sensitiveAera.push_back(sensitiveZone(0, WIN_Y - 51, 51, WIN_Y, 1));
		sensitiveAera.push_back(sensitiveZone(52, WIN_Y - 51, 103, WIN_Y, 2));
		sensitiveAera.push_back(sensitiveZone(104, WIN_Y - 51, 155, WIN_Y, 3));
		sensitiveAera.push_back(sensitiveZone(156, WIN_Y - 51, 208, WIN_Y, 4));
	}

	void Game::render()
	{
		DrawHelper helper(win);
		sf::Event event;
		
		while (win.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				clickTrigger(event.mouseButton.x, event.mouseButton.y);
			}
		}
		helper.drawImage(0, WIN_Y - 51, "img/droplets.png", 0x55AAFF, 0.10f);
		helper.drawImage(52, WIN_Y - 51, "img/dripping-honey.png", 0xD3A308, 0.10f);
		helper.drawImage(104, WIN_Y - 51, "img/flame.png", 0xFF6611, 0.10f);
		helper.drawImage(156, WIN_Y - 51, "img/fluffy-cloud.png", 0xEEEEFF, 0.10f);

		static int cycles = 0;
		static bool still = false;
		static const char *cactai = "img/cactstill1grey.png";
		if (cycles % 6 == 0)
		{
			if (still)
			{
				cactai = "img/cactstill1grey.png";
				still = false;
			}
			else
			{
				cactai = "img/cactstill2grey.png";
				still = true;
			}
			cycles = 0;
		}
		++cycles;

		helper.drawImage(WIN_X / 2, WIN_Y / 2, cactai, state);
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
				switch (it->getZoneId())
				{
				case 1:
					state = Water;
					break;
				case 2:
					state = Honey;
					break;
				case 3:
					state = Fire;
					break;
				case 4:
					state = Air;
					break;
				default:
					break;
				}
			}
		}
	}

	void Game::tick()
	{
		std::cout << "tick" << std::endl;
	}
};