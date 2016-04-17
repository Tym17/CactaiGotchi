#include "SensitiveZone.hpp"

namespace cactaigotchi
{
	sensitiveZone::sensitiveZone(int x, int y, int a, int b, int zoneId) :
		x(x), y(y), a(a), b(b), zoneId(zoneId)
	{
	}

	sensitiveZone::sensitiveZone(const sensitiveZone &o) :
		x(o.x), y(o.y), a(o.a), b(o.b), zoneId(o.zoneId)
	{
	}

	sensitiveZone &sensitiveZone::operator=(const sensitiveZone &o)
	{
		x = o.x;
		y = o.y;
		a = o.a;
		b = o.b;
		zoneId = o.zoneId;
		return *this;
	}

	bool sensitiveZone::isIn(int ix, int iy) const
	{
		if ((ix >= x && ix <= a) && (iy >= y && iy <= b))
			return true;
		return false;
	}

	int sensitiveZone::getZoneId() const
	{
		return zoneId;
	}
};