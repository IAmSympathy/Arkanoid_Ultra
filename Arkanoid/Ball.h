#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace sf;		// Namespace pour les objets de la librairie SFML
using namespace std;	// Namespace pour les objets de la librairie standard en C++

class Ball
{
private:
	sf::RectangleShape _ball;
	sf::Texture _texture;
	sf::IntRect _rectSprite;

	sf::Clock _clock;		// À mettre avec les autres variables au début du main
	sf::Clock _clockSprite;
	sf::Time _time;

	sf::SoundBuffer _buffer;
	sf::Sound _sound;

	double xVelocity = 3;
	double yVelocity = 3;
public:
	Ball();

	RectangleShape getBall();
	bool SetTexture();

	void move();
	bool setSound(int bounceReason);
	void bounce(int bounceReason);

	void draw(sf::RenderWindow& window);
};

