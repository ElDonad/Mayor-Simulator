#include "ClosableWindow.h"

using namespace std;
using namespace sf;

ClosableWindow::ClosableWindow()
{
}

ClosableWindow::ClosableWindow(sf::Vector2i size, std::string name) : ClosableWindow::BaseWindow(size, name)
{

}

vector <ClosableWindow::Event> ClosableWindow::update(sf::Vector2i mousePos, vector<sf::Keyboard::Key>pressedKeys, vector<sf::Mouse::Button> mouseButtons)
{
	vector <Event> events;
	sf::Texture ui;
	ui.loadFromFile("C:/Users/Elie/Documents/Elie/divers/programmation/Mayor Simulator/MayorSimulator/MSimulator/Debug/ressources/images/closeCroix.png");
	sf::Sprite croix(ui);
	croix.setPosition(m_progressWindow.getSize().x - 15, 5);
	sf::RectangleShape test;
	//	test.setPosition(croix.getGlobalBounds().left, croix.getGlobalBounds().top);
	test.setSize(sf::Vector2f(10, 10));
	//	m_progressWindow.draw(test);
	cout << croix.getGlobalBounds().left << endl << mousePos.x << endl;

	if (croix.getGlobalBounds().contains(static_cast <sf::Vector2f>(mousePos)))
	{
		cout << "coucou" << endl;
		croix.setColor(sf::Color(150, 0, 0));
		for (int loop = 0; loop != mouseButtons.size(); loop++)
		{
			if (mouseButtons[loop] == sf::Mouse::Left)
				events.push_back(Closed);
			cout << "coucou" << endl;
		}
	}

	m_progressWindow.draw(croix);
	m_window = m_progressWindow.getTexture();
	return events;
}


ClosableWindow::~ClosableWindow()
{
}
