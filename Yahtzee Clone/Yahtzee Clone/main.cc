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
	sf::RenderWindow mainWindow(sf::VideoMode(750, 750), "Yahtzee Clone!");
	Menu menu(mainWindow.getSize().x, mainWindow.getSize().y);
	Yahtzee game(mainWindow.getSize().x, mainWindow.getSize().y);
	/*Text text;
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

	*/
	


	while (mainWindow.isOpen())
	{
		sf::Event event;
		while (mainWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
				cout << "mouse button pressed" << endl;
				switch (event.key.code)
				{
				case sf::Mouse::Left:
					if (menu.selectedIndex == -1) {	//handle menu input if at main menu, otherwise we will be handling other mouse input
						cout << "mouse 1 has been pressed" << endl;
						Vector2f position = Vector2f(Mouse::getPosition(mainWindow));
						menu.handleMouseClick(event, position);
					}
				
				}
				break;
			}
			if (event.type == sf::Event::Closed)
				mainWindow.close();
		}
		
		mainWindow.clear();

		if (menu.selectedIndex == 0)
		{
			game.draw(mainWindow);
		}
		else if (menu.selectedIndex == 1)
		{
			//draw rules
		}
		else if (menu.selectedIndex == 2)
		{
			//exit game
			mainWindow.close();
		}
		else
		{
			menu.draw(mainWindow);
		}
		
		mainWindow.display();
	}

	return 0;
}