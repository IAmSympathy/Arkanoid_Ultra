#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Ball.h"
#include "ObjectShadow.h"

using namespace sf;		// Namespace pour les objets de la librairie SFML
using namespace std;	// Namespace pour les objets de la librairie standard en C++

int main() {

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "My window");
	window.setFramerateLimit(144);
	Game game;
	Player player;
	ObjectShadow playerShadow("Player");
	Ball ball;
	ObjectShadow ballShadow("Ball");

	ball.SetTexture();
	ballShadow.SetTexture();
	int ballCollision;

	player.setTexture();
	playerShadow.SetTexture();

	game.SetBackground(1);
	game.SetBorder();
	game.StartGame(1);

	// on fait tourner le programme jusqu'� ce que la fen�tre soit ferm�e
	while (window.isOpen())
	{
		// on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente     it�ration
		Event event;
		while (window.pollEvent(event))
		{
			// �v�nement "fermeture demand�e" : on ferme la fen�tre
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}

		// Render
		window.clear(Color::Black);



		//Actions du jeu
		player.setIsDead(ball.GetIsUnderMap());

		//Actions du joueur
		player.move();
		playerShadow.move(player.getPlayer());
		player.idleAnimation();

		//Actions de la balle
		ballCollision = game.checkCollision(player, ball);
		ball.checkCollision(ballCollision);
		ball.move();

		ballShadow.move(ball.getBall());

		//Draw
		game.draw(window);

		if (player.GetIsDead() == false)
		{
			playerShadow.draw(window);
			ballShadow.draw(window);
			ball.draw(window);
		}

		player.draw(window);
		game.drawBorder(window);

		window.display();
	}
}
