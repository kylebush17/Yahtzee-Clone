#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
class Scorecard
{
public:
	Scorecard();
	~Scorecard();

	
	//booleans keep track of whether each value has been used.
	bool ones;
	bool twos;
	bool threes;
	bool fours;
	bool fives;
	bool sixes;
	bool threeOfKind;
	bool fourOfKind;
	bool fullHouse;
	bool smallStraight;
	bool largeStraight;
	bool yahtzee;
	bool chance;
	bool upperBonus;
	bool yahtzeeBonus;

	//integers keep track of actual values of the scores
	int ones_value;
	int twos_value;
	int threes_value;
	int fours_value;
	int fives_value;
	int sixes_value;
	int threeOfKind_value;
	int fourOfKind_value;
	int fullHouse_value;
	int smallStraight_value;
	int largeStraight_value;
	int chance_value;
	int yahtzee_value;
	int upperBonus_values;
	int yahtzeeBonus_value;


	void draw(sf::RenderWindow &window);

	
};

