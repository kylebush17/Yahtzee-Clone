#include "Player.h"
Player::Player()
{
	playerName = "player unknown";
	

}

Player::Player(string name)
{
	playerName = name;
}

Player::~Player()
{

}

void Player::rollDice()
{
	for (int i = 0; i < 5; i++)
	{
		diceArray[i].Roll();
	}
}

bool Player::is_three_of_kind()
{
	for (int i = 1; i <= 6; i++)
	{
		int count = 0;
		for (int j = 0; j < 5; j++)
		{
			if (diceArray[j].diceValue == i)
				count++;

			if (count > 2)
				return true;
		}
	}
	return false;

}

bool Player::is_four_of_kind()
{
	for (int i = 1; i <= 6; i++)
	{
		int count = 0;
		for (int j = 0; j < 5; j++)
		{
			if (diceArray[j].diceValue == i)
				count++;

			if (count > 3)
				return true;
		}
	}
	return false;
}

bool Player::is_full_house()
{
	
	int dice[5];

	dice[0] = diceArray[0].diceValue;
	dice[1] = diceArray[1].diceValue;
	dice[2] = diceArray[2].diceValue;
	dice[3] = diceArray[3].diceValue;
	dice[4] = diceArray[4].diceValue;

	sort(dice, dice + 5);

	if ((((dice[0] == dice[1]) && (dice[1] == dice[2])) && // Three of a Kind
		(dice[3] == dice[4]) && // Two of a Kind
		(dice[2] != dice[3])) ||
		((dice[0] == dice[1]) && // Two of a Kind
		((dice[2] == dice[3]) && (dice[3] == dice[4])) && // Three of a Kind
			(dice[1] != dice[2])))
	{
		return true;
	}
	return false;
}

bool Player::is_yahtzee()
{
	for (int i = 1; i <= 6; i++)
	{
		int count = 0;
		for (int j = 0; j < 5; j++)
		{
			if (diceArray[j].diceValue == i)
				count++;

			if (count > 4)
				return true;
		}
	}
	return false;
}

int Player::sum_dice()
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += diceArray[i].diceValue;
	}
	return sum;
}

int Player::sum_ones()
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		if (diceArray[i].diceValue == 1)
			sum += 1;
	}
	return sum;
}

int Player::sum_twos()
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		if (diceArray[i].diceValue == 2)
			sum += 2;
	}
	return sum;
}

int Player::sum_threes()
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		if (diceArray[i].diceValue == 3)
			sum += 3;
	}
	return sum;
}

int Player::sum_fours()
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		if (diceArray[i].diceValue == 4)
			sum += 4;
	}
	return sum;
}

int Player::sum_fives()
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		if (diceArray[i].diceValue == 5)
			sum += 5;
	}
	return sum;
}

int Player::sum_sixes()
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		if (diceArray[i].diceValue == 6)
			sum += 6;
	}
	return sum;
}

