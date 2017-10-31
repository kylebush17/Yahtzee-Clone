#pragma once
#include "Yahtzee.h"
class EndGame
{
public:
	EndGame(Yahtzee game);
	~EndGame();

	void draw(sf::RenderWindow &window);
	bool update(Vector2f mousePosition);
	bool contains(RectangleShape button, Vector2f mousePosition);



	Yahtzee gameOver;
	sf::Text end;
	sf::Text score;
	sf::Font font;
	sf::RectangleShape backButton;
	sf::Texture back;
	int p1;
	int p2;
	int winScore;

};

