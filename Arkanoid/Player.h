#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Player
{
private:
	sf::RectangleShape _player;
	sf::Texture _texturePlayer;
	sf::IntRect _rectSprite;

	sf::Clock _clock;		// � mettre avec les autres variables au d�but du main
	sf::Clock _clockSprite;
	sf::Time _time;
public:
	Player();

	void move();

	bool setTexture();
	void idleAnimation();

	sf::RectangleShape getPlayer();
	void draw(sf::RenderWindow& window);
};

