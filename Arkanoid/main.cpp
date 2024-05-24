#include <SFML/Graphics.hpp>
#include <iostream>
#include "ObjectShadow.h"
#include "Menu.h"
#include "UserInterface.h"
#include "Game.h"
#include "Brick.h"
#include "Player.h"
#include "Ball.h"

using namespace sf;
using namespace std;

int main() {

	//Initialize
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Arkanoid Ultra!");
	window.setFramerateLimit(144);

	Game game;
	Menu menu;
	UserInterface userInterface;
	int level = 0;
	int section = 1;
	int episode = 0;
	enum state { TITLE, EPISODES, LEVELS, QUIT, INSTRUCTION };
	menu.Initialize();

	//Main loop
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}

		window.clear(Color::Black);

		//Menu logic
		if (level == 0)
		{
			switch (menu.GetState())
			{
			case TITLE:
				if (menu.ChangeOption() == 1)
				{
					menu.SetState(EPISODES);

				}
				else if ((menu.ChangeOption() == 2))
				{
					window.close();
				}
				break;
			case EPISODES:
					episode = menu.ChangeOption();
					if (episode != 0)
					{
						menu.SetState(LEVELS);
					}
				break;
			case LEVELS:
				level = menu.ChangeOption();
				if (level != 0)
					game.StartLevel(level,section);
				break;
			}
			menu.updateText();
			menu.HighlightOption(window);
			menu.IsKeyPressed(event);
			menu.Draw(window);
		}
		//Game logic
		else
		{
			game.Play();
			userInterface.updateStats(game.GetScore(), game.GetHighScore(), game.GetLives(), game.GetLevel());
			game.Draw(window);
			userInterface.DrawInGameStats(window);
		}


		window.display();
	}
}
