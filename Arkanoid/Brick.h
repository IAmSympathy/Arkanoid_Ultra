#pragma once
#include <SFML/Graphics.hpp>
class Brick
{
private:
	int _point;
	int _health;
	int _type;
	sf::IntRect _rectSprite;
	sf::Texture _texture;
	sf::RectangleShape _brick;

	const int _width = 15;
	const int _height = 7;
	const int sizeMultiplier = 4;
public:
	Brick();
	Brick(int type);
	~Brick();
	bool setTextureBrick();
	void drawBrick(sf::RenderWindow& window);
};