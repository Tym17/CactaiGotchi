#pragma once

#ifndef ISTATE_HPP_
# define ISTATE_HPP_

# include "WindowSystem.hpp"

namespace cactaigotchi
{
	class IState
	{
	public:
		virtual int render(WindowSystem &) = 0;
	};
};

#endif /* !ISTATE_HPP_ */
