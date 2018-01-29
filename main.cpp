#include <SFML/Graphics.hpp>
#include "BaseWindow.h"
#include "ClosableWindow.h"
#include <iostream>
#include <string>
#include "TestWindow.h"

using namespace std;
using namespace sf;

int main()
{
	string root = "C:/Users/Elie/Documents/Elie/divers/programmation/Mayor Simulator/MayorSimulator/MSimulator/Debug"; 
	RenderWindow window(sf::VideoMode(1200, 800), "Mayor Simulator");
	CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	vector <BaseWindow*> windows;
	//windows.push_back(new ClosableWindow(Vector2i(300, 500), "Coucou"));
	//windows.push_back(new ClosableWindow(Vector2i(80, 110), "Deuxième fenêtre"));
	windows.push_back(new TestWindow(Vector2i(300, 600), "Test"));
	windows[0]->setPos(Vector2i(250, 100));

	while (window.isOpen())
	{
		sf::RenderTexture mainTexture;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		vector <sf::Mouse::Button> mouseButtons;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			mouseButtons.push_back(sf::Mouse::Left);

		for (int loop = 0; loop != windows.size(); loop++)
		{
			Sprite toDraw(*windows[loop]->getTexture());
			toDraw.setPosition(static_cast <Vector2f>(windows[loop]->getPos()));
			
			vector <BaseWindow::Event> events = windows[loop]->update(Mouse::getPosition(window) - windows[loop]->getPos(), vector<Keyboard::Key>(), mouseButtons);
			for (int loopB = 0; loopB != events.size(); loopB++)
			{
				if (events[loopB] == BaseWindow::Closed)
				{
					windows[loop]->~BaseWindow();
					windows.erase(windows.begin() + loop);
					loop--;
					continue;
				}

			}
			window.draw(toDraw);
		}


		window.display();
	}

	return 0;
}