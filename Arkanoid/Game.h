/*====================================
// Filename : Game.h
// Description : This file contains the definitions of the Game class
//				 which contains the game's logic and the interaction between actors
// Author : Samy Larochelle
// Date : May 13th, 2024
====================================*/
#pragma once
#define _USE_MATH_DEFINES		//Used to calculate the angle between the player and the ball
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>
#include "BrickField.h"
#include "Player.h"
#include "Ball.h"
#include "ObjectShadow.h"

class Game
{
private:
	//Attributes
	Player _player;
	Ball _ball;
	BrickField _brickfield;
	int _lives;
	int _score;
	int _highscore;
	int _level;

	//Actors' Shadows
	ObjectShadow _playerShadow;
	ObjectShadow _ballShadow;

	//Checks
	bool _isGameStarted;
	int _ballCollision;
	bool _isDead;
	bool _spawnSoundOnce;
	bool _paused;
	bool escapeKeyIsPressed;
	enum playerStates { SPAWNING, ALIVE, DYING, EXPLODING };
	enum borderSize { SMALL, NORMAL, LARGE };
	int _leftBorder, _rightBorder, _upBorder;

	//Textures
	sf::Texture _textureBackground;
	sf::Texture _textureBorder;
	sf::Texture _textureBorderShadow;
	sf::Texture _textureBorderBG;
	sf::RectangleShape _background;
	sf::RectangleShape _border;
	sf::RectangleShape _borderShadow;
	sf::RectangleShape _borderBG;

	//Audios
	sf::SoundBuffer _buffer;
	sf::Sound _music;
public:
	//Constructor
	Game();

	//Actions
	void StartLevel(int &level, int &section, int &episode);
	void Play();
	void Reset();
	//Checks
	void IsKeyPressed(sf::Event event);
	void CheckPlayerLives(Player& player);
	double CheckCollision(Player player, Ball ball);

	//Getters
	int GetLives() const;
	int GetScore() const;
	int GetHighScore() const;
	int GetLevel() const;
	int GetPlayerState();
	bool GetPaused() const;

	//Setters
	bool SetMusic(int section);
	void SetPaused(bool value);
	void SetScore();

	//Load ressources
	bool LoadBackground(int &episode, int &section);
	bool LoadBorder(int size); //Also sets the border width, so it can be sent to the ball and player

	void LoadHighScore();
	void SaveHighScore();

	//Others
	void Draw(sf::RenderWindow& window);
};

