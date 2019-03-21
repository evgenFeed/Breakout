#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

class Tiles
{
public:
	Tiles();
	~Tiles();
private:
	std::vector<sf::RectangleShape> tiles;
};

