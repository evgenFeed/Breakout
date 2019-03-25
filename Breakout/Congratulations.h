#pragma once
#include "Ball.h"
#include "Game.h"

class Congratulations
{
public:
	Congratulations();
	~Congratulations();
	void create_congratulations();
	unsigned int getWindowWidth();
	unsigned int getWindowHeight();
	void setWindowWidth(unsigned int w);
	void setWindowHeight(unsigned int h);
	static bool get_closed();
private:
	sf::Text score;
	sf::Text congr;
	sf::Font font;
	sf::RenderWindow *for_cong;
	unsigned int WINDOW_WIDTH;
	unsigned int WINDOW_HEIGHT;
	static bool closed;
};

