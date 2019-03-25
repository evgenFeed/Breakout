#include "Congratulations.h"



Congratulations::Congratulations()
{
	font.loadFromFile("arial.ttf");

	congr.setFont(font);
	congr.setString("Congratulations!");
	congr.setPosition(20.0f,20.0f);

	score.setFont(font);
	score.setString("Scores: " + std::to_string(Ball::getScores()));
	score.setPosition(congr.getPosition() + sf::Vector2f(20.0f, 30.0f));

	

	create_congratulations();

	while (for_cong->isOpen())
	{
		//events
		
		sf::Event event;
		while (for_cong->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				Ball::end = false;
				closed = true;
				for_cong->close();
			}
		}

		for_cong->clear();

		for_cong->draw(congr);
		for_cong->draw(score);

		for_cong->display();
	}
}


Congratulations::~Congratulations()
{
	delete for_cong;
}

void Congratulations::create_congratulations()
{
	setWindowWidth(400); setWindowHeight(200);
	for_cong = new sf::RenderWindow(sf::VideoMode(getWindowWidth(), getWindowHeight()), "Congratulations");
	for_cong->setPosition(sf::Vector2i(200, 200));
}

unsigned int Congratulations::getWindowWidth()
{
	return WINDOW_WIDTH;
}

unsigned int Congratulations::getWindowHeight()
{
	return WINDOW_HEIGHT;
}

void Congratulations::setWindowWidth(unsigned int w)
{
	WINDOW_WIDTH = w;
}

void Congratulations::setWindowHeight(unsigned int h)
{
	WINDOW_HEIGHT = h;
}

bool Congratulations::get_closed()
{
	return closed;
}

bool Congratulations::closed = false;