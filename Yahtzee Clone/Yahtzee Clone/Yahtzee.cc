
#include "Yahtzee.h"

Yahtzee::Yahtzee(float width, float height)
{
	p1 = Player("Player 1");
	p2 = Player("Player 2");
	currentPlayer = p1;

	//initialize turn text to player 1 turn
	if (!font.loadFromFile("FSEX300.ttf")) { std::cout << "didnt get font"; }
	turnText.setString("Player 1's turn!");
	turnText.setFont(font);
	turnText.setFillColor(Color::Cyan);
	turnText.setPosition(Vector2f(5, 5));

	//load in all of the dice face textures.
	if(!diceTextures[0].loadFromFile("die_face_1.png")){}
	if(!diceTextures[1].loadFromFile("die_face_2.png")){}
	if (!diceTextures[2].loadFromFile("die_face_3.png")) {}
	if (!diceTextures[3].loadFromFile("die_face_4.png")) {}
	if (!diceTextures[4].loadFromFile("die_face_5.png")) {}
	if (!diceTextures[5].loadFromFile("die_face_6.png")) {}

	//apply the dice textures to the dice rectangle shapes
	for (int i = 0; i < 6; i++)
	{
		
		dice[i].setSize(Vector2f(50, 50));
		dice[i].setPosition(Vector2f(((width/12) * i )+ width/4, 50));
		dice[i].setTexture(&diceTextures[i]);
	}

	//load textures for buttons
	if (!buttonTextures[0].loadFromFile("keep.png")) {}
	if (!buttonTextures[1].loadFromFile("keep.png")) {}
	if (!buttonTextures[2].loadFromFile("keep.png")) {}
	if (!buttonTextures[3].loadFromFile("keep.png")) {}
	if (!buttonTextures[4].loadFromFile("keep.png")) {}
	if (!buttonTextures[5].loadFromFile("keep.png")) {}

	//apply the textures to the buttons
	for (int i = 0; i < 6; i++)
	{
		buttons[i].setSize(Vector2f(50, 20));
		buttons[i].setPosition(Vector2f(((width / 12)*i) + width / 4, 120));
		buttons[i].setTexture(&buttonTextures[i]);
	}
	
	//load texture for roll button
	if(!rollTexture.loadFromFile("roll.png")){}
	
	//apply the texture
	rollButton.setSize(Vector2f(100, 50));
	float x = rollButton.getSize().x;
	rollButton.setPosition(Vector2f(width/2 - 55, 150));
	rollButton.setTexture(&rollTexture);

	//initialize current scorecard labels and values
	//set strings for lables
	labels[0].setString("Ones: ");
	labels[1].setString("Twos: ");
	labels[2].setString("Threes: ");
	labels[3].setString("Fours: ");
	labels[4].setString("Fives: ");
	labels[5].setString("Sixes: ");
	labels[6].setString("Upper Bonus: ");
	labels[7].setString("Three of a Kind: ");
	labels[8].setString("Four of a kind: ");
	labels[9].setString("Full House: ");
	labels[10].setString("Small Straight: ");
	labels[11].setString("Large Straight: ");
	labels[12].setString("Chance: ");
	labels[13].setString("Yahztee: ");
	labels[14].setString("Yahtzee Bonus: ");
	

	//set strings for score values
	scoreValues[0].setString(to_string(currentPlayer.scoreCard.ones_value));
	scoreValues[1].setString(to_string(currentPlayer.scoreCard.twos_value));
	scoreValues[2].setString(to_string(currentPlayer.scoreCard.threes_value));
	scoreValues[3].setString(to_string(currentPlayer.scoreCard.fours_value));
	scoreValues[4].setString(to_string(currentPlayer.scoreCard.fives_value));
	scoreValues[5].setString(to_string(currentPlayer.scoreCard.sixes_value));
	scoreValues[6].setString(to_string(currentPlayer.scoreCard.upperBonus_values));
	scoreValues[7].setString(to_string(currentPlayer.scoreCard.threeOfKind_value));
	scoreValues[8].setString(to_string(currentPlayer.scoreCard.fourOfKind_value));
	scoreValues[9].setString(to_string(currentPlayer.scoreCard.fullHouse_value));
	scoreValues[10].setString(to_string(currentPlayer.scoreCard.smallStraight_value));
	scoreValues[11].setString(to_string(currentPlayer.scoreCard.largeStraight_value));
	scoreValues[12].setString(to_string(currentPlayer.scoreCard.chance_value));
	scoreValues[13].setString(to_string(currentPlayer.scoreCard.yahtzee_value));
	scoreValues[14].setString(to_string(currentPlayer.scoreCard.yahtzeeBonus_value));
	
	//initialize fonts, color, and position for above text
	for (int i = 0; i < 15; i++)
	{
		labels[i].setFont(font);
		scoreValues[i].setFont(font);
		labels[i].setFillColor(Color::Cyan);
		scoreValues[i].setFillColor(Color::Cyan);
		labels[i].setPosition(Vector2f(25, 250 + (25 * i)));
		scoreValues[i].setPosition(Vector2f(225, 250 + (25 * i)));
		labels[i].setCharacterSize(24);
		scoreValues[i].setCharacterSize(24);
	}
}
Yahtzee::~Yahtzee()
{

}

void Yahtzee::draw(RenderWindow &window)
{
	//draw whos turn it is
	window.draw(turnText);
	//draw the dice
	for (int i = 0; i < 6; i++)
	{
		window.draw(dice[i]);
		window.draw(buttons[i]);
	}
	if (currentPlayer.numRolls < 4)
	{
		window.draw(rollButton);
	}
	for (int i = 0; i < 15; i++)
	{
		window.draw(labels[i]);
		window.draw(scoreValues[i]);
	}

}