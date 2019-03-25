#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Ball.h"
#include "Tile.h"

class World
{
public:
	World();
	~World();
	void draw(sf::RenderWindow& window);
	void update_tiles();
	static int getQuantity();
private:
	Player player;
	std::vector<Tile> tiles;
	Ball redball;
	static const int QUANTITY = 100;
};
