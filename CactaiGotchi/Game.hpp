#pragma once

#ifndef GAME_HPP_
# define GAME_HPP_

# include <vector>
# include "WindowSystem.hpp"
# include "DrawHelper.hpp"
# include "SensitiveZone.hpp"

namespace cactaigotchi
{
	class Game
	{
		WindowSystem &win;
		DrawHelper helper;

		std::vector<sensitiveZone>	sensitiveAera;

		void clickTrigger(int x, int y);

	public:
		Game(WindowSystem &);

		void render();
		void tick();
	};
};

#endif /* !GAME_HPP_ */