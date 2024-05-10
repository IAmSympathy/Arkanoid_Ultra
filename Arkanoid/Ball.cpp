#include "Ball.h"

Ball::Ball()
{
	_ball.setPosition(960, 520);		// On définit sa position
	_ball.setSize(Vector2f(16, 13));	// On définit ses dimensions
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

	_time = _clock.getElapsedTime(); // Prends le temps de l’horloge
	if (_time.asMilliseconds() >= 10.0f)
	{
		if (position.x < 521 || position.x > 1395 - 16) {
			xVelocity *= -1;
			bounce(1);
		}

		if (position.y < 100 || position.y > 1080 - 13)
		{
			yVelocity *= -1;
			bounce(1);
		}

		_ball.setPosition(position.x + xVelocity, position.y + yVelocity);
		_clock.restart(); // On remet l’horloge à 0
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

void Ball::bounce(int bounceReason)
{
	switch (bounceReason)
	{
	case 1:
		if (!(xVelocity > 3.5 || yVelocity > 3.5))
		{
			if (xVelocity < 0)
				xVelocity -= 0.01;
			else
				xVelocity += 0.01;

			if (yVelocity < 0)
				yVelocity += 0.01;
			else
				yVelocity -= 0.01;
		}
		setSound(1);
		_sound.play();
		break;
	}


}

void Ball::draw(sf::RenderWindow& window)
{
	window.draw(_ball);
}
