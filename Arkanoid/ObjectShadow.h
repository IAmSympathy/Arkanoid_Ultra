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

	const int _playerWidth = 32;
	const int _playerHeight = 8;
	const int _ballWidth = 5;
	const int _ballHeight = 4;
	const int sizeMultiplier = 4;
public:
	ObjectShadow();
	ObjectShadow(std::string type);

	bool SetTexture();
	void SetType(std::string type);

	void move(RectangleShape type);


	void draw(sf::RenderWindow& window);
};

