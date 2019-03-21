#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Tiles.h"
#include <vector>
#include <algorithm>

class Ball
{
public:
	Ball();
	~Ball();
	void draw(sf::RenderWindow &window, Player &player, Tiles &tiles);
	void move(Player player);
	void is_move(bool move);
	void intersect(Player player);
	void intersect(std::vector<sf::RectangleShape> tiles);
	void update_intersect(Player &player, Tiles &tiles);
private:
	sf::CircleShape ball;
	float BALL_SPEED, UP_SPEED, RIGHT_SPEED;
};
