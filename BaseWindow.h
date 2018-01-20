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

	virtual sf::Texture update();

private:
	sf::Vector2i m_size;
	std::string m_name;
	sf::RenderWindow* m_renderWindow;
	sf::RenderTexture m_blankWindow;
};

