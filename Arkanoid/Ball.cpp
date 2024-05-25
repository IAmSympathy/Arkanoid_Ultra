#include "Ball.h"

Ball::Ball()
{
	_velocity.x = 1;
	_velocity.y = 1;
	_speed = 5;
	_collision = 0;
	_isUnderMap = true;
	_State = THROW;

	_leftBorder = 0;
	_rightBorder = 0;
	_upBorder = 0;

	_ball.scale(sizeMultiplier, sizeMultiplier);
	_ball.setPosition(960, 1015 - (8 / 2) * 4 - (_height / 2) * 4);
	_ball.setOrigin(_width / 2, _height / 2);
	_ball.setSize(Vector2f(_width, _height));	// On définit ses dimensions
	_ball.setFillColor(Color::White);
	_rectSprite = IntRect(0, 0, _width, _height);
}

Ball::~Ball()
{
	_velocity.x = 0;
	_velocity.y = 0;
	_speed = 0;
	_collision = 0;
	_isUnderMap = true;
	_State = DEAD;

	_leftBorder = 0;
	_rightBorder = 0;
	_upBorder = 0;
}

RectangleShape Ball::getBall()
{
	return _ball;
}

bool Ball::SetTexture()
{
	_ball.setTextureRect(_rectSprite);

	if (!_texture.loadFromFile("ArkanoidUltra_Data/Sprites/Ball.png"))
		return false;

	_ball.setTexture(&_texture);
}

void Ball::Move()
{
	Vector2f position;
	position = _ball.getPosition();

	if (_State == ALIVE)
	{
		float norme = sqrt(_velocity.x * _velocity.x + _velocity.y * _velocity.y);
		if (norme != 0) {
			_velocity.x /= norme;
			_velocity.y /= norme;
		}

		_time = _clock.getElapsedTime();
		if (_time.asMilliseconds() >= 10.0f)
		{
			if (position.x < _leftBorder + _width * sizeMultiplier / 2 || position.x > _rightBorder - _width * sizeMultiplier / 2) {
				_velocity.x *= -1;
				Bounce(1);
			}

			if (position.y < _upBorder + _height * sizeMultiplier)
			{
				_velocity.y *= -1;
				Bounce(1);
			}

			if (position.y > 1080 + _height * sizeMultiplier / 2)
			{
				_State = DEAD;
			}
			_ball.setPosition(position.x + _velocity.x * _speed, position.y + _velocity.y * _speed);
			_clock.restart();
		}
	}
}

void Ball::MoveThrow(RectangleShape player)
{
	Vector2f playerPosition = player.getPosition();
	if (_State == THROW)
	{
		_ball.setPosition(playerPosition.x, playerPosition.y - (8 / 2) * 4 - (_height / 2) * 4);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))	//If the 'SPace' key is pressed, throws the Ball
		{
			_State = ALIVE;
		}
	}
}

bool Ball::SetSound(int bounceReason)
{
	switch (bounceReason)
	{
	case 1:
		if (!_buffer.loadFromFile("ArkanoidUltra_Data/Sounds/BallWall.wav"))
			return false;
		break;
	case 2:
		if (!_buffer.loadFromFile("ArkanoidUltra_Data/Sounds/BallPlayer.wav"))
			return false;
		break;
	case 3:
		if (!_buffer.loadFromFile("ArkanoidUltra_Data/Sounds/BallBrick.wav"))
			return false;
		break;
	}
	_sound.setBuffer(_buffer);
}

void Ball::SetAngle(double xVelocity, double yVelocity)
{
	_velocity.x = xVelocity;
	_velocity.y = yVelocity;
}

void Ball::Reset(int State)
{
	_State = State;
}

void Ball::SetBorders(int leftBorder, int rightBorder, int upBorder)
{
	_leftBorder = leftBorder;
	_rightBorder = rightBorder;
	_upBorder = upBorder;
}

int Ball::GetState()
{
	return _State;
}

void Ball::CheckCollision(double angle)
{
	if (angle != -6969)
	{
		if (angle < 90)
		{
			if (angle < 25)
			{
				if (angle < 15)
				{
					SetAngle(0.90, -1);
				}
				else
					SetAngle(0.75, -1);
			}
			else
				SetAngle(0.5, -1);
		}
		else if (angle > 90)
		{
			if (angle > 155)
			{
				if (angle > 164)
				{
					SetAngle(-0.90, -1);
				}
				else
					SetAngle(-0.75, -1);
			}
			else
				SetAngle(-0.5, -1);
		}
		else if (angle > 180 || angle < 0)
		{
			_velocity.y *= -1;
			SetAngle(_velocity.x, _velocity.y);
		}

		Bounce(2);
	}

}

void Ball::Bounce(int bounceReason)
{

	switch (bounceReason)
	{
	case 1:
		SetSound(1);
		_sound.play();
		break;
	case 2:
		SetSound(2);
		_sound.play();
	case 3:
		SetSound(3);
		_sound.play();
		break;
	}
	if (_speed <8)
	{
		_speed += 0.05;
	}
}

void Ball::Revive()
{
	_speed = 5;
	_State = THROW;
	_velocity.x = 1;
	_velocity.y = 1;
}

void Ball::Draw(sf::RenderWindow& window)
{
	if (_State != DEAD)
		window.draw(_ball);
}