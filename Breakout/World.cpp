#include "World.h"



World::World()
{
	int color = 3;
	float offsetX = 0, offsetY = 30;
	for (int i = 0; i < QUANTITY; i++)
	{
		if (offsetX >= 720)
		{
			offsetY += 12;
			offsetX = 0;
			color--;
		}
		tiles.push_back(Tile(offsetX += 25, offsetY, color));
	}

}

World::~World()
{
	player.~Player();
	redball.~Ball();
	for (auto i : tiles)
	{
		i.~Tile();
	}
}

void World::draw(sf::RenderWindow & window)
{
	player.draw(window);
	for (auto &i : tiles)
	{
		i.draw(window);
	}
	redball.draw(window, player, tiles);
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

int World::getQuantity()
{
	return QUANTITY;
}


