#include "EndGame.h"



EndGame::EndGame(Yahtzee game)
{
	gameOver = game;
	p1 = 0;
	p2 = 0;
	if (!font.loadFromFile("FSEX300.ttf")) { std::cout << "didnt get font"; }

	end.setFont(font);
	end.setCharacterSize(60);
	end.setPosition(Vector2f(0, 0));
	end.setFillColor(Color::Yellow);
	
	for (int i = 0; i < 15; i++)
	{
		p1 += gameOver.p1.scoreCard.values[i];
		p2 += gameOver.p2.scoreCard.values[i];

	}

	if (p1 > p2)
	{
		string P1 = "player 1 wins!!!";
		end.setString(P1);
		score.setString("Score:" + to_string(p1));
	
	}
	else if (p1 < p2)
	{
		string P2 = "player 2 wins!!!";
		end.setString(P2);
		score.setString("Score:" + to_string(p2));
		
	}
	else
	{
		string t = "wow! tie!!!";
		end.setString(t);
		score.setString("well, this is confusing");
	
	}
	score.setFont(font);
	score.setCharacterSize(40);
	score.setPosition(Vector2f(0, 70));
	score.setFillColor(Color::Yellow);

	if (!back.loadFromFile("back.png")) {}

	backButton.setSize(Vector2f(100, 60));
	backButton.setTexture(&back);
	backButton.setPosition(Vector2f(375, 375));

}


EndGame::~EndGame()
{
}

void EndGame::draw(sf::RenderWindow &window)
{
	window.draw(end);
	window.draw(score);
	window.draw(backButton);
}
bool EndGame::contains(RectangleShape button, Vector2f mousePosition)
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

bool EndGame::update(Vector2f mousePosition)
{
	if (contains(backButton, mousePosition))
	{
		return true;
	}
	return false;
}

