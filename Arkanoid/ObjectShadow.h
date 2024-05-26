/*====================================
// Filename : ObjectShadow.h
// Description : This file contains the definitions of the ObjectShadow class
//				 which contains the ball and player's shadows logic
// Author : Samy Larochelle
// Date : May 13th, 2024
====================================*/
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Ball.h"	

class ObjectShadow
{
private:
	//Attributes
	std::string _type;
	const int _playerWidth = 32;
	const int _playerHeight = 8;
	const int _ballWidth = 5;
	const int _ballHeight = 4;
	const int sizeMultiplier = 4;

	//Sprites
	sf::RectangleShape _shadow;
	sf::Texture _texture;
	sf::IntRect _rectSprite;

	//Clock
	sf::Clock _clock;
	sf::Time _time;

public:
	//Constructors
	ObjectShadow();
	ObjectShadow(std::string type);

	//Actions
	void move(sf::RectangleShape type);

	//Setters
	void SetType(std::string type);

	//Load Ressources
	bool LoadTextures();

	//Others
	void draw(sf::RenderWindow& window);
};

