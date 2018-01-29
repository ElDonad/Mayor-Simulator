#include "BaseWidget.h"
#include "BaseWindow.h"



BaseWidget::BaseWidget()
{
}

BaseWidget::BaseWidget(sf::Vector2i size)
{
	m_size = size;
	m_pos = sf::Vector2i(0, 0);
	m_renderTexture.create(m_size.x, m_size.y);
}


BaseWidget::~BaseWidget()
{
}

sf::Vector2i BaseWidget::getSize()
{
	return m_size;
}

sf::Vector2i BaseWidget::getPos()
{
	return m_pos;
}

void BaseWidget::setPos(sf::Vector2i newPos)
{
	m_pos = newPos;
}

void BaseWidget::update(sf::Vector2i mousePosition, std::vector<sf::Keyboard::Key> pressedKeys, std::vector<sf::Mouse::Button> pressedMouse)
{
}

sf::Sprite BaseWidget::getWidgetSprite()
{
	return sf::Sprite(m_renderTexture.getTexture());
}
