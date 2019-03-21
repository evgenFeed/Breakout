#include "Ball.h"





Ball::Ball()
{
	BALL_SPEED = 0.2f;
	RIGHT_SPEED = UP_SPEED = -BALL_SPEED;  //
 	ball.setRadius(4.5f);
	ball.setOrigin(5.0f,5.0f);
	ball.setFillColor(sf::Color(sf::Color::Red));
	ball.setPosition(sf::Vector2f(400.0f, 575.0f));
}

Ball::~Ball()
{
}

void Ball::draw(sf::RenderWindow & window, Player player)
{
	move(player);
	window.draw(ball);
}

void Ball::move(Player player)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		is_move(true);
	}
 	else
	{
		ball.setPosition(player.getPosBoard().x, player.getPosBoard().y - 10);
		is_move(false);
	}
}

void Ball::is_move(bool move)
{
	if (!move) return;
	else
	{
		if (ball.getPosition().x <= 0)
		{
			RIGHT_SPEED = BALL_SPEED;
		}
		else if (ball.getPosition().x >= 800)
		{
			RIGHT_SPEED = -BALL_SPEED; 
		}
		else if (ball.getPosition().y <= 0)
		{
			UP_SPEED = BALL_SPEED;
		}
		else if (ball.getPosition().y >= 600)
		{
			UP_SPEED = -BALL_SPEED;
		}
		ball.move(RIGHT_SPEED, UP_SPEED);
	}
}
