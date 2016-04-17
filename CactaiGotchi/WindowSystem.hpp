#pragma once

#ifndef WINDOWSYSTEM_HPP_
# define WINDOWSYSTEM_HPP_

# include <SFML/Graphics.hpp>
# include "WindowSystem.hpp"

namespace cactaigotchi
{

	class WindowSystem
	{
	private:
		sf::Event event;

	public:
		sf::RenderWindow *it;

		WindowSystem();
		~WindowSystem();

		bool isOpen();
		bool pollEvent(sf::Event &event);
		void display();
		void clear();
	};
};

#endif /* !WINDOWSYSTEM_HPP_ */
