#pragma once

#ifndef ISTATE_HPP_
# define ISTATE_HPP_

namespace cactaigotchi
{
	class IState
	{
	public:
		virtual void render() = 0;
	};
};

#endif /* !ISTATE_HPP_ */
