#include "Game.h"



Game::Game()
{
	setWindowWidth(800);
	setWindowHeight(600);
	createWindow();

	while (window->isOpen())
	{
		//events
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		window->clear();

		world.draw(*window);

		window->display();
	}
}

Game::~Game()
{
	world.~World();
	delete window;
}

void Game::createWindow()
{
	if (getWindowHeight() != 0 && getWindowWidth() != 0)
	{
		window = new sf::RenderWindow(sf::VideoMode(getWindowWidth(), getWindowHeight()), "Breakout");
		window->setPosition(sf::Vector2i(50, 50));
		//window->setFramerateLimit(120);
	}

	else
	{
		setWindowWidth(1024);
		setWindowHeight(768);
		window = new sf::RenderWindow(sf::VideoMode(getWindowWidth(), getWindowHeight()), "Breakout");
		window->setPosition(sf::Vector2i(50, 50));
	}
}

unsigned int Game::getWindowWidth()
{
	return WINDOW_WIDTH;
}

unsigned int Game::getWindowHeight()
{
	return WINDOW_HEIGHT;
}

void Game::setWindowWidth(unsigned int w)
{
	WINDOW_WIDTH = w;
}

void Game::setWindowHeight(unsigned int h)
{
	WINDOW_HEIGHT = h;
}
