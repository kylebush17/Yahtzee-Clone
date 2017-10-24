#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>

class Dice
{
public:
	Dice();
	~Dice();

	void Roll();
	//keep track if dice is being held
	bool holdState;

	//actual value of the dice
	int diceValue;
};

