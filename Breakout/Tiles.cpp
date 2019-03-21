#include "Tiles.h"

const int QUANTITY = 20;

Tiles::Tiles()
{
	float offsetX = 25, offsetY = 10;
	for (int i = 0; i < QUANTITY; i++)
	{
		tiles.push_back(sf::RectangleShape(sf::Vector2f(20.0f, 10.0f)));
		tiles.at(i).setOrigin(10.0f, 5.0f);
		tiles.at(i).setPosition(offsetX += 25, offsetY);
	}
}


Tiles::~Tiles()
{
	
}

void Tiles::draw(sf::RenderWindow & window)
{
	for (auto i : tiles)
	{
		window.draw(i);
	}
}

std::vector<sf::RectangleShape> Tiles::getTiles()
{
	return tiles;
}
