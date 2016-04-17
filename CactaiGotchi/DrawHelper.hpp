#ifndef DRAWHELPER_HPP_
# define DRAWHELPER_HPP_

# include "WindowSystem.hpp"

namespace cactaigotchi
{
	class DrawHelper
	{
		WindowSystem &win;
		sf::Font OpenSans;
		bool canText;

	public:
		DrawHelper(WindowSystem &);
		
		void drawImage(int , int, const char *);
		void drawImage(int, int, const char *, int color);
		void drawImage(int, int, const char *, int color, float);

		void drawText(int, int, const char *);
		void drawBar(int, int, int len, int actual, int max, int colorFull, int colorEmpty);
	};
};

#endif /* !DRAWHELPER_HPP_*/