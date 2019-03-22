#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

class Tile
{
public:
	Tile(float offsetX, float offsetY);
	~Tile();
	void draw(sf::RenderWindow &window);
	sf::RectangleShape getTile();
	void setIntersected(bool val);
	bool getIntersected();
private:
	bool intersected;
	sf::RectangleShape tile;
};
