#include "BaseWindow.h"
using namespace std;


BaseWindow::BaseWindow()
{
	//temporaire :
	m_size.x = 500;
	m_size.y = 400;
	
	
	std::string root = "C:/Users/Elie/Documents/Elie/divers/programmation/Mayor Simulator/MayorSimulator/MSimulator/Debug";
	sf::Color borderColor(112, 97, 69);
	sf::Color middleColor(198, 186, 176);
	m_progressWindow.create(m_size.x + 10, m_size.y + 26);

	sf::RectangleShape header(sf::Vector2f(m_size.x - 10, 21));
	header.setFillColor(borderColor);
	header.setPosition(sf::Vector2f(10, 0));
	m_progressWindow.draw(header);

	sf::Texture corners;
	corners.create(22, 22);
	corners.loadFromFile(root + "/ressources/images/window corner.png");

	sf::Sprite rightCorner(corners, sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(10, 10)));
	rightCorner.setPosition(sf::Vector2f(header.getSize().x + 10, 0));
	rightCorner.setColor(borderColor);
	m_progressWindow.draw(rightCorner);

	sf::RectangleShape bottomRightCorner(sf::Vector2f(10, 11));
	bottomRightCorner.setFillColor(borderColor);
	bottomRightCorner.setPosition(rightCorner.getPosition().x, rightCorner.getPosition().y + 10);
	m_progressWindow.draw(bottomRightCorner);

	sf::Sprite leftCorner(corners, sf::IntRect(sf::Vector2i(0, 12), sf::Vector2i(10, 10)));
	leftCorner.setColor(borderColor);
	leftCorner.setPosition(sf::Vector2f(0, 0));
	m_progressWindow.draw(leftCorner);

	sf::RectangleShape bottomLeftCorner(sf::Vector2f(10, 11));
	bottomLeftCorner.setFillColor(borderColor);
	bottomLeftCorner.setPosition(leftCorner.getPosition().x, leftCorner.getPosition().y + 10);
	m_progressWindow.draw(bottomLeftCorner);

	sf::RectangleShape leftSide(sf::Vector2f(5, m_size.y));
	leftSide.setFillColor(borderColor);
	leftSide.setPosition(0, 21);
	m_progressWindow.draw(leftSide);

	sf::RectangleShape middle(static_cast <sf::Vector2f>(m_size));
	middle.setFillColor(middleColor);
	middle.setPosition(sf::Vector2f(5, 21));
	m_progressWindow.draw(middle);

	sf::RectangleShape rightSide(sf::Vector2f(5, m_size.y));
	rightSide.setFillColor(borderColor);
	rightSide.setPosition(m_size.x + 5, 21);
	m_progressWindow.draw(rightSide);

	sf::RectangleShape bottomSide(sf::Vector2f(m_size.x + 10, 5));
	bottomSide.setFillColor(borderColor);
	bottomSide.setPosition(0, m_size.y + 21);
	m_progressWindow.draw(bottomSide);

	sf::Font consolas;
	consolas.loadFromFile("C:/Users/Elie/Documents/Elie/divers/programmation/Mayor Simulator/MayorSimulator/MSimulator/Debug/ressources/fonts/consola.ttf");
	sf::Text testText("Hello World", consolas, 18);
	testText.setPosition(6, 0);
	m_progressWindow.draw(testText);

	m_progressWindow.display();

	m_window.create(m_progressWindow.getSize().x, m_progressWindow.getSize().y);
	m_window = m_progressWindow.getTexture();

}


BaseWindow::BaseWindow(sf::Vector2i size, std::string name)
{
	m_size.x = size.x + 10;
	m_size.y = size.y + 21;


	std::string root = "C:/Users/Elie/Documents/Elie/divers/programmation/Mayor Simulator/MayorSimulator/MSimulator/Debug";
	sf::Color borderColor(112, 97, 69);
	sf::Color middleColor(198, 186, 176);
	m_progressWindow.create(m_size.x + 10, m_size.y + 26);

	sf::RectangleShape header(sf::Vector2f(m_size.x - 10, 21));
	header.setFillColor(borderColor);
	header.setPosition(sf::Vector2f(10, 0));
	m_progressWindow.draw(header);

	sf::Texture corners;
	corners.create(22, 22);
	corners.loadFromFile(root + "/ressources/images/window corner.png");

	sf::Sprite rightCorner(corners, sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(10, 10)));
	rightCorner.setPosition(sf::Vector2f(header.getSize().x + 10, 0));
	rightCorner.setColor(borderColor);
	m_progressWindow.draw(rightCorner);

	sf::RectangleShape bottomRightCorner(sf::Vector2f(10, 11));
	bottomRightCorner.setFillColor(borderColor);
	bottomRightCorner.setPosition(rightCorner.getPosition().x, rightCorner.getPosition().y + 10);
	m_progressWindow.draw(bottomRightCorner);

	sf::Sprite leftCorner(corners, sf::IntRect(sf::Vector2i(0, 12), sf::Vector2i(10, 10)));
	leftCorner.setColor(borderColor);
	leftCorner.setPosition(sf::Vector2f(0, 0));
	m_progressWindow.draw(leftCorner);

	sf::RectangleShape bottomLeftCorner(sf::Vector2f(10, 11));
	bottomLeftCorner.setFillColor(borderColor);
	bottomLeftCorner.setPosition(leftCorner.getPosition().x, leftCorner.getPosition().y + 10);
	m_progressWindow.draw(bottomLeftCorner);

	sf::RectangleShape leftSide(sf::Vector2f(5, m_size.y));
	leftSide.setFillColor(borderColor);
	leftSide.setPosition(0, 21);
	m_progressWindow.draw(leftSide);

	sf::RectangleShape middle(static_cast <sf::Vector2f>(m_size));
	middle.setFillColor(middleColor);
	middle.setPosition(sf::Vector2f(5, 21));
	m_progressWindow.draw(middle);

	sf::RectangleShape rightSide(sf::Vector2f(5, m_size.y));
	rightSide.setFillColor(borderColor);
	rightSide.setPosition(m_size.x + 5, 21);
	m_progressWindow.draw(rightSide);

	sf::RectangleShape bottomSide(sf::Vector2f(m_size.x + 10, 5));
	bottomSide.setFillColor(borderColor);
	bottomSide.setPosition(0, m_size.y + 21);
	m_progressWindow.draw(bottomSide);

	sf::Font consolas;
	consolas.loadFromFile("C:/Users/Elie/Documents/Elie/divers/programmation/Mayor Simulator/MayorSimulator/MSimulator/Debug/ressources/fonts/consola.ttf");
	sf::Text testText(name, consolas, 18);
	testText.setPosition(6, 0);
	m_progressWindow.draw(testText);

	m_progressWindow.display();

	m_window.create(m_progressWindow.getSize().x, m_progressWindow.getSize().y);
	m_window = m_progressWindow.getTexture();

}

BaseWindow::~BaseWindow()
{
}

vector <BaseWindow::Event> BaseWindow::update(sf::Vector2i mousePos, vector<sf::Keyboard::Key> pressedKeys, std::vector<sf::Mouse::Button> mouseButtons)
{

}

sf::Texture* BaseWindow::getTexture()
{
	return &m_window;
}

sf::Vector2i BaseWindow::getPos()
{
	return m_pos;
}

void BaseWindow::setPos(sf::Vector2i newPos)
{
	m_pos = newPos;
}

