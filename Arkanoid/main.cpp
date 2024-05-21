#include <SFML/Graphics.hpp>
#include <iostream>
#include "Brick.h"
#include "ObjectShadow.h"
#include "Game.h"
#include "Player.h"
#include "Ball.h"
#include "Interface.h"
using namespace sf;		
using namespace std;	

int main() {

	//Initialize
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Arkanoid Ultra!");
	window.setFramerateLimit(144);

	Game game;
	Interface interface;
	interface.Initialize();
	game.StartLevel(1);

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

		//Game logic
		game.Play();
		interface.updateStats(game.GetScore(),game.GetHighScore(), game.GetLives(), game.GetLevel());
		game.Draw(window);
		interface.DrawInGameStats(window);

		window.display();
	}
}
