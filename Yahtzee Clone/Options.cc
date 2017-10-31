#include "Options.h"



Options::Options()
{
	Rules.setString("The option of the game is to fill your scorecard \nwith the highest possible score...\n\nyou get 3 rolls to get the\nbest possible combination of dice\n\nSCORING:\n\nUPPER SECTION:\nones:sum of ones\ntwos:sum of twos\nthrees:sum of threes\nfours:sum of fours\nfives:sum of fives\nsixes:sum of sixes\nUPPER BONUS:35 if all upper values > 35 summed\nthree of a kind:sum of dice\nfour of a kind:sum of dice\nfull house:two of a kind AND three of a kind (25)\nsmall straight: sequence of 4 (30)\nlarge straight: sequence of 5 (40)\nyahtzee:5 of a kind (50 for first, 100 for second)\n");
	if (!font.loadFromFile("FSEX300.ttf")) { std::cout << "didnt get font"; }

	Rules.setFont(font);
	Rules.setCharacterSize(25);
	Rules.setPosition(Vector2f(0, 0));
	Rules.setFillColor(Color::Yellow);


	if(!back.loadFromFile("back.png")){}

	backButton.setSize(Vector2f(100, 60));
	backButton.setTexture(&back);
	backButton.setPosition(Vector2f(600, 600));
}


Options::~Options()
{

}

void Options::draw(sf::RenderWindow &window)
{
	window.draw(Rules);
	window.draw(backButton);
}
 
bool Options::contains(RectangleShape button, Vector2f mousePosition)
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

bool Options::update(Vector2f mousePosition)
{
	if (contains(backButton, mousePosition))
	{
		return true;
	}
	return false;
}