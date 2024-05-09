#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

using namespace sf;		// Namespace pour les objets de la librairie SFML
using namespace std;	// Namespace pour les objets de la librairie standard en C++

int main() {

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "My window");
	window.setFramerateLimit(60);
	Player player;
	player.setTexture();
	window.draw(player.getPlayer());

	IntRect _rectSprite(0, 0, 80, 20);

	// on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
	while (window.isOpen())
	{
		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente     itération
		Event event;
		// effacement de la fenêtre en noir
		window.clear(Color::Black);
		// c'est ici qu'on dessine tout
		window.draw(player.getPlayer());
		// fin de la frame courante, affichage de tout ce qu'on a dessiné
		window.display();

		while (window.pollEvent(event))
		{
			// évènement "fermeture demandée" : on ferme la fenêtre
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		player.move();
		player.idleAnimation();
	}
}
