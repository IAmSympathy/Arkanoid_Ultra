#include "Ball.h"

Ball::Ball()
{
	_velocity.x = 1;
	_velocity.y = 1;
	_speed = 4;
	_collision = 0;
	_isUnderMap = false;

	_ball.setPosition(960, 520);		// On définit sa position
	_ball.setOrigin(8, 6);
	_ball.setSize(Vector2f(15, 12));	// On définit ses dimensions
	_ball.setFillColor(Color::White);
	_rectSprite = IntRect(0, 0, 16, 13);
}

RectangleShape Ball::getBall()
{
	return _ball;
}

bool Ball::SetTexture()
{
	_ball.setTextureRect(_rectSprite);

	if (!_texture.loadFromFile("Ressources/Sprites/Ball.png"))
		return false;

	_ball.setTexture(&_texture);
}

void Ball::move()
{
	Vector2f position;
	position = _ball.getPosition();
	if (_isUnderMap == false)
	{
		if (!(_collision == 0))
		{
			if (position.y < 1015 + 13 - 6)
			{
				switch (_collision)
				{
				case 1:
					setAngle(-0.85, -1);
					break;
				case 2:
					setAngle(-0.5, -1);
					break;
				case 3:
					setAngle(-0.25, -1);
					break;
				case 4:
					setAngle(0.25, -1);
					break;
				case 5:
					setAngle(0.5, -1);
					break;
				case 6:
					setAngle(0.85, -1);
					break;
				}
			}
			else
			{
				switch (_collision)
				{
				case 1:
					setAngle(-0.85, 1);
					break;
				case 2:
					setAngle(-0.5, 1);
					break;
				case 3:
					setAngle(-0.15, 1);
					break;
				case 4:
					setAngle(0.15, 1);
					break;
				case 5:
					setAngle(0.5, 1);
					break;
				case 6:
					setAngle(0.85, 1);
					break;
				}
			}

			bounce(2);
			_collision = 0;
		}

		float norme = sqrt(_velocity.x * _velocity.x + _velocity.y * _velocity.y);
		if (norme != 0) {
			_velocity.x /= norme;
			_velocity.y /= norme;
		}

		_time = _clock.getElapsedTime(); // Prends le temps de l’horloge
		if (_time.asMilliseconds() >= 10.0f)
		{
			if (position.x < 521 + 8 || position.x > 1395 - 6) {
				_velocity.x *= -1;
				bounce(1);
			}

			if (position.y < 100 + 7)
			{
				_velocity.y *= -1;
				bounce(1);
			}

			if (position.y > 1080 - 6)
			{
				_isUnderMap = true;
			}

			_ball.setPosition(position.x + _velocity.x * _speed, position.y + _velocity.y * _speed);
			_clock.restart(); // On remet l’horloge à 0
		}

	}
}

bool Ball::setSound(int bounceReason)
{
	switch (bounceReason)
	{
	case 1:
		if (!_buffer.loadFromFile("Ressources/Audio/Sound/BallWall.wav"))
			return false;
		break;
	case 2:
		if (!_buffer.loadFromFile("Ressources/Audio/Sound/BallPlayer.wav"))
			return false;
		break;
	case 3:
		if (!_buffer.loadFromFile("Ressources/Audio/Sound/BallBrick.wav"))
			return false;
		break;
	}
	_sound.setBuffer(_buffer);
}

void Ball::setAngle(double xVelocity, double yVelocity)
{
	_velocity.x = xVelocity;
	_velocity.y = yVelocity;
}

void Ball::SetIsUnderMap(isUnderMap)
{
	_isUnderMap = isUnderMap;
}

void Ball::bounce(int bounceReason)
{

	switch (bounceReason)
	{
	case 1:
		setSound(1);
		_sound.play();
		break;
	case 2:
		setSound(2);
		_sound.play();
		break;
	}
	if (_speed < 10)
	{
		_speed += 0.05;
	}


}

void Ball::checkCollision(int value)
{
	_collision = value;
}

void Ball::draw(sf::RenderWindow& window)
{
	window.draw(_ball);
}

bool Ball::GetIsUnderMap()
{
	return _isUnderMap;
}
