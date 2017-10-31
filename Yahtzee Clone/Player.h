#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
#include <string>
#include <algorithm>

#include "Scorecard.h"
#include "Dice.h"

using namespace std;

class Player
{
public:
	Player();
	Player(string name);
	~Player();
	
	void rollDice();	// roll the dice...

	int sum_ones();
	int sum_twos();
	int sum_threes();
	int sum_fours();
	int sum_fives();
	int sum_sixes();

	//functions check if the following combos can be made
	bool is_three_of_kind();
	bool is_four_of_kind();
	bool is_full_house();
	bool is_yahtzee();
	bool is_small_straight();
	bool is_large_straight();

	int sum_dice();

	int numYahtzee;
	Dice diceArray[5];
	Scorecard scoreCard;
	string playerName;
	int numRolls;
	

};

#endif // !PLAYER_H