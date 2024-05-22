#pragma once
#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>
#include "Player.h"
#include "Ball.h"
#include "ObjectShadow.h"
using namespace sf;		
using namespace std;	

class Game
{
private:
	//Attributes
	Player _player;
	Ball _ball;
	int _lives;
	int _score;
	int _highscore;
	int _level;

	//Actors' Shadows
	ObjectShadow _playerShadow;
	ObjectShadow _ballShadow;

	//Checks
	int _ballCollision;
	bool _isDead;
	bool _SpawnSoundOnce;
	enum playerStates { SPAWNING, ALIVE, DYING, EXPLODING };
	enum borderSize { SMALL, NORMAL, LARGE };

	//Textures
	sf::Texture _textureBackground;
	sf::Texture _textureBorder;
	sf::Texture _textureBorderS;
	sf::Texture _textureBorderBG;
	sf::RectangleShape _background;
	sf::RectangleShape _border;
	sf::RectangleShape _borderS;
	sf::RectangleShape _borderBG;

	//Audios
	sf::SoundBuffer _buffer;
	sf::Sound _music;

	//Others
	int _leftBorder, _rightBorder, _upBorder;
public:
	//Constructor
	Game();

	//Logic
	void StartLevel(int level);
	void Play();

	//Getters
	int GetLives();
	int GetScore();
	int GetHighScore();
	int GetLevel();
	//Setters
	bool SetBackground(int section);
	bool SetBorder(int size);
	bool SetMusic(int section);

	//Others
	void checkLives(Player& player);
	double CheckCollision(Player player, Ball ball);
	void Draw(sf::RenderWindow& window);
};

