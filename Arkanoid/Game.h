#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Player.h"
#include "Ball.h"
#include "ObjectShadow.h"
using namespace sf;		
using namespace std;	

class Game
{
private:
	//Actors
	Player _player;
	Ball _ball;

	//Actors' Shadows
	ObjectShadow _playerShadow;
	ObjectShadow _ballShadow;

	//Checks
	int _ballCollision;
	bool _isDead;

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

	//Setters
	bool SetBackground(int level);
	bool SetBorder();
	bool SetMusic(int level);

	//Others
	int CheckCollision(Player player, Ball ball);
	void Draw(sf::RenderWindow& window);
};

