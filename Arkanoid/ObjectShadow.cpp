#include "ObjectShadow.h"

ObjectShadow::ObjectShadow(std::string objet)
{
	_type = objet;
	_shadow.setFillColor(Color::White);
}

bool ObjectShadow::SetTexture()
{
	if (_type == "Ball")
	{
		_shadow.setSize(Vector2f(16, 13));		// On définit ses dimensions
		_rectSprite = IntRect(0, 0, 16, 13);
		_shadow.setOrigin(8, 6);
		_shadow.setTextureRect(_rectSprite);
		if (!_texture.loadFromFile("Ressources/Sprites/Ball_S.png"))
			return false;
	}
	else if (_type == "Player")
	{
		_shadow.setSize(Vector2f(100, 25));		// On définit ses dimensions
		_rectSprite = IntRect(0, 0, 100, 25);
		_shadow.setOrigin(50, 14);
		_shadow.setTextureRect(_rectSprite);
		if (!_texture.loadFromFile("Ressources/Sprites/Player_S.png"))
			return false;
	}

	_shadow.setTexture(&_texture);
}

void ObjectShadow::draw(sf::RenderWindow& window)
{
	window.draw(_shadow);
}

void ObjectShadow::move(RectangleShape player)
{
	Vector2f position = player.getPosition();
	_time = _clock.getElapsedTime(); // Prends le temps de l’horloge
	if (_time.asMilliseconds() >= 10.0f) 
	{
		_shadow.setPosition(position.x + 12, position.y + 12);
		_clock.restart(); // On remet l’horloge à 0
	}
}
