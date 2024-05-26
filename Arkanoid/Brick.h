/*====================================
// Filename : Brick.h
// Description : This file contains the definition of the Brick class
//				 which contains the collisions, sprites and attributes of the brick object
// Author : Loucas Viens, Samy Larochelle
// Date : May 16th, 2024
====================================*/
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Brick
{
private:
	//Attributes
	int _point;
	int _health;
	int _baseHealth;
	int _type;
	const int _width = 15;
	const int _height = 7;
	const int sizeMultiplier = 4;

	//Sprite
	sf::IntRect _rectSprite;
	sf::RectangleShape _brick;

	//Checks
	int _left;
	int _up;
	int _right;
	int _down;

	//Clock
	sf::Clock _clock;
	sf::Time _time;
public:
	//Constructors and Destructor
	Brick();
	Brick(int type);
	~Brick();

	//Actions
	void CreateBorder();
	void Hit(sf::Texture &texture);
	void GoldBrickAnimation();
	void SilverPoint(int level);
	void SilverHealth(int section);

	//Getters
	sf::RectangleShape GetBrick() const;
	int GetLeft() const;
	int GetUp() const;
	int GetRight() const;
	int GetDown() const;
	int GetHealth() const;
	int GetType() const;
	int GetScore();
	//Setters
	void SetTexture(sf::Texture &texture);
	void SetType(int type);
	void SetBrick(sf::RectangleShape _brickField);
	void SetUp(int haut);
	void SetDown(int bas);
	void SetRight(int droite);
	void SetLeft(int gauche);
	void setPosition(int x, int y);
	void SetRectSpriteTop(int value);
	void SetHealth(int health);

	
};