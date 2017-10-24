// -- Programmer: Kyle Bush
// -- Project Title: Yahtzee Clone
// -- Date last modified: 10/22/17
#include "Yahtzee.h"



#include <ctime>
#include <cstdlib>

using namespace sf;
using namespace std;
int main()
{
	srand((unsigned int)time(NULL));	//-- seed for random number generation
	sf::RenderWindow mainWindow(sf::VideoMode(500, 500), "Yahtzee Clone!");
	Text text;
	Font font;

	Texture texture;
	
	if(!texture.loadFromFile("playbutton.png")){}
	
	RectangleShape playbutton(Vector2f(120.0, 70.0));
	playbutton.setTexture(&texture);
	playbutton.setPosition(Vector2f(250, 250));


	
	//for now this is the menu screen

	font.loadFromFile("Colleged.ttf");
	text.setString("YAHTZEE CLONE!");
	text.setFont(font);
	text.setPosition(Vector2f(25, 50.0));
	text.setCharacterSize(40);
	text.setColor(Color::Cyan);
	text.setFillColor(Color::Cyan);

	
	


	while (mainWindow.isOpen())
	{
		sf::Event event;
		while (mainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				mainWindow.close();
		}
		
		mainWindow.clear();
		mainWindow.draw(text);
		mainWindow.draw(playbutton);
		mainWindow.display();
	}

	return 0;
}