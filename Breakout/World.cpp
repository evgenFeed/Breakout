#include "World.h"

const int QUANTITY = 100;

World::World()
{
	float offsetX = 0, offsetY = 20;
	for (int i = 0; i < QUANTITY; i++)
	{
		if (offsetX >= 750)
		{
			offsetY += 12;
			offsetX = 0;
		}
		tiles.push_back(Tile(offsetX += 25, offsetY));
	}

	//score.setFont(sf::Font::loadFromFile(""))
}

World::~World()
{
	player.~Player();
	ball.~Ball();
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

