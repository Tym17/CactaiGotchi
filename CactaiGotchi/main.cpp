#include "WindowSystem.hpp"

int main(int ac, char **)
{

	cactaigotchi::WindowSystem win;

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (win.isOpen())
	{
		sf::Event event;
		while (win.pollEvent(event))
		{
		}

		win.clear();
		win.it->draw(shape);
		win.display();
	}
	return 0;
}