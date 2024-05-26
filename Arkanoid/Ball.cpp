/*====================================
// Filename : Ball.cpp
// Description : This file contains the implementation of the Ball class
//				 which contains the ball's movements, collision checks, sounds and states
// Author : Samy Larochelle
// Date : May 9th, 2024
====================================*/
#include "Ball.h"
using namespace sf;
using namespace std;

Ball::Ball()
{
	//Attributes
	_velocity.x = 1;
	_velocity.y = 1;
	_speed = 5;

	_collision = 0;
	_leftBorder = 0;
	_rightBorder = 0;
	_upBorder = 0;

	//Checks
	_isUnderMap = true;
	_firstThrow = true;
	_startMusic = false;
	_state = THROW;

	//Sprite
	_ball.scale(sizeMultiplier, sizeMultiplier);
	_ball.setPosition(960, 1015 - (8 / 2) * 4 - (_height / 2) * 4);
	_ball.setOrigin(_width / 2, _height / 2);
	_ball.setSize(Vector2f(_width, _height));	
	_ball.setFillColor(Color::White);
	_rectSprite = IntRect(0, 0, _width, _height);

	//Load ressources
	LoadSounds();

	cout << "[Player] Ball has been created " << endl;
}

Ball::~Ball()
{
	_velocity.x = 0;
	_velocity.y = 0;
	_speed = 0;
	_collision = 0;
	_isUnderMap = true;
	_state = DEAD;

	_leftBorder = 0;
	_rightBorder = 0;
	_upBorder = 0;

	_isUnderMap = true;
	_firstThrow = true;
	_startMusic = false;
	_state = THROW;
}

RectangleShape Ball::GetBall() const
{
	return _ball;
}

bool Ball::LoadTexture()
{
	_ball.setTextureRect(_rectSprite);

	cout << "[Ball::Load] Loading sprite" << endl;
	if (!_texture.loadFromFile("ArkanoidUltra_Data/Sprites/Ball.png"))
		return false;

	_ball.setTexture(&_texture);
}

//The ball's movement while its state is ALIVE
void Ball::Move()
{
	Vector2f position;
	position = _ball.getPosition();

	if (_state == ALIVE)
	{
		float norme = sqrt(_velocity.x * _velocity.x + _velocity.y * _velocity.y);
		if (norme != 0) {
			_velocity.x /= norme;
			_velocity.y /= norme;
		}

		//If the ball hits a wall, inverts the velocity.y
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

			if (position.y > 1080 + _height * sizeMultiplier / 2)	//If the ball goes under the map, set state to DEAD
			{
				SetState(DEAD);
			}
			_ball.setPosition(position.x + _velocity.x * _speed, position.y + _velocity.y * _speed);
			_clock.restart();
		}
	}
}

//The ball's movement while its state is THROW
void Ball::MoveThrow(RectangleShape player)
{
	Vector2f playerPosition = player.getPosition();
	if (_state == THROW)
	{
		_ball.setPosition(playerPosition.x, playerPosition.y - (8 / 2) * 4 - (_height / 2) * 4);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))	//If the 'Space' key is pressed, sets the state to ALIVE
		{
			if (_firstThrow == true)	//If this is the first throw, plays a sound and allow the level music to start
			{
				LoadBounceSounds(1);
				_firstThrowSound.play();
				_startMusic = true;
				_firstThrow = false;
			}
			SetState(ALIVE);
		}
	}
}

//Load a different sound based on the bounce parameter
bool Ball::LoadBounceSounds(int bounceReason)
{
	switch (bounceReason)
	{
	case 1:
		cout << "[Ball::Load] Wall hit sound" << endl;
		if (!_buffer.loadFromFile("ArkanoidUltra_Data/Sounds/BallWall.wav"))
			return false;
		break;
	case 2:
		cout << "[Ball::Load] Player hit sound" << endl;
		if (!_buffer.loadFromFile("ArkanoidUltra_Data/Sounds/BallPlayer.wav"))
			return false;
		break;
	case 3:
		cout << "[Ball::Load] Brick hit sound" << endl;
		if (!_buffer.loadFromFile("ArkanoidUltra_Data/Sounds/BallBrick.wav"))
			return false;
		break;
	}
	_sound.setBuffer(_buffer);
}

bool Ball::LoadSounds()
{
	cout << "[Ball::Load] First throw sound" << endl;
	if (!_firstThrowBuffer.loadFromFile("ArkanoidUltra_Data/Sounds/LevelStart.wav"))
		return false;
	_firstThrowSound.setBuffer(_firstThrowBuffer);
}

void Ball::SetStartMusic(bool value)
{
	_startMusic = value;
}

void Ball::SetAngle(double xVelocity, double yVelocity)
{
	_velocity.x = xVelocity;
	_velocity.y = yVelocity;
}

void Ball::SetState(int state)
{
	_state = state;
	cout << "[Ball] Setting state to" << _state << endl;
}

int Ball::GetHeight() const
{
	return _height;
}

sf::Vector2f Ball::GetVelocity() const
{
	return _velocity;
}

void Ball::SetBorders(int leftBorder, int rightBorder, int upBorder)
{
	_leftBorder = leftBorder;
	_rightBorder = rightBorder;
	_upBorder = upBorder;
}

int Ball::GetState() const
{
	return _state;
}

bool Ball::GetStartMusic() const
{
	return _startMusic;
}

//Sets the ball velicities (x,y) depending on the angle it hit the player
void Ball::CheckCollision(double angle)
{
	if (angle != -6969)
	{
		if (angle < 90)
		{
			if (angle < 36)
			{
				if (angle < 25)
				{
					SetAngle(0.90, -0.50);
					cout << "[Ball::Collsion] R Blue" << endl;
				}
				else
				{
					SetAngle(0.75, -1);
					cout << "[Ball::Collsion] R Red" << endl;
				}
			}
			else
			{
				SetAngle(0.5, -1);
				cout << "[Ball::Collsion] R Gray" << endl;
			}
		}
		else if (angle > 90)
		{
			if (angle > 144)
			{
				if (angle > 155)
				{
					SetAngle(-0.90, -0.50);
					cout << "[Ball::Collsion] L Blue" << endl;
				}
				else
				{
					SetAngle(-0.75, -1);
					cout << "[Ball::Collsion] L Red" << endl;
				}
			}
			else
			{
				SetAngle(-0.5, -1);
				cout << "[Ball::Collsion] L Gray" << endl;
			}
		}
		else if (angle > 180 || angle < 0)
		{
			_velocity.y *= -1;
			SetAngle(_velocity.x, _velocity.y);
		}
		Bounce(2);
	}
}

//Plays a sound depending on which collsion type it hit (wall,player, brick) and and makes the ball faster each time
void Ball::Bounce(int bounceReason)
{

	switch (bounceReason)
	{
	case 1:
		LoadBounceSounds(1);
		_sound.play();
		break;
	case 2:
		LoadBounceSounds(2);
		_sound.play();
		break;
	case 3:
		LoadBounceSounds(3);
		_sound.play();
		break;
	}
	if (_speed < 8)
	{
		_speed += 0.05;
	}
}

//Resets the ball's speed, state and angle (velocity)
void Ball::Revive()
{
	cout << "[Ball] Reviving ball" << endl;
	_speed = 5;
	_state = THROW;
	_velocity.x = 1;
	_velocity.y = 1;
}

//Allows the ball to play the first throw sound
void Ball::Reset()
{
	_firstThrow = true;
}

void Ball::Draw(sf::RenderWindow& window)
{
	if (_state != DEAD)
		window.draw(_ball);
}