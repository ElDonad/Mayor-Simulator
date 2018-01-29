#include "ButtonWidget.h"

using namespace std;
using namespace sf;

ButtonWidget::ButtonWidget(sf::Vector2i size, std::string text, bool * clicked) : BaseWidget(size)
{
	m_clicked = clicked;
	m_hovered = new bool;
	*m_hovered = false;
	destructM_hovered = true;
	m_text = text;
	m_renderTexture.create(m_size.x + 6, m_size.y + 6);
	constructButton(static_cast<Vector2i>(m_renderTexture.getSize()), Color(112, 97, 69),Color(198, 186, 176),text);
}

ButtonWidget::ButtonWidget(sf::Vector2i size, std::string text, bool * clicked, bool * hovered)
{
	m_clicked = clicked;
	m_hovered = hovered;
	m_text = text;
	m_renderTexture.create(m_size.x + 6, m_size.y + 6);
	destructM_hovered = false;
	constructButton(static_cast<Vector2i>(m_renderTexture.getSize()), Color(112, 97, 69), Color(198, 186, 176), text);
}

ButtonWidget::~ButtonWidget()
{
	if (destructM_hovered)
		delete m_hovered;
}

void ButtonWidget::update(sf::Vector2i mousePosition, std::vector<sf::Keyboard::Key> pressedKeys, std::vector<sf::Mouse::Button> pressedMouse)
{
	//1. reset texture
	bool isHover = false;
	bool isPressed = false;
	sf::IntRect button(m_pos.x, m_pos.y, m_size.x, m_size.y);

	if (button.contains(mousePosition))
	{
		isHover = true;
		if (Utilities::isVectorContainingItem(pressedMouse, sf::Mouse::Left))
			isPressed = true;
	}

	//changement éventuel des textures
	if (*m_hovered == false && isHover == true)
	{
		constructButton(static_cast<Vector2i>(m_renderTexture.getSize()), Color(145, 128, 75), Color(220, 222, 149), m_text);
		*m_hovered = true;
	}

	if (*m_hovered == true && isHover == false)
	{
		constructButton(static_cast<Vector2i>(m_renderTexture.getSize()), Color(112, 97, 69), Color(198, 186, 176), m_text);
		*m_hovered = false;
	}

	if (*m_clicked == false && isPressed == true)
	{
		*m_clicked = true;
	}

	if (*m_clicked == true && isPressed == false)
	{
		*m_clicked = false;
	}
}

void ButtonWidget::constructButton(sf::Vector2i size, sf::Color background, sf::Color foreground, std::string test)
{
	RectangleShape backgroundShape(Vector2f(m_size.x, m_size.y));
	backgroundShape.setFillColor(background);
	backgroundShape.setPosition(0, 0);
	m_renderTexture.draw(backgroundShape);

	RectangleShape foregroundShape(Vector2f(m_size.x - 4, m_size.y - 4));
	foregroundShape.setFillColor(foreground);
	foregroundShape.setPosition(2, 2);
	m_renderTexture.draw(foregroundShape);

	Font consolas;
	consolas.loadFromFile("C:\\Users\\Elie\\Documents\\Elie\\divers\\programmation\\Mayor Simulator\\MayorSimulator\\MSimulator\\Debug\\ressources\\fonts\\consola.ttf");
	Text textDrawable;
	textDrawable.setString(test);
	textDrawable.setFont(consolas);
	textDrawable.setCharacterSize(m_size.y - 5);
	textDrawable.setPosition((m_size.x - 4 - textDrawable.getGlobalBounds().height)/2 - 2,0 );
	m_renderTexture.draw(textDrawable);
	
	m_renderTexture.display();

}
