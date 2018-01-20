#include "BaseWindow.h"
using namespace std;


BaseWindow::BaseWindow()
{
	sf::Image corner;
	m_blankWindow.create(m_size.x + 10, m_size.y + 21);
	m_blankWindow.create(m_size.x + 10, m_size.y + 21);

	sf::Color borderColor (sf::Uint8(228), sf::Uint8(216), sf::Uint8(211));
	corner.loadFromFile("ressources/images/window border.png");
	sf::Image cornerWindow;
	cornerWindow.create(m_size.x + 10, m_size.y + 21);

	cornerWindow.copy(corner,0,0);
	corner.flipHorizontally();
	cornerWindow.copy(corner, m_size.x - 2, 0);
	corner.flipVertically();
	cornerWindow.copy(corner, m_size.x - 2, m_size.y - 2);
	corner.flipHorizontally();
	cornerWindow.copy(corner, 0, m_size.y - 2);

	sf::Sprite borderSprite;
	sf::Texture borderTexture;
	borderTexture.create(cornerWindow.getSize().x, cornerWindow.getSize().y);
	borderTexture.loadFromImage(cornerWindow);
	borderSprite.setTexture(borderTexture);
	m_blankWindow.draw(borderSprite);//les bords sont tracés
	
	sf::RectangleShape centerRectangle(sf::Vector2f(5, 21));
	centerRectangle.setSize(sf::Vector2f(m_size.x - 5, m_size.y - 5));
	centerRectangle.setFillColor(sf::Color(sf::Uint8(241), sf::Uint8(241), sf::Uint8(241)));//couleur d'arrière plan
	m_blankWindow.draw(centerRectangle);

	sf::RectangleShape leftBorder(sf::Vector2f(0, 2));
	leftBorder.setFillColor(borderColor);
	leftBorder.setSize(sf::Vector2f(5, m_size.y - 2));
	m_blankWindow.draw(leftBorder);

	sf::RectangleShape bottomCorner(sf::Vector2f(0, m_size.y - 5));
	bottomCorner.setFillColor(borderColor);
	bottomCorner.setSize(sf::Vector2f(sf::Vector2f(m_size.x - 2, m_size.y - 2)));
	m_blankWindow.draw(bottomCorner);

	m_blankWindow.display();

}


BaseWindow::BaseWindow(sf::Vector2i size, std::string name)
{
	m_size.x = size.x + 10;
	m_size.y = size.y + 21;

}

BaseWindow::~BaseWindow()
{
}

sf::Texture BaseWindow::update()
{
	return m_blankWindow.getTexture();
}
