#include <iostream>
#include "WindowSystem.hpp"

namespace cactaigotchi
{
	WindowSystem::WindowSystem()
	{
		try {
			it = new sf::RenderWindow(sf::VideoMode(700, 600), "CactaiGotchi v1.0.0 - Tym17.com", sf::Style::Close);
		}
		catch (std::bad_alloc e)
		{
			std::cout << "Could not create window" << std::endl;
		}
		sf::Image img;
		if (!img.loadFromFile("img/cactaifood.png"))
		{
			std::cerr << "Could not open icon." << std::endl;
		}
		it->setIcon(64, 64, img.getPixelsPtr());
		it->setFramerateLimit(60);
	}

	WindowSystem::~WindowSystem()
	{
		it->close();
		delete it;
	}

	bool WindowSystem::isOpen()
	{
		return it->isOpen();
	}

	bool WindowSystem::pollEvent(sf::Event &event)
	{
		bool ret;

		ret = it->pollEvent(event);
		if (event.type == sf::Event::Closed)
			it->close();
		return ret;
	}

	void WindowSystem::display()
	{
		it->display();
	}

	void WindowSystem::clear()
	{
		it->clear();
	}


};