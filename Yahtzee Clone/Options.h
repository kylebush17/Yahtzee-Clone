#pragma once
#include "Yahtzee.h"
class Options
{
public:
	Options();
	~Options();
	void draw(sf::RenderWindow &window);
	bool contains(RectangleShape button, Vector2f mousePosition);
	bool update(Vector2f mousePosition);

	
	sf::Text Rules;
	sf::Font font;
	sf::RectangleShape backButton;
	sf::Texture back;

};

