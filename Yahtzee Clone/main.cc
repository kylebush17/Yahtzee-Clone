// -- Programmer: Kyle Bush
// -- Project Title: Yahtzee Clone
// -- Date last modified: 10/22/17
#include "Yahtzee.h"
#include "EndGame.h"
#include "Options.h"



#include <ctime>
#include <cstdlib>

using namespace sf;
using namespace std;
int main()
{
	srand((unsigned int)time(NULL));	//-- seed for random number generation
	sf::RenderWindow mainWindow(sf::VideoMode(750, 750), "Yahtzee Clone!");
	bool finished = false;
	Menu menu(mainWindow.getSize().x, mainWindow.getSize().y);
	Yahtzee game(mainWindow.getSize().x, mainWindow.getSize().y);
	
	Options options;
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
		sf::Event event2;
		EndGame end(game);
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
					else if (menu.selectedIndex == 0)
					{
						Vector2f position = Vector2f(Mouse::getPosition(mainWindow));
						game.updateGameState(position);
						if (game.turnComplete == true)
						{
							game.player++;
							if (game.player % 2 == 0)
							{
								game.turnText.setString("Player 2's Turn!");
								game.p1 = game.currentPlayer;
								game.currentPlayer = game.p2;
								game.turnComplete = false;
								game.resetState();
							}
							else
							{
								game.turnText.setString("Player 1's Turn!");
								game.p2 = game.currentPlayer;
								game.currentPlayer = game.p1;
								game.turnComplete = false;
								game.resetState();
							}
						}
					}
					else if (menu.selectedIndex == 1)
					{
						//options selected
						Vector2f position = Vector2f(Mouse::getPosition(mainWindow));
						if (options.update(position))
						{
							menu.selectedIndex = -1;
							menu.reset();
						}
					}
					else if (menu.selectedIndex == 4)
					{
						//in end of game, need to get mouse button
						Vector2f position = Vector2f(Mouse::getPosition(mainWindow));
						if (end.update(position))
						{
							menu.selectedIndex = -1;
							menu.reset();
							//need to figure out a way to reset the game here...
							bool finished = true;
						}
					}
					
				
				}
				break;
			}
			if (event.type == sf::Event::Closed)
				mainWindow.close();
		}
		
		mainWindow.clear();

		if (menu.selectedIndex == 0||menu.selectedIndex == 4)
		{
			/*if (game.currentPlayer.is_yahtzee() && game.currentPlayer.numYahtzee <2)
			{
				mainWindow.clear();
				Font font;
				if (!font.loadFromFile("FSEX300.ttf")) { std::cout << "didnt get font"; }
				//draw yahztee screen;
				sf::Text yahtzee;
				yahtzee.setString("YAHTZEE!!!");
				yahtzee.setPosition(Vector2f(250, 250));
				yahtzee.setFillColor(Color::Yellow);
				yahtzee.setFont(font);
				yahtzee.setCharacterSize(60);
				mainWindow.draw(yahtzee);
				
				mainWindow.clear();

			}*/
			if(!game.isGameOver())
				game.draw(mainWindow);
			else
			{
				menu.selectedIndex = 4;
				
				end.draw(mainWindow);
				//draw the end of game screen, declare winner, save high score to file (optional)


			}
		}
		else if (menu.selectedIndex == 1)
		{
			//draw rules
			options.draw(mainWindow);

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