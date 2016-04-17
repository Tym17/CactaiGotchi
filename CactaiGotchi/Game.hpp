#pragma once

#ifndef GAME_HPP_
# define GAME_HPP_

# include "WindowSystem.hpp"
# include "DrawHelper.hpp"

namespace cactaigotchi
{
	class Game
	{
		WindowSystem &win;
		DrawHelper helper;

	public:
		Game(WindowSystem &);

		void render();
		void tick();
	};
};

#endif /* !GAME_HPP_ */