#pragma once

#ifndef SENSITIVEZONE_HPP_
# define SENSITIVEZONE_HPP_

# include <SFML/System/Vector2.hpp>

namespace cactaigotchi
{
	class sensitiveZone
	{
	protected:
		int x;
		int y;
		int a;
		int b;
		int zoneId;

	public:
		sensitiveZone(int, int, int, int, int);
		sensitiveZone(const sensitiveZone &);
		sensitiveZone &operator=(const sensitiveZone &);

		bool isIn(int x, int y) const;

		// Pointers to member should much better
		int	 getZoneId(void) const;
	};
};

#endif /* !SENSITIVEZONE_HPP_ */