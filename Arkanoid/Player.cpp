#include "Player.h"
using namespace sf;		// Namespace pour les objets de la librairie SFML
using namespace std;	// Namespace pour les objets de la librairie standard en C++

Player::Player()
{
	_player.setPosition(10, 20);				// On définit sa position
	_player.setSize(Vector2f(80, 20));		// On définit ses dimensions
	_player.setFillColor(Color::White);
	_rectSprite = IntRect(0, 0, 80, 20);
}

bool Player::setTexture()
{
	_player.setTextureRect(_rectSprite);

	if (!_texturePlayer.loadFromFile("ressources/sprites/player.png"))
		return false;

	_player.setTexture(&_texturePlayer); // Applique la texture à l’élément souhaité

}

void Player::idleAnimation()
{
	_time = _clockSprite.getElapsedTime(); // Prends le temps de l’horloge
	if (_time.asMilliseconds() >= 100.0f) {
		_rectSprite.left = 0;
		_rectSprite.top += 20;
		if (_rectSprite.top >= 120)	// Après 3, on revient à 0
			_rectSprite.top = 0;
		_player.setTextureRect(_rectSprite);
		_clockSprite.restart(); // On remet l’horloge à 0
	}
}

sf::RectangleShape Player::getPlayer()
{
	return _player;
}


void Player::move()
{
	_time = _clock.getElapsedTime(); // Prends le temps de l’horloge
	if (_time.asMilliseconds() >= 10.0f) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			_player.move(-10, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			_player.move(+10, 0);
		}
		_clock.restart(); // On remet l’horloge à 0
	}
}
