#include "Player.h"
using namespace sf;		// Namespace pour les objets de la librairie SFML
using namespace std;	// Namespace pour les objets de la librairie standard en C++

Player::Player()
{
	_lives = 3;
	_isDead = false;

	_player.setPosition(960, 1015);				// On définit sa position
	_player.setSize(Vector2f(100, 27));		// On définit ses dimensions
	_player.setOrigin(50, 14);
	_rectSprite = IntRect(0, 0, 100, 27);

	_col1.setPosition(960 - 50, 1015 - 14);				// On définit sa position
	_col1.setSize(Vector2f(6, 27));		// On définit ses dimensions
	_col1.setFillColor(Color::Red);

	_col2.setPosition(966 - 50, 1015 - 14);				// On définit sa position
	_col2.setSize(Vector2f(19, 27));		// On définit ses dimensions
	_col2.setFillColor(Color::Yellow);

	_col3.setPosition(985 - 50, 1015 - 14);				// On définit sa position
	_col3.setSize(Vector2f(25, 27));		// On définit ses dimensions
	_col3.setFillColor(Color::Green);

	_col4.setPosition(1010 - 50, 1015 - 14);				// On définit sa position
	_col4.setSize(Vector2f(25, 27));		// On définit ses dimensions
	_col4.setFillColor(Color::Cyan);

	_col5.setPosition(1035 - 50, 1015 - 14);				// On définit sa position
	_col5.setSize(Vector2f(19, 27));		// On définit ses dimensions
	_col5.setFillColor(Color::Yellow);

	_col6.setPosition(1054 - 50, 1015 - 14);				// On définit sa position
	_col6.setSize(Vector2f(6, 27));		// On définit ses dimensions
	_col6.setFillColor(Color::Red);
}

bool Player::setTexture()
{
	_player.setTextureRect(_rectSprite);

	if (!_texturePlayer.loadFromFile("ressources/sprites/player.png"))
		return false;

	_player.setTexture(&_texturePlayer); // Applique la texture à l’élément souhaité
}

void Player::setIsDead(bool ballUnderMap)
{
	if (ballUnderMap == true)
		die();
}


void Player::idleAnimation()
{
	_time = _clockSprite.getElapsedTime(); // Prends le temps de l’horloge

	if (_isDead == true)
	{
		if (_time.asMilliseconds() >= 200.0f) {
			_rectSprite.left = 100;
			_rectSprite.top += 75;
			if (_rectSprite.top >= 300)	// Après 3, on revient à 0
			{
				_rectSprite.top = 0;
				hidePlayer();
			}
			_player.setTextureRect(_rectSprite);
			_clockSprite.restart(); // On remet l’horloge à 0
		}
	}
	else
	{
		if (_time.asMilliseconds() >= 100.0f) {
			_rectSprite.left = 0;
			_rectSprite.top += 27;
			if (_rectSprite.top >= 120)	// Après 3, on revient à 0
				_rectSprite.top = 0;
			_player.setTextureRect(_rectSprite);
			_clockSprite.restart(); // On remet l’horloge à 0
		}
	}


}

void Player::hidePlayer()
{
	_player.setSize(Vector2f(0, 0));
	_rectSprite = IntRect(0, 0, 0, 0);
}

void Player::die()
{
	_lives--;
	_isDead = true;

	_player.setSize(Vector2f(150, 75));		// On définit ses dimensions
	_player.setOrigin(75, 37);
	_rectSprite = IntRect(174, 36, 150, 75);

}

sf::RectangleShape Player::getPlayer()
{
	return _player;
}

bool Player::GetIsDead()
{
	return _isDead;
}

sf::RectangleShape Player::getCol(int value)
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

void Player::draw(sf::RenderWindow& window)
{
	window.draw(_player);
	//window.draw(_col1);
	//window.draw(_col2);
	//window.draw(_col3);
	//window.draw(_col4);
	//window.draw(_col5);
	//window.draw(_col6);
}



void Player::move()
{
	Vector2f currentPosition = _player.getPosition();
	Vector2f nextPosition;

	_time = _clock.getElapsedTime(); // Prends le temps de l’horloge
	if (_isDead == false)
	{
		if (_time.asMilliseconds() >= 10.0f) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				currentPosition = _player.getPosition();
				_player.move(-10, 0);
				moveCol(-10);
				nextPosition = _player.getPosition();;
				if (nextPosition.x < 521 + 50)
				{
					_player.setPosition(currentPosition.x, currentPosition.y);
					moveCol(+10);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				currentPosition = _player.getPosition();
				_player.move(+10, 0);
				moveCol(+10);
				nextPosition = _player.getPosition();;
				if (nextPosition.x > 1395 - 50)
				{
					_player.setPosition(currentPosition.x, currentPosition.y);
					moveCol(-10);
				}

			}
			_clock.restart(); // On remet l’horloge à 0
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
			die();
		}
	}
}

void Player::moveCol(int value)
{
	_col1.move(value, 0);
	_col2.move(value, 0);
	_col3.move(value, 0);
	_col4.move(value, 0);
	_col5.move(value, 0);
	_col6.move(value, 0);
}
