#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;		// Namespace pour les objets de la librairie SFML
using namespace std;	// Namespace pour les objets de la librairie standard en C++

class Game
{
private:
	sf::Texture _textureBG;
	sf::Sprite _background;

public:
	Game();

	bool bgSetTexture();

	sf::Sprite getBackground();
};

