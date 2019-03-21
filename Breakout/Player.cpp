#include "Player.h"



Player::Player()
{
	board.setSize(sf::Vector2f(60.0f,10.0f));
	board.setOrigin(board.getSize().x/2, board.getSize().y / 2);
	board.setPosition(400.0f, 585.0f);
	MOVE_SPEED = 0.2f;
}

Player::~Player()
{
}

void Player::draw(sf::RenderWindow &window)
{
	move();
	window.draw(board);
}

sf::Vector2f Player::getPosBoard()
{
	return board.getPosition();
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))  //left
	{
		if (board.getPosition().x >= 0)
		{
			board.move(-(MOVE_SPEED) , 0);

		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))  //right
	{
		if (board.getPosition().x <= 800)
		{
			board.move(MOVE_SPEED, 0);
		}
	}
}
