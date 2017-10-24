#include "Dice.h"



Dice::Dice()
{
	diceValue = 0;
	holdState = false;
}


Dice::~Dice()
{
}

void Dice::Roll()
{
	if (!holdState)
	{
		diceValue = rand() % 6 +1;
	}
}