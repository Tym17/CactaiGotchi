#pragma once

#ifndef GAME_HPP_
# define GAME_HPP_

# include <vector>
# include "WindowSystem.hpp"
# include "DrawHelper.hpp"
# include "SensitiveZone.hpp"

namespace cactaigotchi
{
	enum CactaiState
	{
		Water = 0x0088FF,
		Fire = 0xFF4422,
		Honey = 0xFFFF00,
		Air = 0xDDDDFF,
		Normal = 0x00FF00
	};

	class Game
	{
		WindowSystem &win;
		DrawHelper helper;

		std::vector<sensitiveZone>	sensitiveAera;

		void clickTrigger(int x, int y);

		/* Game data */
		CactaiState state;

		int hunger;
		int hp;
		int clean;

	public:
		Game(WindowSystem &);

		void render();
		void tick();
	};
};

#endif /* !GAME_HPP_ */