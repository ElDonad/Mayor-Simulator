#pragma once
#include <SFML\System.hpp>
#include <iostream>
#include <vector>
#include "Quarter.h"


class Town
{
public:
	Town();
	~Town();

private:
	sf::String m_name;
	sf::String m_mayorName;
	std::vector <Quarter*> m_quarters;
};

