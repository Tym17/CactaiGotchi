#pragma once

#ifndef STATEMACHINE_HPP_
# define STATEMACHINE_HPP_

# include "WindowSystem.hpp"

namespace cactaigotchi
{
	enum State
	{
		TITLE,
		HOWTO,
		GAME
	};

	class StateMachine
	{
		State	stateId;
		WindowSystem &win;

		void titleState();
		void howtoplayState();
		void gameState();

	public:
		StateMachine(WindowSystem &win);

		void render();
	};
};

#endif /* !STATEMACHINE_HPP_ */