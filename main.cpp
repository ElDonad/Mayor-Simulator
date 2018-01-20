#include <SFML/Graphics.hpp>
#include "BaseWindow.h"
#include <iostream>
#include <string>

std::string root = "C:/Users/Elie/Documents/Elie/divers/programmation/Mayor Simulator/MayorSimulator/MSimulator/Debug";

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	BaseWindow test(sf::Vector2i(100, 100), "coucou");

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
		//window.draw(shape);
		sf::Color borderColor(112, 97, 69);
		sf::Color middleColor(198, 186, 176);
		
		sf::RectangleShape testShape(sf::Vector2f(490, 21));
		testShape.setFillColor(borderColor);
		testShape.setPosition(sf::Vector2f(60, 50));
		window.draw(testShape);

		sf::Texture corners;
		corners.create(22, 22);
		corners.loadFromFile(root + "/ressources/images/window corner.png");

		sf::Sprite rightCorner(corners, sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(10, 10)));

		rightCorner.setPosition(sf::Vector2f(testShape.getSize().x + 60,50));
		rightCorner.setColor(borderColor);
		window.draw(rightCorner);

		sf::RectangleShape bottomRightCorner(sf::Vector2f(10, 11));
		bottomRightCorner.setFillColor(borderColor);
		bottomRightCorner.setPosition(rightCorner.getPosition().x, rightCorner.getPosition().y + 10);
		window.draw(bottomRightCorner);

		sf::Sprite leftCorner(corners, sf::IntRect(sf::Vector2i(0, 12), sf::Vector2i(10, 10)));
		leftCorner.setColor(borderColor);
		leftCorner.setPosition(sf::Vector2f(50, 50));
		window.draw(leftCorner);

		sf::RectangleShape bottomLeftCorner(sf::Vector2f(10, 11));
		bottomLeftCorner.setFillColor(borderColor);
		bottomLeftCorner.setPosition(leftCorner.getPosition().x, leftCorner.getPosition().y + 10);
		window.draw(bottomLeftCorner);

		sf::RectangleShape testShape2(sf::Vector2f(5, 200));
		testShape2.setFillColor(borderColor);
		testShape2.setPosition(50, 71);
		window.draw(testShape2);

		sf::RectangleShape testShape3(sf::Vector2f(500, 200));
		testShape3.setFillColor(middleColor);
		testShape3.setPosition(sf::Vector2f(55, 71));
		window.draw(testShape3);

		sf::RectangleShape testShape4(sf::Vector2f(5, 200));
		testShape4.setFillColor(borderColor);
		testShape4.setPosition(555, 71);
		window.draw(testShape4);

		sf::RectangleShape testShape5(sf::Vector2f(510, 5));
		testShape5.setFillColor(borderColor);
		testShape5.setPosition(50, 271);
		window.draw(testShape5);

		sf::Font consolas;
		consolas.loadFromFile("C:/Users/Elie/Documents/Elie/divers/programmation/Mayor Simulator/MayorSimulator/MSimulator/Debug/ressources/fonts/consola.ttf");
		sf::Text testText("Hello World", consolas, 18);
		testText.setPosition(56, 50);
		//testText.setFillColor(middleColor);
		window.draw(testText);

		sf::Texture ui;
		ui.loadFromFile(root + "/ressources/images/closeCroix.png");
		sf::Sprite croix(ui);
		croix.setPosition(testShape.getSize().x + 48, 50 + 5);

		if (croix.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y))
		{
			croix.setColor(sf::Color(0, 0, 0));
		};

			window.draw(croix);

		window.display();
	}

	return 0;
}