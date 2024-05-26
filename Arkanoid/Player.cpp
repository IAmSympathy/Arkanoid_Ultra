/*====================================
// Filename : Player.cpp
// Description : This file contains the implementation of the Player class
//				 which contains the player's movements, animations, collsion checks, sounds and states
// Author : Samy Larochelle
// Date : May 9th, 2024
====================================*/
#include "Player.h"
using namespace sf;
using namespace std;

Player::Player()
{
	//Attributes
	_lives = 3;
	_state = SPAWNING;

	//Checks
	_isSpawned = false;
	_leftBorder = 0;
	_rightBorder = 0;
	_upBorder = 0;
	//Collision
	_hitbox.setPosition(957 - (_width * sizeMultiplier) / 2, 1015 - (_height * sizeMultiplier) / 2);
	_hitbox.setSize(Vector2f((32 + 3) * sizeMultiplier, _height * sizeMultiplier));
	_hitbox.setFillColor(Color::Red);

	//Sprites
	_player.scale(sizeMultiplier, sizeMultiplier);
	_player.setPosition(960, 1015);
	_player.setSize(Vector2f(0, 0));
	_player.setOrigin(_width / 2, _height / 2);
	_rectSprite = IntRect(0, 0, _width, _height);

	_diePlayer.scale(sizeMultiplier, sizeMultiplier);
	_diePlayer.setPosition(960, 1015);
	_diePlayer.setSize(Vector2f(0, 0));
	_diePlayer.setOrigin(_width / 2, _height / 2);
	_dieRectSprite = IntRect(0, 0, _width, _height);

	_explodePlayer.scale(sizeMultiplier, sizeMultiplier);
	_explodePlayer.setPosition(960, 1015);
	_explodePlayer.setSize(Vector2f(0, 0));
	_explodePlayer.setOrigin(24, 12);
	_explodeRectSprite = IntRect(0, 0, 48, 24);

	_spawnPlayer.scale(sizeMultiplier, sizeMultiplier);
	_spawnPlayer.setPosition(960, 1015);
	_spawnPlayer.setSize(Vector2f(_width, _height));
	_spawnPlayer.setOrigin(_width / 2, _height / 2);
	_spawnRectSprite = IntRect(0, 0, _width, _height);
	cout << "[Player] Player has been created " << endl;
}

bool Player::LoadTextures()
{
	_player.setTextureRect(_rectSprite);
	if (!_texturePlayer.loadFromFile("ArkanoidUltra_Data/Sprites/Player.png"))
		return false;
	_player.setTexture(&_texturePlayer);

	_diePlayer.setTextureRect(_dieRectSprite);
	if (!_dieTexturePlayer.loadFromFile("ArkanoidUltra_Data/Sprites/PlayerCrack.png"))
		return false;
	_diePlayer.setTexture(&_dieTexturePlayer);

	_explodePlayer.setTextureRect(_explodeRectSprite);
	if (!_explodeTexturePlayer.loadFromFile("ArkanoidUltra_Data/Sprites/PlayerDead.png"))
		return false;
	_explodePlayer.setTexture(&_explodeTexturePlayer);

	_spawnPlayer.setTextureRect(_spawnRectSprite);
	if (!_spawnTexturePlayer.loadFromFile("ArkanoidUltra_Data/Sprites/PlayerSpawn.png"))
		return false;
	_spawnPlayer.setTexture(&_spawnTexturePlayer);
}

//Set sounds depenging on the animation state
bool Player::SetSound(int sound)
{
	switch (sound)
	{
	case 1:
		if (!_buffer.loadFromFile("ArkanoidUltra_Data/Sounds/PlayerSpawn.wav"))
		{
			return false;
		}
		break;
	case 2:
		if (!_buffer.loadFromFile("ArkanoidUltra_Data/Sounds/PlayerDeath.wav"))
		{
			return false;
		}
	}
	_sound.setBuffer(_buffer);
}

void Player::SetBorders(int leftBorder, int rightBorder, int upBorder)
{
	_leftBorder = leftBorder;
	_rightBorder = rightBorder;
	_upBorder = upBorder;
}

void Player::SetLives(int lives)
{
	_lives = lives;
}

void Player::SetState(int state)
{
	_state = state;
	cout << "[Player] Switching state to " << state << endl;
}

//Reset the player to its SPAWNING position and state
void Player::Reset()
{
	PlaySound(1);
	SetState(SPAWNING);
	_player.setPosition(960, 1015);
	_hitbox.setPosition(957 - (_width * sizeMultiplier) / 2, 1015 - (_height * sizeMultiplier) / 2);
	_spawnPlayer.setPosition(960, 1015);
	_diePlayer.setPosition(960, 1015);
	_explodePlayer.setPosition(960, 1015);
	cout << "[Player] Player has been reset " << endl;
}

void Player::IdleAnimation()
{
	_time = _clock.getElapsedTime();
	//Idle animation - if the animation is over it will repeat
	if (_time.asMilliseconds() >= 100.0f)
	{
		_rectSprite.left = 0;
		_rectSprite.top += _height;
		if (_rectSprite.top >= _totalHeight)
		{
			_rectSprite.top = 0;
		}
		_player.setTextureRect(_rectSprite);
		_clock.restart();
	}
}

void Player::DieAnimation()
{
	_diePlayer.setSize(Vector2f(_width, _height));
	Vector2f positionPlayer = _player.getPosition();
	_diePlayer.setPosition(positionPlayer.x, positionPlayer.y);

	_time = _clock.getElapsedTime();
	if (_time.asMilliseconds() >= 100.0f)
	{
		_dieRectSprite.left = 0;
		_dieRectSprite.top += _height;
		if (_dieRectSprite.top >= 24)
		{
			_dieRectSprite.top = 0;
			_diePlayer.setSize(Vector2f(0, 0));
			SetState(EXPLODING);
		}
		_diePlayer.setTextureRect(_dieRectSprite);
		_clock.restart();
	}
}

void Player::ExplodeAnimation()
{
	_explodePlayer.setSize(Vector2f(48, 24));
	Vector2f positionPlayer = _player.getPosition();
	_explodePlayer.setPosition(positionPlayer.x, positionPlayer.y);

	_time = _clock.getElapsedTime();
	if (_time.asMilliseconds() >= 100.0f)
	{
		_explodeRectSprite.left = 0;
		_explodeRectSprite.top += 24;
		if (_explodeRectSprite.top >= 96)
		{
			_explodeRectSprite.top = 0;
			_explodePlayer.setSize(Vector2f(0, 0));
			_player.setPosition(960, 1015);
			_hitbox.setPosition(957 - (_width * sizeMultiplier) / 2, 1015 - (_height * sizeMultiplier) / 2);
			SetState(SPAWNING);
		}
		_explodePlayer.setTextureRect(_explodeRectSprite);
		_clock.restart();
	}
}

void Player::SpawnAnimation()
{
	_spawnPlayer.setSize(Vector2f(_width, _height));
	Vector2f positionPlayer = _player.getPosition();
	_spawnPlayer.setPosition(positionPlayer.x, positionPlayer.y);

	_spawnPlayer.setSize(Vector2f(_width, _height));
	_time = _clock.getElapsedTime();
	if (_time.asMilliseconds() >= 100.0f)
	{
		_spawnRectSprite.left = 0;
		_spawnRectSprite.top += 8;
		if (_spawnRectSprite.top >= 40)
		{
			_spawnPlayer.setSize(Vector2f(0, 0));
			_spawnRectSprite.top = 0;
			_isSpawned = true;
		}
		_spawnPlayer.setTextureRect(_spawnRectSprite);
		_clock.restart();
	}
}

void Player::Die()
{
	_lives--;
	SetState(DYING);
	PlaySound(2);
}

void Player::Revive()
{
	_isSpawned = false;
	_player.setSize(Vector2f(_width, _height));
	SetState(ALIVE);
	cout << "[Player] Player has been revived " << endl;
}

//Play sounds depending on the player's animation
void Player::PlaySound(int sound)
{
	switch (sound)
	{
	case 1:
		SetSound(1);
		_sound.play();
		break;
	case 2:
		SetSound(2);
		_sound.play();
		break;
	}
}

sf::RectangleShape Player::GetPlayer()
{
	return _player;
}

int Player::GetPlayerStatus()
{
	return _state;
}

int Player::GetLive()
{
	return _lives;
}

bool Player::GetIsSpawned()
{
	return _isSpawned;
}

sf::RectangleShape Player::GetHitbox()
{
	return _hitbox;
}

void Player::Draw(sf::RenderWindow& window)
{
	switch (_state)
	{
	case SPAWNING:
		window.draw(_spawnPlayer);
		break;
	case ALIVE:
		window.draw(_player);
		break;
	case DYING:
		window.draw(_diePlayer);
		break;
	case EXPLODING:
		window.draw(_explodePlayer);
		break;
	}
	//Uncomment this to draw the player's collision box
	//window.draw(_hitbox);
}

//If ALIVE, moves the player by 10 pixels depending on the keyboard's given direction //------------------TO DO: REMOVE DEBUG DIE KEY
void Player::Move()
{
	Vector2f currentPosition = _player.getPosition();
	Vector2f nextPosition;

	if (_state == ALIVE)
	{
		_time = _clock.getElapsedTime();
		if (_time.asMilliseconds() >= 10.0f) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))	//If the 'A' key is pressed, makes the player move by 10 units to the left
			{
				currentPosition = _player.getPosition();
				_player.move(-10, 0);
				MoveCol(-10);
				nextPosition = _player.getPosition();
				if (nextPosition.x < _leftBorder + (_width * sizeMultiplier) / 2)
				{
					_player.setPosition(currentPosition.x, currentPosition.y);	//If the next position is within a wall, go back to the previous one
					MoveCol(+10);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))	//If the 'A' key is pressed, makes the player move by 10 units to the left
			{
				currentPosition = _player.getPosition();
				_player.move(+10, 0);
				MoveCol(+10);
				nextPosition = _player.getPosition();
				if (nextPosition.x > _rightBorder - (_width * sizeMultiplier) / 2)
				{
					_player.setPosition(currentPosition.x, currentPosition.y); 	//If the next position is within a wall, go back to the previous one
					MoveCol(-10);
				}

			}
			_clock.restart();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
			{
				Die();
			}
		}
	}
}

//Move the player's hitbox
void Player::MoveCol(int value)
{
	_hitbox.move(value, 0);
}
