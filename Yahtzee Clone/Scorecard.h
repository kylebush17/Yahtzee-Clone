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
	bool used[15];

	//integers keep track of actual values of the scores
	int values[15];


	void draw(sf::RenderWindow &window);

	
};

