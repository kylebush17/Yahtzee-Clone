#include "Scorecard.h"



Scorecard::Scorecard()
{
	for (int i = 0; i < 15; i++)
	{
		used[i] = false;
	}


	for (int i = 0; i < 15; i++)
	{
		values[i] = 0;
	}


}


Scorecard::~Scorecard()
{
}

void Scorecard::draw(sf::RenderWindow &window)
{
	
}