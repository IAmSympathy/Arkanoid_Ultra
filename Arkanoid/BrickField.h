/*====================================
// Filename : BrickField.h
// Description : This file contains the definition of the BrickField class
//				 which contains the logic of the creation of the BrickField
// Author : Loucas Viens, Samy Larochelle
// Date : May 25th, 2024
====================================*/
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include "Player.h"
#include "Ball.h"
#include "Brick.h"

class BrickField
{
private:
	//Attributes
	int _nbBrick;
	std::vector<Brick> _field;
	std::vector<Brick> _shadowField;

	//Textures
	sf::Texture _textureNormal;
	sf::Texture _textureSilver;
	sf::Texture _textureGold;
	//Checks
	bool _isCollision;

	//Clock
	sf::Clock _clock;
	sf::Time _time;
public:
	//Actions
	void InitializeField(int level);
	void UpdateShadows(Ball ball);
	void CountBrickLeft();

	//Checks
	void CheckCollision(Brick& brick, Ball& ball);

	//Getters
	std::vector<Brick> GetField();

	//Load ressources
	bool LoadTexture();
	//Other
	void Draw(sf::RenderWindow& window, Ball ball);
};

