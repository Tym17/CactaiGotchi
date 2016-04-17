#include <iostream>
#include "Game.hpp"
#include "DrawHelper.hpp"
#include "Config.hpp"

namespace cactaigotchi
{
	Game::Game(WindowSystem &_win) :
		win(_win), gameOver(false), helper(_win)
	{
		state = Normal;
		hunger = 100;
		hp = 100;
		clean = 100;
		score = 0;
		lastFed = Normal;
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
				if (gameOver)
				{
					lastFed = Normal;
					state = Normal;
					hunger = 100;
					hp = 100;
					clean = 100;
					score = 0;
					gameOver = false;
				}
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
		helper.drawBar(WIN_X - 110, WIN_Y - 20, 100, hp, 100, 0x33FF33, 0xFF3333);
		helper.drawBar(WIN_X - 110, WIN_Y - 40, 100, hunger, 100, 0xFFDD33, 0xAA8800);
		helper.drawBar(WIN_X - 110, WIN_Y - 60, 100, clean, 100, 0x33FFFF, 0xAAAAAA);
		helper.drawText(WIN_X - 90, WIN_Y - 19, "Health", 11);
		helper.drawText(WIN_X - 90, WIN_Y - 39, "Hungerness", 11);
		helper.drawText(WIN_X - 90, WIN_Y - 59, "Cleaniness", 11);
		helper.drawImage(14, 28, "img/cactaifood.png");
		helper.drawText(5, 22, "x", 30);
		helper.drawText(5, 1, std::to_string(score).c_str(), 30);
		if (gameOver)
			helper.drawImage(0, 0, "img/gameover.png");

	}

	void Game::clickTrigger(int x, int y)
	{
		if (gameOver)
			return;
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
					feedWater();
					break;
				case 2:
					feedHoney();
					break;
				case 3:
					feedFire();
					break;
				case 4:
					feedAir();
					break;
				default:
					break;
				}
				if (hunger >= 100)
					hunger = 100;
				if (clean >= 100)
					clean = 100;
				if (hp >= 100)
					hp = 100;
				if (hp <= 0)
				{
					gameOver = true;
					hp = 0;
				}
			}
		}
	}

	void Game::tick()
	{
		if (gameOver)
			return;
		std::cout << "tick" << std::endl;
		static int cycles = 0;

		if (cycles % 3 == 0)
		{
			if (hunger >= 80)
				hunger -= 1;
			else
				hunger -= 2;
			if (clean <= 0)
				hunger -= 3;
			if (hunger <= 0)
			{
				hp -= 1;
				hunger = 0;
			}
		}

		if (cycles % 8 == 0)
		{
			if (clean >= 60)
				clean -= 1;
			else if (clean >= 40)
				clean -= 2;
			else
				clean -= 6;
			if (clean <= 0)
			{
				hp -= 10;
				clean = 0;
			}
		}

		if (hp <= 0)
		{
			hp = 0;
			gameOver = true;
		}

		if (cycles % 150 == 0)
		{
			if (!gameOver)
				score++;
			cycles = 0;
		}
		++cycles;
	}

	void Game::feedAir()
	{
		if (state == Normal)
		{
			clean += 10;
			hunger -= 2;
		}
		else if (state == Water)
		{
			clean += 3;
			hp -= 4;
		}
		else if (state == Fire)
		{
			hp -= 60;
			if (lastFed == Fire)
				state = Fire;
		}
		else if (state == Air)
		{
			hp += 15;
			clean -= 10;
		}
		else if (state == Honey)
		{
			clean += 6;
			hunger -= 3;
		}
		lastFed = Air;
	}

	void Game::feedFire()
	{
		if (state == Normal)
		{
			hp -= 10;
			if (lastFed == Fire)
				state = Fire;
		}
		else if (state == Water)
		{
			hp -= 2;
			if (lastFed == Fire)
				state = Air;
		}
		else if (state == Fire)
		{
			hunger += 10;
			hp -= 1;
		}
		else if (state == Air)
		{
			clean -= 10;
			if (lastFed == Honey)
				state = Normal;
		}
		else if (state == Honey)
		{
			clean += 15;
			hp -= 14;
			if (lastFed == Fire)
				state == Water;
		}
		lastFed = Fire;
	}

	void Game::feedHoney()
	{
		if (state == Normal)
		{
			hunger += 12;
			clean -= 25;
			if (lastFed == Water)
				state = Honey;
		}
		else if (state == Water)
		{
			hunger += 2;
			clean -= 25;
			if (lastFed == Honey)
				state = Honey;
		}
		else if (state == Fire)
		{
			clean -= 17;
			if (lastFed == Honey)
				state = Normal;
		}
		else if (state == Air)
		{
			hunger += 10;
			clean -= 2;
			if (lastFed == Water)
				state = Honey;
			if (lastFed == Honey)
				state = Normal;
		}
		else if (state == Honey)
		{
			hunger += 10;
			hp += 2;
			clean -= 13;
		}
		lastFed = Honey;
	}

	void Game::feedWater()
	{
		if (state == Normal)
		{
			hunger += 5;
			clean -= 2;
			if (lastFed == Water)
				state = Water;
		}
		else if (state == Water)
		{
			hunger += 5;
			clean -= 5;
		}
		else if (state == Fire)
		{
			hp -= 5;
			clean += 10;
			if (lastFed == Air)
				state = Air;
		}
		else if (state == Air)
		{
			clean += 10;
			hunger -= 3;
			if (lastFed == Honey)
				state == Normal;
		}
		else if (state == Honey)
		{
			hp += 1;
			clean += 3;
			if (lastFed == Air)
				state = Water;
		}
		lastFed = Water;
	}
};