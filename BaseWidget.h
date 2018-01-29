#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Audio.hpp>

class BaseWindow;

class BaseWidget
{
public:
	
	BaseWidget();
	BaseWidget(sf::Vector2i size);
	//Toutes les variables qui pourront �tre chang�es par le widget devront �tre pass�es par r�f�rence dans le constructeur.
	~BaseWidget();
	sf::Vector2i getSize();
	sf::Vector2i getPos();
	void setPos(sf::Vector2i newPos);
	virtual void update(sf::Vector2i mousePosition, std::vector <sf::Keyboard::Key> pressedKeys, std::vector <sf::Mouse::Button> pressedMouse);
	virtual sf::Sprite getWidgetSprite();
	

protected:
	sf::Vector2i m_pos;
	sf::Vector2i m_size;
	sf::RenderTexture m_renderTexture;


};

