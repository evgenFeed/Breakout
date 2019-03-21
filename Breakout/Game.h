#pragma once
#include <SFML\Graphics.hpp>
#include "World.h"

class Game
{
public:
	Game();
	~Game();
	sf::RenderWindow *window;
	void createWindow();
	unsigned int getWindowWidth();
	unsigned int getWindowHeight();
	void setWindowWidth(unsigned int w);
	void setWindowHeight(unsigned int h);
private:
	World world;
	unsigned int WINDOW_WIDTH;
	unsigned int WINDOW_HEIGHT;
};

