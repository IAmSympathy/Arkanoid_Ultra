/*====================================
// Filename : Ball.h
// Description : This file contains the definitions of the Ball class
//				 which contains the ball's movements, collision checks, sounds and states
// Author : Samy Larochelle
// Date : May 9th, 2024
====================================*/
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Ball
{
private:
	//Attributes
	sf::Vector2f _velocity;
	float _speed;
	const int _width = 5;
	const int _height = 4;
	const int sizeMultiplier = 4;

	//Checks
	bool _isUnderMap;
	bool _firstThrow;
	bool _startMusic;
	int _collision;
	int _state;
	enum ballStates { THROW, ALIVE, DEAD };
	int _leftBorder, _rightBorder, _upBorder;

	//Sprites
	sf::RectangleShape _ball;
	sf::Texture _texture;
	sf::IntRect _rectSprite;

	//Audio
	sf::SoundBuffer _buffer;
	sf::Sound _sound;
	sf::SoundBuffer _firstThrowBuffer;
	sf::Sound _firstThrowSound;

	//Clock
	sf::Clock _clock;
	sf::Time _time;
public:
	//Constructor and Destructor
	Ball();
	~Ball();

	//Actions
	void Move();
	void MoveThrow(sf::RectangleShape player);
	void CheckCollision(double value);
	void Bounce(int bounceReason);
	void Revive();
	void Reset();

	//Getters
	sf::RectangleShape GetBall();
	int GetState();
	bool GetStartMusic();

	//Setters
	void SetAngle(double xVelocity, double yVelocity);
	void SetState(int State);
	void SetBorders(int leftBorder, int rightBorder, int upBorder);
	void SetStartMusic(bool value);

	//Load Ressources
	bool LoadTexture();
	bool LoadSounds();
	bool LoadBounceSounds(int bounceReason);

	//Others
	void Draw(sf::RenderWindow& window);
};

