#include "Menu.h"



Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("FSEX300.ttf")) { std::cout << "didnt get font"; }
	if (!playTexture.loadFromFile("playbutton.png")){
	}
	if (!optionsTexture.loadFromFile("optionsbutton.png")) {

	}
	if (!exitTexture.loadFromFile("exitbutton.png")) {

	}

	title.setString("Yahtzee Clone");
	title.setFont(font);
	title.setCharacterSize(40);
	title.setPosition(Vector2f(width/4, 50));
	title.setFillColor(Color::Cyan);

	buttons[0].setTexture(&playTexture);
	buttons[0].setSize(Vector2f(120, 70));
	buttons[0].setPosition(Vector2f(width / 4 + (width/8), 110));
	
	buttons[1].setTexture(&optionsTexture);
	buttons[1].setSize(Vector2f(120, 70));
	buttons[1].setPosition(Vector2f(width / 4 + (width / 8), 190));
	
	buttons[2].setTexture(&exitTexture);
	buttons[2].setSize(Vector2f(120, 70));
	buttons[2].setPosition(Vector2f(width / 4 + (width / 8), 270));
	
	selectedIndex = -1;
	//buttons[2].setPosition(Vector2f(width / 2, (height / 4) + 4));
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	window.draw(title);
	for (int i = 0; i < 3; i++)
	{
		window.draw(buttons[i]);
	}
}

void Menu::handleMouseClick(Event &event, Vector2f mousePosition)
{
	

	FloatRect playBounds = buttons[0].getLocalBounds();
	float px = buttons[0].getPosition().x, py = buttons[0].getPosition().y;
	float ox = buttons[1].getPosition().x, oy = buttons[1].getPosition().y;
	float ex = buttons[2].getPosition().x, ey = buttons[2].getPosition().y;
	if (mousePosition.x < px+(px/2) && mousePosition.x > px - (px/2) && mousePosition.y <py + (py/2) && mousePosition.y > py-(py/2))
	{
		if(!playTexture.loadFromFile("playpressed.png")){}
		if (!optionsTexture.loadFromFile("optionsbutton.png")) {}
		if (!exitTexture.loadFromFile("exitbutton.png")) {}
		buttons[0].setTexture(&playTexture);
		buttons[1].setTexture(&optionsTexture);
		buttons[2].setTexture(&exitTexture);
		selectedIndex = 0;
	}
	else if (mousePosition.x < ox + (ox / 2) && mousePosition.x > ox - (ox / 2) && mousePosition.y < oy + (oy / 2) && mousePosition.y > oy - (oy / 2))
	{
		if (!optionsTexture.loadFromFile("optionspressed.png")) {}
		if (!playTexture.loadFromFile("playbutton.png")) {}
		if (!exitTexture.loadFromFile("exitbutton.png")) {}
		buttons[0].setTexture(&playTexture);
		buttons[2].setTexture(&exitTexture);
		buttons[1].setTexture(&optionsTexture);
		selectedIndex = 1;
	}
	else if (mousePosition.x < ex + (ex / 2) && mousePosition.x > ex - (ex / 2) && mousePosition.y < ey + (ey / 2) && mousePosition.y > ey - (ey / 2))
	{
		if (!exitTexture.loadFromFile("exitpressed.png")) {}
		if (!playTexture.loadFromFile("playbutton.png")) {}
		if (!optionsTexture.loadFromFile("optionsbutton.png")) {}
		buttons[2].setTexture(&exitTexture);
		buttons[1].setTexture(&optionsTexture);
		buttons[0].setTexture(&playTexture);
		selectedIndex = 2;
	}
	else
	{
		if (!playTexture.loadFromFile("playbutton.png")) {
		}
		if (!optionsTexture.loadFromFile("optionsbutton.png")) {

		}
		if (!exitTexture.loadFromFile("exitbutton.png")) {

		}
		buttons[2].setTexture(&exitTexture);
		buttons[1].setTexture(&optionsTexture);
		buttons[0].setTexture(&playTexture);
		selectedIndex = -1;
	}

}