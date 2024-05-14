#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Player
{
private:
	int _lives;
	bool _isDead;

	sf::RectangleShape _player;
	sf::Texture _texturePlayer;
	sf::IntRect _rectSprite;

	sf::RectangleShape _deadplayer;
	sf::Texture _deadtexturePlayer;
	sf::IntRect _deadrectSprite;

	sf::RectangleShape _col1;
	sf::RectangleShape _col2;
	sf::RectangleShape _col3;
	sf::RectangleShape _col4;
	sf::RectangleShape _col5;
	sf::RectangleShape _col6;
	

	sf::Clock _clock;		// À mettre avec les autres variables au début du main
	sf::Clock _clockSprite;
	sf::Time _time;
public:
	Player();

	void move();
	void moveCol(int value);
	void idleAnimation();
	void hidePlayer();

	void die();

	bool setTexture();
	void setIsDead(bool IsDead);

	sf::RectangleShape getPlayer();
	bool GetIsDead();
	sf::RectangleShape getCol(int value);

	void draw(sf::RenderWindow& window);
};

