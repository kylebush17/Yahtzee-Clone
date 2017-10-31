
#include "Yahtzee.h"
Yahtzee::Yahtzee()
{

}
Yahtzee::Yahtzee(float width, float height)
{
	p1 = Player("Player 1");
	p2 = Player("Player 2");
	currentPlayer = p1;
	player = 1;

	//initialize turn text to player 1 turn
	if (!font.loadFromFile("FSEX300.ttf")) { std::cout << "didnt get font"; }
	
	p1Name.setString("PLAYER 1 TOTAL SCORE: ");
	p1Name.setFont(font);
	p1Name.setPosition(Vector2f(400, 255));
	p1Name.setFillColor(Color::Yellow);

	p1Score.setString(to_string(0));
	p2Score.setString(to_string(0));
	p1Score.setFont(font);
	p2Score.setFont(font);
	p1Score.setPosition(Vector2f(500, 355));
	p1Score.setCharacterSize(40);
	p2Score.setCharacterSize(40);
	p2Score.setPosition(Vector2f(500, 555));
	p1Score.setFillColor(Color::Yellow);
	p2Score.setFillColor(Color::Yellow);

	p2Name.setString("PLAYER 2 TOTAL SCORE: ");
	p2Name.setFont(font);
	p2Name.setPosition(Vector2f(400, 455));
	p1Name.setCharacterSize(30);
	p2Name.setCharacterSize(30);
	p2Name.setFillColor(Color::Yellow);
	
	
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
	scoreValues[0].setString(to_string(currentPlayer.scoreCard.values[0]));
	scoreValues[1].setString(to_string(currentPlayer.scoreCard.values[1]));
	scoreValues[2].setString(to_string(currentPlayer.scoreCard.values[2]));
	scoreValues[3].setString(to_string(currentPlayer.scoreCard.values[3]));
	scoreValues[4].setString(to_string(currentPlayer.scoreCard.values[4]));
	scoreValues[5].setString(to_string(currentPlayer.scoreCard.values[5]));
	scoreValues[6].setString(to_string(currentPlayer.scoreCard.values[6]));
	scoreValues[7].setString(to_string(currentPlayer.scoreCard.values[7]));
	scoreValues[8].setString(to_string(currentPlayer.scoreCard.values[8]));
	scoreValues[9].setString(to_string(currentPlayer.scoreCard.values[9]));
	scoreValues[10].setString(to_string(currentPlayer.scoreCard.values[10]));
	scoreValues[11].setString(to_string(currentPlayer.scoreCard.values[11]));
	scoreValues[12].setString(to_string(currentPlayer.scoreCard.values[12]));
	scoreValues[13].setString(to_string(currentPlayer.scoreCard.values[13]));
	scoreValues[14].setString(to_string(currentPlayer.scoreCard.values[14]));
	
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

	//load texture for take buttons
	if(!takeTexture.loadFromFile("take.png")){}

	//apply texture to take buttons
	for (int i = 0; i < 15; i++)
	{
		takeButtons[i].setSize(Vector2f(50, 20));
		takeButtons[i].setPosition(Vector2f(285, 254 + (25 * i)));
		takeButtons[i].setTexture(&takeTexture);
	}

	turnComplete = false;
}
Yahtzee::~Yahtzee()
{

}

void Yahtzee::draw(RenderWindow &window)
{

	//draw whos turn it is
	window.draw(turnText);
	window.draw(p1Name);
	window.draw(p2Name);
	int sum = 0, sum2 = 0;
	for (int i = 0; i < 15; i++)
	{
		sum += p1.scoreCard.values[i];
		sum2 += p2.scoreCard.values[i];
	}
	p1Score.setString(to_string(sum));
	p2Score.setString(to_string(sum2));

	window.draw(p1Score);
	window.draw(p2Score);
	//draw the dice
	if (currentPlayer.numRolls > 0)
	{
		for (int i = 0; i < 5; i++)
		{
			window.draw(dice[i]);
			window.draw(buttons[i]);
		}
	}
	if (currentPlayer.numRolls < 3)
	{
		window.draw(rollButton);
	}
	for (int i = 0; i < 15; i++)
	{
		window.draw(labels[i]);
		window.draw(scoreValues[i]);
		window.draw(takeButtons[i]);
		
	}

}

bool Yahtzee::updateGameState(Vector2f mousePosition)
{
	

	if (currentPlayer.numRolls <= 3 )	//while the player can still roll
	{
		if (currentPlayer.numRolls > 0) {

			
			
			//check to see if the user has "taken" a score
			for (int i = 0; i < 15; i++)
			{

				if (contains(takeButtons[i], mousePosition))
				{
					if (i == 6)
					{
						//skip upper bonus 
					}
					else if (currentPlayer.scoreCard.used[i]) {
							cout << "already used combo" << endl;
						}
					else						{
						if (!takePressed.loadFromFile("takepressed.png")) {}
						takeButtons[i].setTexture(&takePressed);
						currentPlayer.scoreCard.used[i] = true;
						int score = calculateScore(i);
						currentPlayer.scoreCard.values[i] = score;
						scoreValues[i].setString(to_string(score));
						turnComplete = true;
					}



				}

				break;

			}
		}
			
	

		//check to see if any dice need to be held
		for (int i = 0; i < 5; i++)
		{
			if (contains(buttons[i], mousePosition))
			{
				if (currentPlayer.diceArray[i].holdState == true)
				{
					currentPlayer.diceArray[i].holdState = false;
					if (!buttonTextures[i].loadFromFile("keep.png")) {}
					buttons[i].setTexture(&buttonTextures[i]);
				}
				else
				{
					currentPlayer.diceArray[i].holdState = true;
					if (!buttonTextures[i].loadFromFile("keeppressed.png")) {}
					buttons[i].setTexture(&buttonTextures[i]);
				}
			
			}
			
		}
		if (contains(rollButton, mousePosition))
		{
			
			currentPlayer.rollDice();
			cout << "just rolled the dice..." << endl;
			//update the dice pictures
			roll();
			cout << "dice:";
			for (int i = 0; i < 5; i++)
			{
				cout << currentPlayer.diceArray[i].diceValue << " ";
			}
			cout << endl;
		}
		if (currentPlayer.is_yahtzee())
		{
			if (!takePressed.loadFromFile("takepressed.png")) {}

			if (currentPlayer.numYahtzee == 0)
			{
				currentPlayer.scoreCard.values[13] = 50;
				takeButtons[13].setTexture(&takePressed);
				currentPlayer.scoreCard.used[13] = true;
				scoreValues[13].setString(to_string(50));
				turnComplete = true;
				currentPlayer.numYahtzee++;
			}
			else if (currentPlayer.numYahtzee == 1)
			{
				currentPlayer.scoreCard.values[14] = 100;
				takeButtons[14].setTexture(&takePressed);
				currentPlayer.scoreCard.used[14] = true;
				scoreValues[14].setString(to_string(100));
				turnComplete = true;
				currentPlayer.numYahtzee++;
			}
		}
		

		
	}
	if (currentPlayer.numRolls > 0) {
		//check to see if the user has "taken" a score
		for (int i = 0; i < 15; i++)
		{
			

			if (contains(takeButtons[i], mousePosition))
			{
				if (i == 6)
				{
					//skip upper bonus 
				}
				else if (currentPlayer.scoreCard.used[i]) {
					cout << "already used combo" << endl;
				}

				else
				{
					if (!takePressed.loadFromFile("takepressed.png")) {}
					takeButtons[i].setTexture(&takePressed);
					currentPlayer.scoreCard.used[i] = true;
					int score = calculateScore(i);
					currentPlayer.scoreCard.values[i] = score;
					scoreValues[i].setString(to_string(score));
					turnComplete = true;
				}

				break;

			}
		}
	}
	return true;
}

bool Yahtzee::contains(RectangleShape button, Vector2f mousePosition)
{


	FloatRect bounds = button.getGlobalBounds();

	float x1 = bounds.left;
	float x2 = bounds.top;
	float m1 = mousePosition.x;
	float m2 = mousePosition.y;
	
	
	if (m1<x1 || m1 > x1 + bounds.width || m2<x2 || m2> x2 + bounds.height)
		return false;

	return true;
}

void Yahtzee::roll()
{
	for (int i = 0; i < 5; i++)
	{
		switch (currentPlayer.diceArray[i].diceValue)
		{
		case 1:
			dice[i].setTexture(&diceTextures[0]);
			break;
		case 2:
			dice[i].setTexture(&diceTextures[1]);
			break;
		case 3:
			dice[i].setTexture(&diceTextures[2]);
			break;
		case 4:
			dice[i].setTexture(&diceTextures[3]);
			break;
		case 5:
			dice[i].setTexture(&diceTextures[4]);
			break;
		case 6:
			dice[i].setTexture(&diceTextures[5]);
			break;

		}
	}
}

int Yahtzee::calculateScore(int index)
{
	int score = 0;
	bool success = false;
	switch (index)
	{
	case 0:
	
		score = currentPlayer.sum_ones();
		break;
	case 1:
		score = currentPlayer.sum_twos();
		break;
	case 2:
		score = currentPlayer.sum_threes();
		break;
	case 3:
		score = currentPlayer.sum_fours();
		break;
	case 4:
		score = currentPlayer.sum_fives();
		break;
	case 5:
		score = currentPlayer.sum_sixes();
		break;
	case 6:
		
		break;
	case 7:
		success = currentPlayer.is_three_of_kind();
		if (success) { score = currentPlayer.sum_dice(); }
		break;
	case 8:
		success =  currentPlayer.is_four_of_kind();
		if (success) { score = currentPlayer.sum_dice(); }
		break;
	case 9:
		success = currentPlayer.is_full_house();
		if (success) { score = 25; }
		else { score = 0; }
		break; 
	case 10:
		success = currentPlayer.is_small_straight();
		if (success) { score = 30; }
		else { score = 0; }
		break;
	case 11:
		success =  currentPlayer.is_large_straight();
		if (success) { score = 40; }
		else { score = 0; }
		break;
	case 12:
		score = currentPlayer.sum_dice();
		break;
	case 13:
		success  = currentPlayer.is_yahtzee();
		if (success)
		{
			score = 50;
		}
		else { score = 0; }
		break;
	case 14:
		success = currentPlayer.is_yahtzee();
		if (success && currentPlayer.scoreCard.used[13] == true )
		{
			score = 100;
		}
		else { score = 0; }
		break;
	}
	return score;
}

bool Yahtzee::resetState()
{
	int score = checkBonus(), i = 0;
	bool isBonus = true;

	if (score > 0)
	{
		currentPlayer.scoreCard.used[6] = true;
		currentPlayer.scoreCard.values[6] = score;
	}
	else {
		for (i = 0; i < 6; i++)
		{
			if (currentPlayer.scoreCard.used[i] == false)
				isBonus = false;
		}
		if (isBonus )
		{
			currentPlayer.scoreCard.used[6] = true;
			currentPlayer.scoreCard.values[6] = score;
		}
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
		buttons[i].setTexture(&buttonTextures[i]);
	}

	//display the score values for the current player
	scoreValues[0].setString(to_string(currentPlayer.scoreCard.values[0]));
	scoreValues[1].setString(to_string(currentPlayer.scoreCard.values[1]));
	scoreValues[2].setString(to_string(currentPlayer.scoreCard.values[2]));
	scoreValues[3].setString(to_string(currentPlayer.scoreCard.values[3]));
	scoreValues[4].setString(to_string(currentPlayer.scoreCard.values[4]));
	scoreValues[5].setString(to_string(currentPlayer.scoreCard.values[5]));
	scoreValues[6].setString(to_string(currentPlayer.scoreCard.values[6]));
	scoreValues[7].setString(to_string(currentPlayer.scoreCard.values[7]));
	scoreValues[8].setString(to_string(currentPlayer.scoreCard.values[8]));
	scoreValues[9].setString(to_string(currentPlayer.scoreCard.values[9]));
	scoreValues[10].setString(to_string(currentPlayer.scoreCard.values[10]));
	scoreValues[11].setString(to_string(currentPlayer.scoreCard.values[11]));
	scoreValues[12].setString(to_string(currentPlayer.scoreCard.values[12]));
	scoreValues[13].setString(to_string(currentPlayer.scoreCard.values[13]));
	scoreValues[14].setString(to_string(currentPlayer.scoreCard.values[14]));

	for (int i = 0; i < 15; i++)
	{
		if (currentPlayer.scoreCard.used[i] == true)
		{
			if (!takePressed.loadFromFile("takepressed.png")) {}
			takeButtons[i].setTexture(&takePressed);
		}
		else
		{
			if(takeTexture.loadFromFile("take.png"))
			{ }
			takeButtons[i].setTexture(&takeTexture);
		}
	}

	for (int i = 0; i < 5; i++)
	{
		currentPlayer.diceArray[i].holdState = false;
	}
	currentPlayer.numRolls = 0;
	return true;
}

int Yahtzee::checkBonus()
{
	bool upper = true;
	int sum = 0;
	int score = 0;
	for (int i = 0; i < 6; i++)
	{
	
		sum += currentPlayer.scoreCard.values[i];
	}
	
	if (upper && sum > 35) { score = 35; }
	return score;
}

bool Yahtzee::isGameOver()
{
	for (int i = 0; i < 15; i++)
	{
		if (p1.scoreCard.used[i] != true || p2.scoreCard.used[i] != true)
		{
		
			return false;
		}
	}
	return true;
}

