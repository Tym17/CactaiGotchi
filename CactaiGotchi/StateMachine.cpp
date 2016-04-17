#include <iostream>
#include <SFML/Window/Event.hpp>
#include "StateMachine.hpp"
#include "Game.hpp"

namespace cactaigotchi
{

	StateMachine::StateMachine(WindowSystem &_win) :
			stateId(TITLE), win(_win), game(_win)
	{
	}

	void StateMachine::render()
	{
		if (stateId == TITLE)
		{
			titleState();
		}
		else if (stateId == HOWTO)
		{
			howtoplayState();
		}
		else if (stateId == GAME)
		{
			gameState();
		}
	}

	void StateMachine::titleState()
	{
		sf::Texture texture;

		if (!texture.loadFromFile("img/title.png"))
		{
			std::cout << "Could not open texture" << std::endl;
			return;
		}
		sf::Event event;

		while (win.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
				stateId = HOWTO;
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
					stateId = HOWTO;
				else if (event.key.code == sf::Keyboard::Tab)
					stateId = GAME;
			}
		}
		sf::Sprite sprite;
		sprite.setTexture(texture);
		win.it->draw(sprite);
		clock.restart();
	}

	void StateMachine::howtoplayState()
	{
		sf::Texture texture;

		if (!texture.loadFromFile("img/howto.png"))
		{
			std::cerr << "Could not open texture" << std::endl;
			return;
		}
		sf::Event event;

		while (win.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
				stateId = GAME;
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
					stateId = GAME;
				else if (event.key.code == sf::Keyboard::Tab)
					stateId = GAME;
			}
		}
		sf::Sprite sprite;
		sprite.setTexture(texture);
		win.it->draw(sprite);
		clock.restart();
	}

	void StateMachine::gameState()
	{
		sf::Texture texture;

		if (!texture.loadFromFile("img/back.png"))
		{
			std::cerr << "Could not open texture" << std::endl;
			return;
		}
		sf::Sprite sprite;
		sprite.setTexture(texture);
		win.it->draw(sprite);

		sf::Time elapsed = clock.getElapsedTime();
		if (elapsed.asMilliseconds() > 200)
		{
			clock.restart();
			game.tick();
		}
		game.render();
	}
};