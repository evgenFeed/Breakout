#pragma once
#include <SFML\Graphics.hpp>

class Player
{
public:
	Player();
	~Player();
	void draw(sf::RenderWindow &window);
	//sf::Vector2f getPosBoard();
	void move();
	sf::RectangleShape getBoard();
private:
	sf::RectangleShape board;
	float MOVE_SPEED;
};
