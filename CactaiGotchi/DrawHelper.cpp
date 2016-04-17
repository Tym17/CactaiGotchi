#include <iostream>
#include "DrawHelper.hpp"

namespace cactaigotchi
{
	DrawHelper::DrawHelper(WindowSystem &_win) :
		win(_win)
	{
		canText = false;
		if (!OpenSans.loadFromFile("OpenSans.ttf"))
		{
			return;
		}
		canText = true;
	}

	void DrawHelper::drawImage(int x, int y, const char *path)
	{
		sf::Texture texture;

		if (!texture.loadFromFile(path))
		{
			std::cerr << "Could not open texture" << std::endl;
			return;
		}
		sf::Sprite sprite;
		sprite.setTexture(texture);
		sprite.setPosition(x, y);
		win.it->draw(sprite);
	}

	void DrawHelper::drawImage(int x, int y, const char *path, int clr)
	{
		sf::Texture texture;

		if (!texture.loadFromFile(path))
		{
			std::cerr << "Could not open texture" << std::endl;
			return;
		}
		sf::Sprite sprite;
		sprite.setTexture(texture);
		sprite.setPosition(x, y);
		sprite.setColor(sf::Color(clr >> 16 & 0xFF,
			clr >> 8 & 0xFF,
			clr & 0xFF));
		win.it->draw(sprite);
	}

	void DrawHelper::drawImage(int x, int y, const char *path, int clr, float scale)
	{
		sf::Texture texture;

		if (!texture.loadFromFile(path))
		{
			std::cerr << "Could not open texture" << std::endl;
			return;
		}
		texture.setSmooth(true);
		sf::Sprite sprite;
		sprite.setTexture(texture);
		sprite.setPosition(x, y);
		sprite.setColor(sf::Color(clr >> 16 & 0xFF,
			clr >> 8 & 0xFF,
			clr & 0xFF));
		sprite.setScale(scale, scale);
		win.it->draw(sprite);
	}

	void DrawHelper::drawText(int x, int y, const char *txt, int size = 24)
	{
		sf::Text text;

		text.setFont(OpenSans);
		text.setString(txt);
		text.setCharacterSize(size);
		text.setColor(sf::Color::Black);
		text.setPosition(x, y);
		win.it->draw(text);
	}

	void DrawHelper::drawBar(int x, int y, int len, int actual, int max, int clrf, int clre)
	{
		sf::RectangleShape back(sf::Vector2f(len, 15));
		sf::RectangleShape front(sf::Vector2f((actual * len) / max, 15));
		
		back.setFillColor(sf::Color(clre >> 16 & 0xFF,
			clre >> 8 & 0xFF,
			clre & 0xFF));
		front.setFillColor(sf::Color(clrf >> 16 & 0xFF,
			clrf >> 8 & 0xFF,
			clrf & 0xFF));
		back.setPosition(x, y);
		front.setPosition(x, y);
		win.it->draw(back);
		win.it->draw(front);
	}
};