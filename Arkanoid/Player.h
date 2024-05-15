#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>


class Player
{
private:
	//Checks
	int _lives;
	int _playerStatus;		// 0=Alive, 1=Crack, 2=Dead 3=Revive

	const int _width = 32;
	const int _height = 8;
	const int _totalHeight = _height * sizeMultiplier;
	const int sizeMultiplier = 4;

	//Others
	int _leftBorder, _rightBorder, _upBorder;

	//Player's sprite
	sf::RectangleShape _player;
	sf::Texture _texturePlayer;
	sf::IntRect _rectSprite;
	////Player's Crack sprite
	sf::RectangleShape _crackPlayer;
	sf::Texture _crackTexturePlayer;
	sf::IntRect _crackRectSprite;
	////Player's Dead sprite
	sf::RectangleShape _deadPlayer;
	sf::Texture _deadTexturePlayer;
	sf::IntRect _deadRectSprite;

	////Player's Dead sprite
	sf::RectangleShape _spawnPlayer;
	sf::Texture _spawnTexturePlayer;
	sf::IntRect _spawnRectSprite;


	//Collisions' sprites
	sf::RectangleShape _col1;
	sf::RectangleShape _col2;
	sf::RectangleShape _col3;
	sf::RectangleShape _col4;
	sf::RectangleShape _col5;
	sf::RectangleShape _col6;
	
	//Clock
	sf::Clock _clock;		
	sf::Clock _clockSprite;
	sf::Time _time;
public:
	//Constructors
	Player();

	//Actions
	void Move();
	void MoveCol(int value);
	void Die();
	
	//Animations
	void IdleAnimation();
	void CrackAnimation();
	void DeathAnimation();
	void SpawnAnimation();

	//Audio
	sf::SoundBuffer _buffer;
	sf::Sound _sound;

	//Setters
	bool SetTexture();
	bool SetSound(int sound);
	void SetBorders(int leftBorder, int rightBorder, int upBorder);

	//Getters
	sf::RectangleShape GetPlayer();
	sf::RectangleShape GetCol(int value);
	int GetPlayerStatus();
	int GetWidth();
	int GetHeight();

	//Others
	void Draw(sf::RenderWindow& window);
};

