#pragma once
#include <SFML\System.hpp>
#include <iostream>
#include <vector>

class Quarter
{
public:
	enum {
		Residential,
		Industrial,
		TownHall,
		Military,
		Administrator
	} QuarterType;

	Quarter();
	~Quarter();

private:
	sf::Vector2 <int> pos;
	int m_workerNumber;
	int m_workerPopularity;
	int m_workerComfort;



	int m_executiveNumber;
};

