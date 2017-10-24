#pragma once
#include <iostream>
#include "Dice.h"
#include "Player.h"
#include "Scorecard.h"
#include "Menu.h"

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Yahtzee
{
public:
	Yahtzee(float width, float height);
	~Yahtzee();

	void draw(RenderWindow &window);

	Font font;
	Text turnText; //text that displays whos turn it is.
	
	RectangleShape dice[6]; //drawable dice
	Texture diceTextures[6]; //textures for the drawble dice
	
	Player p1;
	Player p2;
	Player currentPlayer; //keeps track of whos turn it is
	
	//buttons to keep track of which dice are to be held
	RectangleShape buttons[6];
	Texture buttonTextures[6];

	//roll button
	RectangleShape rollButton;
	Texture rollTexture;

	//labels and values for current player scorecard
	Text labels[15];
	Text scoreValues[15];
	

};