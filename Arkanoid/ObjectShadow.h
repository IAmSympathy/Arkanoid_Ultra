#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Ball.h"

using namespace sf;		// Namespace pour les objets de la librairie SFML
using namespace std;	// Namespace pour les objets de la librairie standard en C++

class ObjectShadow
{
private:
	std::string _type;

	sf::Clock _clock;		// À mettre avec les autres variables au début du main
	sf::Time _time;

	sf::RectangleShape _shadow;
	sf::Texture _texture;
	sf::IntRect _rectSprite;
public:
	ObjectShadow(std::string type);

	bool SetTexture();

	void move(RectangleShape type);


	void draw(sf::RenderWindow& window);
};

