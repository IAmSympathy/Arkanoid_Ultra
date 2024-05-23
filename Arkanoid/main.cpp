#include <SFML/Graphics.hpp>
#include <iostream>
#include "ObjectShadow.h"
#include "Interface.h"
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
	Interface interface;
	int level = 0;
	int section = 1;
	interface.Initialize();


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
			if (interface.ChangeOption() == "PLAY")
			{
				level = 1;
				section = 1;
				game.StartLevel(level, section);
			}
			interface.HighlightOption(window);
			interface.DrawTitleScreen(window);
		}
		//Game logic
		else
		{
			game.Play();
			interface.updateStats(game.GetScore(), game.GetHighScore(), game.GetLives(), game.GetLevel());
			game.Draw(window);
			interface.DrawInGameStats(window);
		}


		window.display();
	}
}
