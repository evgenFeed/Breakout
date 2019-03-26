#include "Tile.h"

sf::Color getColor(int color)
{
	sf::Color tile_color;
	switch (color)
	{
	case 1: tile_color = sf::Color::White; break;
	case 2: tile_color = sf::Color::Red; break;
	case 3: tile_color = sf::Color::Magenta; break;
	default: tile_color = sf::Color::White; break;
	}
	return tile_color;
}


Tile::Tile(float offsetX, float offsetY , int color)
{
	tile.setSize(sf::Vector2f( 20.0f, 10.0f));
	tile.setOrigin(10.0f, 5.0f);
	tile.setPosition(offsetX += 25, offsetY);
	tile.setFillColor(getColor(color));
	intersected = false;
}

Tile::~Tile()
{
	
}

void Tile::draw(sf::RenderWindow & window)
{
	window.draw(tile);
	
}

sf::RectangleShape &Tile::getTile()
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
