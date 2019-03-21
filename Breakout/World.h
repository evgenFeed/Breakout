#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Ball.h"
#include "Tiles.h"

class World
{
public:
	World();
	~World();
	void draw(sf::RenderWindow& window);
private:
	Player player;
	Tiles tiles;
	Ball ball;
};
