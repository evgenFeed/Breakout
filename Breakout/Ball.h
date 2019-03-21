#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"


class Ball
{
public:
	Ball();
	~Ball();
	void draw(sf::RenderWindow &window, Player player);
	void move(Player player);
	void is_move(bool move);
private:
	sf::CircleShape ball;
	float BALL_SPEED, UP_SPEED, RIGHT_SPEED;
};

