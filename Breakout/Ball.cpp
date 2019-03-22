#include "Ball.h"





Ball::Ball()
{
	score = 0;
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

void Ball::draw(sf::RenderWindow & window, Player &player, std::vector<Tile> &tiles)
{
	move(player);
	window.draw(ball);
	update_intersect(player, tiles);
}

void Ball::move(Player &player)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		is_move(true);
	}
 	else
	{
		ball.setPosition(player.getBoard().getPosition().x, player.getBoard().getPosition().y - 10);
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

void Ball::intersect(Player &player)
{
	if (ball.getGlobalBounds().intersects(player.getBoard().getGlobalBounds()))
	{
		UP_SPEED = -UP_SPEED;
	}
}

void Ball::intersect(std::vector<Tile> &tiles)
{
	for (auto& i : tiles)
	{
		if (ball.getGlobalBounds().intersects(i.getTile().getGlobalBounds()))
		{
			UP_SPEED = -UP_SPEED;
			i.setIntersected(true);
			score++;
		}
	}
}

void Ball::update_intersect(Player &player, std::vector<Tile> &tiles)
{
	intersect(player);
	intersect(tiles);
}

std::string Ball::score_s()
{
	return std::string("Score: " + std::to_string(score));
}
