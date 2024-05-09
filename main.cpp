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

	// on fait tourner le programme jusqu'� ce que la fen�tre soit ferm�e
	while (window.isOpen())
	{
		// on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente     it�ration
		Event event;
		// effacement de la fen�tre en noir
		window.clear(Color::Black);
		// c'est ici qu'on dessine tout
		window.draw(player.getPlayer());
		// fin de la frame courante, affichage de tout ce qu'on a dessin�
		window.display();

		while (window.pollEvent(event))
		{
			// �v�nement "fermeture demand�e" : on ferme la fen�tre
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		player.move();
		player.idleAnimation();
	}
}
