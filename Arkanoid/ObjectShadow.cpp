#include "ObjectShadow.h"

ObjectShadow::ObjectShadow()
{
	_type = "";
}

ObjectShadow::ObjectShadow(std::string objet)
{
	_type = objet;
}

bool ObjectShadow::SetTexture()
{
	if (_type == "Ball")
	{
		_shadow.scale(sizeMultiplier, sizeMultiplier);
		_shadow.setSize(Vector2f(_ballWidth, _ballHeight));		
		_rectSprite = IntRect(0, 0, _ballWidth, _ballHeight);
		_shadow.setOrigin(_ballWidth / 2, _ballHeight / 2);
		_shadow.setTextureRect(_rectSprite);
		if (!_texture.loadFromFile("ArkanoidUltra_Data/Sprites/Ball_S.png"))
			return false;
	}
	else if (_type == "Player")
	{
		_shadow.scale(sizeMultiplier, sizeMultiplier);
		_shadow.setSize(Vector2f(_playerWidth, _playerHeight));
		_rectSprite = IntRect(0, 0, _playerWidth, _playerHeight);
		_shadow.setOrigin(_playerWidth / 2, _playerHeight / 2);
		_shadow.setTextureRect(_rectSprite);
		if (!_texture.loadFromFile("ArkanoidUltra_Data/Sprites/Player_S.png"))
			return false;
	}

	_shadow.setTexture(&_texture);
}

void ObjectShadow::SetType(std::string type)
{
	_type = type;
}

void ObjectShadow::draw(sf::RenderWindow& window)
{
	window.draw(_shadow);
}

void ObjectShadow::move(RectangleShape player)
{
	Vector2f position = player.getPosition();
	_time = _clock.getElapsedTime();
	if (_time.asMilliseconds() >= 10.0f) 
	{
		_shadow.setPosition(position.x + 4  * sizeMultiplier, position.y + 4 * sizeMultiplier);
		_clock.restart();
	}
}
