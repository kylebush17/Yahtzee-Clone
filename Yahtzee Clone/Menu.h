#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
using namespace sf;
class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);

	sf::Text title;
	sf::RectangleShape buttons[3];
	sf::Texture playTexture;
	sf::Texture optionsTexture;
	sf::Texture exitTexture;
	sf::Font font;

	bool contains(RectangleShape button, Vector2f mousePosition);

	void reset();
	

	void handleMouseClick(Event &event, Vector2f mousePosition);

	int selectedIndex;
};

