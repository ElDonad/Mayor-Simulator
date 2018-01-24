#pragma once
#include "BaseWindow.h"
class ClosableWindow :
	public BaseWindow
{
public:
	ClosableWindow();
	ClosableWindow(sf::Vector2i size, std::string name);
	~ClosableWindow();
	virtual std::vector <Event> update(sf::Vector2i mousePos, std::vector<sf::Keyboard::Key>pressedKeys, std::vector<sf::Mouse::Button> mouseButtons);
};

