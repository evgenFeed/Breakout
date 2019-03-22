#include "Tile.h"




Tile::Tile(float offsetX, float offsetY)
{
	tile.setSize(sf::Vector2f( 20.0f, 10.0f));
	tile.setOrigin(10.0f, 5.0f);
	tile.setPosition(offsetX += 25, offsetY);
	intersected = false;
}


Tile::~Tile()
{
	
}

void Tile::draw(sf::RenderWindow & window)
{
	window.draw(tile);
}

sf::RectangleShape Tile::getTile()
{
	return tile;
}

void Tile::setIntersected(bool val)
{
	intersected = val;
}

bool Tile::getIntersected()
{
	return intersected;
}


