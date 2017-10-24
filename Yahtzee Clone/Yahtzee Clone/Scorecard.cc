#include "Scorecard.h"



Scorecard::Scorecard()
{
	ones = false;
	twos = false;
	threes = false;
	fours = false;
	fives = false;
	sixes = false;
	upperBonus = false;
	threeOfKind = false;
	fourOfKind = false;
	smallStraight = false;
	largeStraight = false;
	chance = false;
	yahtzee = false;
	yahtzeeBonus = false;


	ones_value = 0;
	twos_value = 0; 
	threes_value = 0;
	fours_value = 0;
	fives_value = 0;
	sixes_value = 0;
	upperBonus_values = 0;
	threeOfKind_value = 0;
	fourOfKind_value = 0;
	smallStraight_value = 0;
	largeStraight_value = 0;
	fullHouse_value = 0;
	chance_value = 0;
	yahtzee_value = 0;
	yahtzeeBonus_value = 0;


}


Scorecard::~Scorecard()
{
}

void Scorecard::draw(sf::RenderWindow &window)
{
	
}