#pragma once
#include "BaseWidget.h"
#include "Utilities.h"

class ButtonWidget :
	public BaseWidget
{
public:
	ButtonWidget(sf::Vector2i size, std::string text, bool* clicked);
	ButtonWidget(sf::Vector2i size, std::string text, bool* clicked, bool* hovered);
	~ButtonWidget();
	virtual void update(sf::Vector2i mousePosition, std::vector <sf::Keyboard::Key> pressedKeys, std::vector <sf::Mouse::Button> pressedMouse);

protected:
	bool* m_clicked;
	bool* m_hovered;
	std::string m_text;

private:
	void constructButton(sf::Vector2i size, sf::Color background, sf::Color foreground, std::string test);

	//pour le destructeur
	bool destructM_hovered;
};

