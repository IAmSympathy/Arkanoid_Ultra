/*====================================
// Filename : Brick.cpp
// Description : This file contains the implementation of the Brick class
//				 which contains the collisions, sprites and attributes of the brick object
// Author : Loucas Viens, Samy Larochelle
// Date : May 16th, 2024
====================================*/
#include "Brick.h"
using namespace::std;
using namespace::sf;

Brick::Brick()
{
	_left = 0;
	_up = 0;
	_right = 0;
	_down = 0;
	_health = 1;
	_baseHealth = _health;
	_type = 0;
	_point = 50;
	_brick.scale(sizeMultiplier, sizeMultiplier);
	_brick.setSize(Vector2f(_width, _height));
	_rectSprite = IntRect(0, 0, _width, _height);
}

Brick::Brick(int type)
{
	_left = 0;
	_up = 0;
	_right = 0;
	_down = 0;
	_type = type;
	_health = 1;
	_point = 50;
	_brick.scale(sizeMultiplier, sizeMultiplier);
	_brick.setSize(Vector2f(_width, _height));
	_rectSprite = IntRect(0, 0, _width, _height);
	if (type == 9)
	{
		_health = 999;
	}

	_baseHealth = _health;
	_point += _type * 10;
}

Brick::~Brick()
{
	_health = 0;
	_type = 0;
	_point = 0;
}


void Brick::CreateBorder()
{
	if (_type != -1)
	{
		Vector2f position = _brick.getPosition();
		_up = position.y;
		_down = position.y + (_height * sizeMultiplier);
		_left = position.x;
		_right = position.x + (_width * sizeMultiplier);
	}
}

int Brick::GetUp() const
{
	return _up;
}

int Brick::GetDown() const
{
	return _down;
}

int Brick::GetLeft() const
{
	return _left;
}

int Brick::GetRight() const
{
	return _right;
}

sf::RectangleShape Brick::GetBrick() const
{
	return _brick;
}

void Brick::Hit(sf::Texture &texture)
{
	_health -= 1;
	if (_health == 0)
	{
		_up = 0;
		_down = 0;
		_left = 0;
		_right = 0;
	}
	if (_type == 9)
		_rectSprite.top = 0;
	SetTexture(texture);
}

void Brick::SetTexture(sf::Texture& texture)
{
	if (_health == _baseHealth)
	{
		_rectSprite.top = (_height * _type);
		_brick.setTextureRect(_rectSprite);
		_brick.setTexture(&texture);
	}

	if (_type == -1)
	{
		_rectSprite.top = (56);
	}
	if (_type == 8)
	{
		if (_health == _baseHealth)
		{
			_rectSprite.top = 0;
		}
		if (_health == _baseHealth - 1)
		{
			_rectSprite.top = 7;
		}
		if (_health == _baseHealth - 2)
		{
			_rectSprite.top = 14;
		}
		if (_health == _baseHealth - 3)
		{
			_rectSprite.top = 21;
		}
		if (_health == _baseHealth - 4 )
		{
			_rectSprite.top = 28;
		}
	}
	if (_type == 9)
	{
		if (_health == _baseHealth)
		{
			_rectSprite.top = 0;
		}
	}
	if (_health == 0)
	{
		_rectSprite.top = 56;
		_brick.setScale(0, 0);
	}
	_brick.setTextureRect(_rectSprite);
	std::cout << "Brick textures has been changed" << endl;
}

void Brick::SetType(int type)
{
	_type = type;
}

void Brick::SetBrick(sf::RectangleShape brick)
{
	_brick = brick;
}

void Brick::SetUp(int haut)
{
	_up = haut;
}

void Brick::SetDown(int bas)
{
	_down = bas;
}

void Brick::setPosition(int x, int y)
{
	_brick.setPosition(x, y);
}

void Brick::SetRectSpriteTop(int value)
{
	_rectSprite.top = value;
	_brick.setTextureRect(_rectSprite);
}

void Brick::SetHealth(int health)
{
	_health = health;
}

void Brick::SetRight(int droite)
{
	_right = droite;
}

void Brick::SetLeft(int gauche)
{
	_left = gauche;
}

void Brick::GoldBrickAnimation()
{
	if (_type == 9)
	{
		if (_health != _baseHealth)
		{
			_time = _clock.getElapsedTime();
			//Idle animation - if the animation is over it will repeat
			if (_time.asMilliseconds() >= 100.0f)
			{
				_rectSprite.left = 0;
				_rectSprite.top += _height;
				if (_rectSprite.top >= 35)
				{
					_health = _baseHealth;
					_rectSprite.top = 0;
				}
				_brick.setTextureRect(_rectSprite);
				_clock.restart();
			}
		}
	}
}

void Brick::SilverPoint(int level)
{
	_point = level * 50;
}

void Brick::SilverHealth(int section)
{
	switch (section)
	{
	case 1:
		_health = 2;
		break;
	case 2:
		_health = 3;
		break;
	case 3:
		_health = 4;
		break;
	case 4:
		_health = 5;
		break;
	default:
		break;
	}
	_baseHealth = _health;
}

int Brick::GetHealth() const
{
	return _health;
}

int Brick::GetType() const
{
	return _type;
}

int Brick::GetScore()
{
	return _point;
}