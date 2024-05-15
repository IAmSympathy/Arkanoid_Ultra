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
	bool _isDead;

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

	//Actions
	void Move();
	void Bounce(int bounceReason);

	//Getters
	RectangleShape getBall();
	bool GetIsUnderMap();
	bool GetIsDead();

	//Setters
	void SetAngle(double xVelocity, double yVelocity);
	void SetIsUnderMap(bool isUnderMap);
	void SetIsDead(bool isDead);
	void SetBorders(int leftBorder, int rightBorder, int upBorder);

	bool SetTexture();
	bool SetSound(int bounceReason);

	//Others
	void CheckCollision(int value);
	void Draw(sf::RenderWindow& window);
};

