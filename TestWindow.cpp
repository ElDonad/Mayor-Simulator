#include "TestWindow.h"



TestWindow::TestWindow(sf::Vector2i size, std::string name) : ClosableWindow(size, name), m_okButton(sf::Vector2i(60,20),"OK", &m_okButtonPressed)
{
	m_okButton.setPos(sf::Vector2i(30, 30));
	m_widgets.push_back(&m_okButton);
	
}


TestWindow::~TestWindow()
{
}

std::vector<TestWindow::Event> TestWindow::update(sf::Vector2i mousePos, std::vector<sf::Keyboard::Key> pressedKeys, std::vector<sf::Mouse::Button> mouseButtons)
{
	std::vector <Event> events;
	ClosableWindow::update(mousePos, pressedKeys, mouseButtons);
	std::cout << m_okButtonPressed << std::endl;
	if (m_okButtonPressed == true)
	{
		events.push_back(this->Closed);
	}
	return events;
}
