#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace sf;	
using namespace std;	

class Ball
{
private:
	//Attributes
	Vector2f _velocity;
	float _speed;
	const int _width = 5;
	const int _height = 4;
	const int sizeMultiplier = 4;

	//Checks
	int _collision;
	bool _isUnderMap;
	int _State;
	enum ballStates { THROW, ALIVE, DEAD };

	//Ball's sprite
	sf::RectangleShape _ball;
	sf::Texture _texture;
	sf::IntRect _rectSprite;

	//Audio
	sf::SoundBuffer _buffer;
	sf::Sound _sound;

	//Clock
	sf::Clock _clock;		
	sf::Clock _clockSprite;
	sf::Time _time;

	//Others
	int _leftBorder, _rightBorder, _upBorder;
public:
	//Constructors
	Ball();
	~Ball();
	//Actions
	void Move();
	void MoveThrow(RectangleShape player);
	void Bounce(int bounceReason);
	void Revive();

	//Getters
	RectangleShape getBall();
	int GetState();

	//Setters
	void SetAngle(double xVelocity, double yVelocity);
	void Reset(int State);
	void SetBorders(int leftBorder, int rightBorder, int upBorder);

	bool SetTexture();
	bool SetSound(int bounceReason);

	//Others
	void CheckCollision(double value);
	void Draw(sf::RenderWindow& window);
};

