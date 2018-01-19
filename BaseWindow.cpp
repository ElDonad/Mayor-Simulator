#include "BaseWindow.h"
using namespace std;


BaseWindow::BaseWindow()
{
	sf::Image corner;
	sf::RenderTexture finalImage;
	finalImage.create(m_size.x + 10, m_size.y + 21);
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
	finalImage.draw(borderSprite);//les bords sont tracés
	
	sf::RectangleShape centerRectangle(sf::Vector2f(5, 21));
	centerRectangle.setSize(sf::Vector2f(m_size.x - 5, m_size.y - 5));
	centerRectangle.setFillColor(sf::Color(sf::Uint8(241), sf::Uint8(241), sf::Uint8(241)));//couleur d'arrière plan


}


BaseWindow::BaseWindow(sf::Vector2i size, std::string name, sf::RenderWindow* renderWindow)
{
	m_size.x = size.x + 10;
	m_size.y = size.y + 21;
	m_renderWindow = renderWindow;

}

BaseWindow::~BaseWindow()
{
}

sf::Image BaseWindow::update()
{
	sf::RenderTexture mainTexture;



	return mainImage;
}
