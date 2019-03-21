#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

class Tiles
{
public:
	Tiles();
	~Tiles();
	void draw(sf::RenderWindow &window);
private:
	std::vector<sf::RectangleShape> tiles;
};

