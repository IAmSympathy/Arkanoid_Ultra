#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>


class Player
{
private:
	//Attributes
 	const int _width = 32;
	const int _height = 8;
	const int _totalHeight = _height * 6;
	const int sizeMultiplier = 4;
	int _lives;

	//Checks
	bool _isSpawned;
	enum playerStates{SPAWNING, ALIVE, DYING, EXPLODING };
	int _State ;// 0=Alive, 1=Crack, 2=Dead 3=Revive

	//Player's sprite
	sf::RectangleShape _player;
	sf::Texture _texturePlayer;
	sf::IntRect _rectSprite;
	//Player's Crack sprite
	sf::RectangleShape _diePlayer;
	sf::Texture _dieTexturePlayer;
	sf::IntRect _dieRectSprite;
	//Player's Dead sprite
	sf::RectangleShape _explodePlayer;
	sf::Texture _explodeTexturePlayer;
	sf::IntRect _explodeRectSprite;
	//Player's Spawn sprite
	sf::RectangleShape _spawnPlayer;
	sf::Texture _spawnTexturePlayer;
	sf::IntRect _spawnRectSprite;

	//Collisions
	sf::RectangleShape _col1;
	sf::RectangleShape _col2;
	sf::RectangleShape _col3;
	sf::RectangleShape _col4;
	sf::RectangleShape _col5;
	sf::RectangleShape _col6;
	int _leftBorder, _rightBorder, _upBorder;

	//Audio
	sf::SoundBuffer _buffer;
	sf::SoundBuffer _bufferSpawn;
	sf::Sound _sound;

	//Clock		
	sf::Clock _clock;
	sf::Time _time;
public:
	//Constructors
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

	//Setters
	bool SetTexture();
	bool SetSound(int sound);
	void SetBorders(int leftBorder, int rightBorder, int upBorder);

	//Getters
	sf::RectangleShape GetPlayer();
	sf::RectangleShape GetCol(int value);
	int GetPlayerStatus();
	int GetLive();
	bool GetIsSpawned();

	//Others
	void Draw(sf::RenderWindow& window);
};

