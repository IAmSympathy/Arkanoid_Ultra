#include "Player.h"
using namespace sf;
using namespace std;

Player::Player()
{
	//Define the player and its sprite
	_lives = 3;
	_playerStatus = 0;

	_leftBorder = 0;
	_rightBorder = 0;
	_upBorder = 0;

	_player.scale(sizeMultiplier, sizeMultiplier);
	_player.setPosition(960, 1015);
	_player.setSize(Vector2f(_width, _height));
	_player.setOrigin(_width / 2, _height / 2);
	_rectSprite = IntRect(0, 0, _width, _height);

	_crackPlayer.scale(sizeMultiplier, sizeMultiplier);
	_crackPlayer.setPosition(960, 1015);
	_crackPlayer.setSize(Vector2f(0, 0));
	_crackPlayer.setOrigin(_width / 2, _height / 2);
	_crackRectSprite = IntRect(0, 0, _width, _height);

	_deadPlayer.scale(sizeMultiplier, sizeMultiplier);
	_deadPlayer.setPosition(960, 1015);
	_deadPlayer.setSize(Vector2f(0, 0));
	_deadPlayer.setOrigin(24, 12);
	_deadRectSprite = IntRect(0, 0, 48, 24);

	_spawnPlayer.scale(sizeMultiplier, sizeMultiplier);
	_spawnPlayer.setPosition(960, 1015);
	_spawnPlayer.setSize(Vector2f(_width, _height));
	_spawnPlayer.setOrigin(_width / 2, _height / 2);
	_spawnRectSprite = IntRect(0, 0, _width, _height);

	//Define all the player's collisions
	_col1.setPosition(957 - (_width * sizeMultiplier) / 2, 1015 - (_height * sizeMultiplier)/ 2);
	_col1.setSize(Vector2f(3 * sizeMultiplier, _height * sizeMultiplier));
	_col1.setFillColor(Color::Red);

	_col2.setPosition(957 + 3 * sizeMultiplier - (_width * sizeMultiplier) / 2, 1015 - (_height * sizeMultiplier) / 2);
	_col2.setSize(Vector2f(6 * sizeMultiplier, _height * sizeMultiplier));
	_col2.setFillColor(Color::Yellow);

	_col3.setPosition(957 + 3 * sizeMultiplier + 6 * sizeMultiplier - (_width * sizeMultiplier) / 2, 1015 - (_height * sizeMultiplier) / 2);
	_col3.setSize(Vector2f(8 * sizeMultiplier, _height * sizeMultiplier));
	_col3.setFillColor(Color::Green);

	_col4.setPosition(957 + 3 * sizeMultiplier + 6 * sizeMultiplier + 8 * sizeMultiplier - (_width * sizeMultiplier) / 2, 1015 - (_height * sizeMultiplier) / 2);
	_col4.setSize(Vector2f(8 * sizeMultiplier, _height * sizeMultiplier));
	_col4.setFillColor(Color::Cyan);

	_col5.setPosition(957 + 3 * sizeMultiplier + 6 * sizeMultiplier + 8 * sizeMultiplier + 8 * sizeMultiplier - (_width * sizeMultiplier) / 2, 1015 - (_height * sizeMultiplier) / 2);
	_col5.setSize(Vector2f(6 * sizeMultiplier, _height * sizeMultiplier));
	_col5.setFillColor(Color::Yellow);

	_col6.setPosition(957 + 3 * sizeMultiplier + 6 * sizeMultiplier + 8 * sizeMultiplier + 8 * sizeMultiplier +6 * sizeMultiplier - (_width * sizeMultiplier) / 2, 1015 - (_height * sizeMultiplier) / 2);
	_col6.setSize(Vector2f(3 * sizeMultiplier, _height * sizeMultiplier));
	_col6.setFillColor(Color::Red);
}

bool Player::SetTexture()
{
	_player.setTextureRect(_rectSprite);
	if (!_texturePlayer.loadFromFile("ArkanoidUltra_Data/Sprites/Player.png"))
		return false;
	_player.setTexture(&_texturePlayer);

	_crackPlayer.setTextureRect(_crackRectSprite);
	if (!_crackTexturePlayer.loadFromFile("ArkanoidUltra_Data/Sprites/PlayerCrack.png"))
		return false;
	_crackPlayer.setTexture(&_crackTexturePlayer);

	_deadPlayer.setTextureRect(_deadRectSprite);
	if (!_deadTexturePlayer.loadFromFile("ArkanoidUltra_Data/Sprites/PlayerDead.png"))
		return false;
	_deadPlayer.setTexture(&_deadTexturePlayer);

	_spawnPlayer.setTextureRect(_spawnRectSprite);
	if (!_spawnTexturePlayer.loadFromFile("ArkanoidUltra_Data/Sprites/PlayerSpawn.png"))
		return false;
	_spawnPlayer.setTexture(&_spawnTexturePlayer);

}

bool Player::SetSound(int sound)
{
	switch (sound)
	{
	case 1:
		if (!_buffer.loadFromFile("ArkanoidUltra_Data/Sounds/PlayerDeath.wav"))
			return false;
		break;

	}
	_sound.setBuffer(_buffer);
}

void Player::SetBorders(int leftBorder, int rightBorder, int upBorder)
{
	_leftBorder = leftBorder;
	_rightBorder = rightBorder;
	_upBorder = upBorder;
}

void Player::IdleAnimation()
{
	_time = _clockSprite.getElapsedTime();
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
		_clockSprite.restart();
	}
}

void Player::CrackAnimation()
{
	_crackPlayer.setSize(Vector2f(_width, _height));
	Vector2f positionPlayer = _player.getPosition();
	_crackPlayer.setPosition(positionPlayer.x, positionPlayer.y);

	_time = _clockSprite.getElapsedTime();
	if (_time.asMilliseconds() >= 150.0f)
	{
		_crackRectSprite.left = 0;
		_crackRectSprite.top += _height;
		if (_crackRectSprite.top >= 24)
		{
			_crackRectSprite.top = 0;
			_crackPlayer.setSize(Vector2f(0, 0));
			_playerStatus = 2;
		}
		_crackPlayer.setTextureRect(_crackRectSprite);
		_clockSprite.restart();
	}
}

void Player::DeathAnimation()
{
	_deadPlayer.setSize(Vector2f(48, 24));
	Vector2f positionPlayer = _player.getPosition();
	_deadPlayer.setPosition(positionPlayer.x, positionPlayer.y);

	_time = _clockSprite.getElapsedTime();
	if (_time.asMilliseconds() >= 150.0f) 
	{
		_deadRectSprite.left = 0;
		_deadRectSprite.top += 24;
		if (_deadRectSprite.top >= 96)
		{
			_deadRectSprite.top = 0;
			_deadPlayer.setSize(Vector2f(0, 0));
			_playerStatus = 3;
		}
		_deadPlayer.setTextureRect(_deadRectSprite);
		_clockSprite.restart();
	}
}

void Player::SpawnAnimation()
{
	_spawnPlayer.setSize(Vector2f(_width, _height));
	Vector2f positionPlayer = _player.getPosition();
	_spawnPlayer.setPosition(positionPlayer.x, positionPlayer.y);

	_spawnPlayer.setSize(Vector2f(_width, _height));
	_time = _clockSprite.getElapsedTime();
	if (_time.asMilliseconds() >= 150.0f) 
	{
		_spawnRectSprite.left = 0;
		_spawnRectSprite.top += 8;
		if (_spawnRectSprite.top >= 40)
		{
			_spawnRectSprite.top = 0;
		}
		_spawnPlayer.setTextureRect(_spawnRectSprite);
		_clockSprite.restart();
	}
}

void Player::Die()
{
	//Death consequences
	_lives--;
	_playerStatus = 1;

	SetSound(1);
	_sound.play();
}

sf::RectangleShape Player::GetPlayer()
{
	return _player;
}

int Player::GetPlayerStatus()
{
	return _playerStatus;
}

int Player::GetWidth()
{
	return 0;
}

sf::RectangleShape Player::GetCol(int value)
{
	switch (value)
	{
	case 1:
		return _col1;
		break;
	case 2:
		return _col2;
		break;
	case 3:
		return _col3;
		break;
	case 4:
		return _col4;
		break;
	case 5:
		return _col5;
		break;
	case 6:
		return _col6;
		break;
	}
}

void Player::Draw(sf::RenderWindow& window)
{
	switch (_playerStatus)
	{
	case 0:
		window.draw(_player);
		break;
	case 1:
		window.draw(_crackPlayer);
		break;
	case 2:
		window.draw(_deadPlayer);
		break;
	case 3:
		window.draw(_spawnPlayer);
		break;
	}
	//window.draw(_col1);
	//window.draw(_col2);
	//window.draw(_col3);
	//window.draw(_col4);
	//window.draw(_col5);
	//window.draw(_col6);
}

void Player::Move()
{
	Vector2f currentPosition = _player.getPosition();
	Vector2f nextPosition;

	_time = _clock.getElapsedTime();
	if (_playerStatus == 0)
	{
		if (_time.asMilliseconds() >= 10.0f) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))	//If the 'A' key is pressed, makes the player move by 10 units to the left
			{
				currentPosition = _player.getPosition();
				_player.move(-10, 0);
				MoveCol(-10);
				nextPosition = _player.getPosition();
				if (nextPosition.x < _leftBorder + (_width * sizeMultiplier) /2)					//If the next position is within a wall, go back to the previous one
				{
					_player.setPosition(currentPosition.x, currentPosition.y);
					MoveCol(+10);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))	//If the 'A' key is pressed, makes the player move by 10 units to the left
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
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
			Die();
		}
	}
}

void Player::MoveCol(int value)
{
	_col1.move(value, 0);
	_col2.move(value, 0);
	_col3.move(value, 0);
	_col4.move(value, 0);
	_col5.move(value, 0);
	_col6.move(value, 0);
}
