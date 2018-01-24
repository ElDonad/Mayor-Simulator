#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <iostream>
#include <vector>
#include <string>


class BaseWindow
{
public:
	BaseWindow(sf::Vector2i size, std::string name);
	BaseWindow();
	~BaseWindow();

	enum Event {
		Resized,
		Closed,
		GotFocus,
		LostFocus
	};

	virtual std::vector <Event> update(sf::Vector2i mousePos, std::vector<sf::Keyboard::Key>pressedKeys, std::vector<sf::Mouse::Button> mouseButtons);
	sf::Texture* getTexture();
	sf::Vector2i getPos();
	void setPos(sf::Vector2i newPos);


protected:
	sf::Vector2i m_size;
	sf::Vector2i m_pos;
	std::string m_name;
	sf::Texture m_window;
	sf::RenderTexture m_progressWindow;
};

