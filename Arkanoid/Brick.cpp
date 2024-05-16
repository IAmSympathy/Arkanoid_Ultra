#include "Brick.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace::std;
using namespace::sf;

Brick::Brick()
{
	_health = 1;
	_type = 0;
	_point = 50;
	_brick.scale(sizeMultiplier, sizeMultiplier);
	_brick.setPosition(100, 100);
	_brick.setSize(Vector2f(_width, _height));
	_rectSprite = IntRect(0, 0, _width, _height);
}

Brick::Brick(int type)
{
	_type = type;
	_health = 1;
	_type = 0;
	_point = 50;
	_brick.scale(sizeMultiplier, sizeMultiplier);
	_brick.setPosition(100, 100);
	_brick.setSize(Vector2f(_width, _height));
	_rectSprite = IntRect(0, 0, _width, _height);
	
	_point += _type * 10;
}

Brick::~Brick()
{
	_health = 0;
	_type = 0;
	_point = 0;
}

bool Brick::setTextureBrick()
{
	if (!_texture.loadFromFile("ArkanoidUltra_Data/Sprites/Bricks.png"))
	{
		return false;
	}
	_brick.setTexture(&_texture);

	_rectSprite.top = (_height * _type);
	_brick.setTextureRect(_rectSprite);
}

void Brick::drawBrick(sf::RenderWindow& window)
{
	window.draw(_brick);
}
