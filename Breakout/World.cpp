#include "World.h"
#include "Player.h"

World::World()
{
	
}

World::~World()
{
	player.~Player();
}

void World::draw(sf::RenderWindow & window)
{
	player.draw(window);
	//tiles.draw(window);
	ball.draw(window, player);
}
