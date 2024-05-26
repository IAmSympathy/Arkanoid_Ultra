/*====================================
// Filename : Player.h
// Description : This file contains the definitions of the Player class
//				 which contains the player's movements, animations, collsion checks, sounds and states
// Author : Samy Larochelle
// Date : May 9th, 2024
====================================*/
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Player
{
private:
	//Attributes
	int _lives;
 	const int _width = 32;
	const int _height = 8;
	const int _totalHeight = _height * 6;
	const int sizeMultiplier = 4;

	//Checks
	bool _isSpawned;
	int _state;
	enum playerStates{ SPAWNING, ALIVE, DYING, EXPLODING, THROW };
	//Collisions
	sf::RectangleShape _hitbox;
	int _leftBorder, _rightBorder, _upBorder;

	//Sprite
	sf::RectangleShape _player;
	sf::Texture _texturePlayer;
	sf::IntRect _rectSprite;
	//Crack sprite
	sf::RectangleShape _diePlayer;
	sf::Texture _dieTexturePlayer;
	sf::IntRect _dieRectSprite;
	//Dead sprite
	sf::RectangleShape _explodePlayer;
	sf::Texture _explodeTexturePlayer;
	sf::IntRect _explodeRectSprite;
	//Spawn sprite
	sf::RectangleShape _spawnPlayer;
	sf::Texture _spawnTexturePlayer;
	sf::IntRect _spawnRectSprite;

	//Audio
	sf::SoundBuffer _buffer;
	sf::SoundBuffer _bufferSpawn;
	sf::Sound _sound;

	//Clock		
	sf::Clock _clock;
	sf::Time _time;
public:
	//Constructor
	Player();

	//Actions
	void Move();
	void MoveCol(int value);
	void Die();
	void Revive();
	void PlaySound(int sound);
	
	//Animations
	void IdleAnimation();
	void DieAnimation();
	void ExplodeAnimation();
	void SpawnAnimation();

	//Load ressources
	bool LoadTextures();

	//Getters
	sf::RectangleShape GetPlayer();
	sf::RectangleShape GetHitbox();
	int GetPlayerStatus();
	int GetLive();
	bool GetIsSpawned();

	//Setters
	bool SetSound(int sound);
	void SetBorders(int leftBorder, int rightBorder, int upBorder);
	void SetLives(int lives);
	void SetState(int state);
	void Reset();

	//Others
	void Draw(sf::RenderWindow& window);
};

