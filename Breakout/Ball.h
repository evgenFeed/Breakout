#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Tile.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

class Ball
{
public:
	Ball();
	~Ball();
	void draw(sf::RenderWindow &window, Player &player, std::vector<Tile> &tiles);
	void move(Player &player);
	void is_move(bool move);
	void intersect(Player &player);
	void intersect(std::vector<Tile> &tiles);
	void update_intersect(Player &player, std::vector<Tile> &tiles);
	void update_scores();
	static int getScores();
	static bool end;
private:
	sf::CircleShape ball;
	float BALL_SPEED, UP_SPEED, RIGHT_SPEED;
	static int scores;
	sf::Text score;
	sf::Font font;
	bool moves;
};
