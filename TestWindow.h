#pragma once
#include <iostream>
#include <string>
#include "ClosableWindow.h"
#include "ButtonWidget.h"


class TestWindow :
	public ClosableWindow
{
public:
	TestWindow(sf::Vector2i size, std::string name);
	~TestWindow();
	virtual std::vector <Event> update(sf::Vector2i mousePos, std::vector<sf::Keyboard::Key>pressedKeys, std::vector<sf::Mouse::Button> mouseButtons);

private:
	ButtonWidget m_okButton;
	bool m_okButtonPressed;
};

