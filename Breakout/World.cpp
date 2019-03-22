#include "World.h"

const int QUANTITY = 20;
World::World()
{
	float offsetX = 25, offsetY = 0;
	for (int i = 0; i < QUANTITY; i++)
	{
		tiles.push_back(Tile(offsetX += 25, offsetY));
	}
	
}

World::~World()
{
	player.~Player();
}

void World::draw(sf::RenderWindow & window)
{
	player.draw(window);
	for (auto i : tiles)
	{
		i.draw(window);
	}
	ball.draw(window, player, tiles);
	update_tiles();
}

void World::update_tiles()
{
 	tiles.erase(std::remove_if(tiles.begin(), tiles.end(), [](Tile e)
	{
		if (e.getIntersected() == true)
		{
			e.getTile().setFillColor(sf::Color::Black);
			return true;
		}
		else return false;
	}), tiles.end());
}
