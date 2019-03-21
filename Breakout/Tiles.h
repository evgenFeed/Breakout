#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

class Tiles
{
public:
	Tiles();
	~Tiles();
	void draw(sf::RenderWindow &window);
	std::vector<sf::RectangleShape> getTiles();
private:
	std::vector<sf::RectangleShape> tiles;
};

