/*====================================
// Filename : BrickField.h
// Description : This file contains the implementation of the BrickField class
//				 which contains the logic of the creation of the BrickField
// Author : Loucas Viens, Samy Larochelle
// Date : May 25th, 2024
====================================*/
#include "BrickField.h"
using namespace::std;
using namespace::sf;

//Checks if the ball is in collsion with the brick and within each of the brick's sides
void BrickField::CheckCollision(Brick& brick, Ball& ball)
{
	Vector2f position = ball.GetBall().getPosition();
	Vector2f velocity = ball.GetVelocity();
	if (_isCollision == true)
	{
		_time = _clock.getElapsedTime();
		if (_time.asMilliseconds() >= 10.0f)
		{
			_isCollision = false;
			_clock.restart();
		}
	}
	if (_isCollision == false)
	{
		_clock.restart();
		if (ball.GetBall().getGlobalBounds().intersects(brick.GetBrick().getGlobalBounds()) && position.x >= brick.GetLeft() && position.x <= brick.GetRight() && position.y + ball.GetHeight() * 4 >= brick.GetUp())
		{
			velocity.y *= -1;
			_isCollision = true;
			ball.Bounce(3);
			switch (brick.GetType())
			{
			default:
				brick.Hit(_textureNormal);
				break;
			case 8:
				brick.Hit(_textureSilver);
				break;
			case 9:
				brick.Hit(_textureGold);
				break;
			}

		}
		if (ball.GetBall().getGlobalBounds().intersects(brick.GetBrick().getGlobalBounds()) && position.y >= brick.GetUp() && position.y <= brick.GetDown())
		{
			velocity.x *= -1;
			_isCollision = true;
			ball.Bounce(3);
			switch (brick.GetType())
			{
			default:
				brick.Hit(_textureNormal);
				break;
			case 8:
				brick.Hit(_textureSilver);
				break;
			case 9:
				brick.Hit(_textureGold);
				break;
			}
		}
	}
	ball.SetAngle(velocity.x, velocity.y);
}

//Loads a file and read the bricks currentType and position from it
void BrickField::InitializeField(int level)
{
	LoadTexture();

	Vector2f position(510, 272);
	std::vector<char> typeField;
	char currentType = ' ';
	std::string currentLine;
	int lineAmount = 0;
	int counter = 0;

	ifstream levelFile;
	levelFile.open("ArkanoidUltra_Data/Levels/1.txt");

	while (getline(levelFile, currentLine))
	{
		lineAmount++;
	}
	levelFile.close();
	levelFile.open("ArkanoidUltra_Data/Levels/1.txt");
	while (!levelFile.eof())
	{
		levelFile.get(currentType);
		if (currentType != '\n')
		{
			typeField.push_back(currentType);
		}
	}
	currentType = ' ';
	for (int y = 1; y < lineAmount + 1; y++)
	{
		for (int x = 1; x <= 13; x++)
		{
			currentType = typeField.at(counter);
			if (currentType == '_')
			{
				currentType -= 48;
			}
			currentType -= 48;
			Brick newBrick(currentType);
			newBrick.setPosition(position.x + 60 * x, position.y + 28 * y);
			newBrick.CreateBorder();
			switch (currentType)
			{
			case 8:
				newBrick.SetTexture(_textureGold);
				break;
			case 9:
				newBrick.SetTexture(_textureSilver);
				break;
			default:
				newBrick.SetTexture(_textureNormal);
				break;
			}
			_field.push_back(newBrick);
			counter++;
		}
	}
	levelFile.close();
}

void BrickField::UpdateShadows(Ball ball)
{
	_shadowField.resize(_field.size());
	for (int i = 0; i < _field.size(); i++)
	{
		Vector2f position = _field[i].GetBrick().getPosition();
		CheckCollision(_field[i], ball);
		_field[i].GoldBrickAnimation();
		_shadowField[i].SetBrick(_field[i].GetBrick());
		_shadowField[i].SetType(_field[i].GetType());
		if (_shadowField[i].GetType() != -1)
		{
			_shadowField[i].SetType(-2);
		}
		_shadowField[i].setPosition(position.x + 16, position.y + 16);
	}
}

std::vector<Brick> BrickField::GetField()
{
	return _field;
}


bool BrickField::LoadTexture()
{
	if (!_textureNormal.loadFromFile("ArkanoidUltra_Data/Sprites/Bricks.png"))
		return false;
	if (!_textureSilver.loadFromFile("ArkanoidUltra_Data/Sprites/BricksSilver.png"))
		return false;
	if (!_textureGold.loadFromFile("ArkanoidUltra_Data/Sprites/BricksGold.png"))
		return false;
	cout << "All brick textures have been loaded" << endl;
	return true;
}

void BrickField::Draw(sf::RenderWindow& window, Ball ball)
{
	UpdateShadows(ball);
	for (int i = 0; i < _field.size(); i++)
	{
		if (_field[i].GetHealth() > 0)
		{
			if (_shadowField[i].GetType() != -1)
			{
				_shadowField[i].SetRectSpriteTop(63);
			}
			window.draw(_shadowField[i].GetBrick());
			window.draw(_field[i].GetBrick());
		}
	}
}

//Counts how many bricks are left in the brick field
void BrickField::CountBrickLeft()
{
	for (int i = 0; i < _field.size(); i++)
	{
		if (_field[i].GetHealth() > 0)
		{
			_nbBrick++;
		}
	}
	//Resets the number of brick counted if it is not equal to 0
	if (_nbBrick != 0)
	{
		_nbBrick = 0;
	}
}
