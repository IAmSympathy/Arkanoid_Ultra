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
			switch (brick.GetType())
			{
			default:
				brick.Hit(_textureNormal);
				ball.Bounce(3);
				break;
			case 8:
				brick.Hit(_textureSilver);
				ball.Bounce(4);
				break;
			case 9:
				brick.Hit(_textureGold);
				ball.Bounce(5);
				break;
			}
			if (brick.GetHealth() == 0)
			{
				_score = brick.GetScore();
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
				ball.Bounce(3);
				break;
			case 8:
				brick.Hit(_textureSilver);
				ball.Bounce(4);
				break;
			case 9:
				brick.Hit(_textureGold);
				ball.Bounce(5);
				break;
			}
			if (brick.GetHealth() == 0)
			{
				_score = brick.GetScore();
			}
		}
	}
	ball.SetAngle(velocity.x, velocity.y);
}

//Loads a file and read the bricks currentType and position from it
void BrickField::InitializeField(int level, int section)
{
	LoadTexture();
	char isEnter = 0;
	Vector2f position(510, 272);
	std::vector<char> typeField;
	char currentType = ' ';
	std::string currentLine;
	int lineAmount = 0;
	int collumnAmount = 0;
	int counter = 0;
	string currentLevelPath = _levelPath;
	currentLevelPath.append(to_string(level));
	currentLevelPath.append(_levelFileExtension);

	ifstream levelFile;
	levelFile.open(currentLevelPath);
	while (getline(levelFile, currentLine))
	{
		collumnAmount = currentLine.length();
		lineAmount++;
	}
	levelFile.close();

	levelFile.open(currentLevelPath);
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
		for (int x = 1; x <= collumnAmount; x++)
		{
			currentType = typeField.at(counter);
			if (currentType == '_')
			{
				currentType = -48;
			}
			currentType -= 48;
			Brick newBrick(currentType);
			newBrick.setPosition(position.x + 60 * x, position.y + 28 * y);
			newBrick.CreateBorder();
			if (newBrick.GetType()== 8)
			{
				newBrick.SilverPoint(level);
				newBrick.SilverHealth(section);
			}
			if (newBrick.GetType() == -96)
			{
				newBrick.SetHealth(0);
			}
			switch (currentType)
			{
			case 8:
				newBrick.SetTexture(_textureSilver);
				break;
			case 9:
				newBrick.SetTexture(_textureGold);
				break;
			default:
				newBrick.SetTexture(_textureNormal);
				break;
			}
			_field.push_back(newBrick);
			counter++;
		}
	}
	typeField.clear();
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

int BrickField::GetScore()
{
	return _score;
}

int BrickField::GetNbBrickLeft()
{
	return _nbBrickLeft;
}

void BrickField::SetField(std::vector<Brick>& field)
{
	for (int i = 0; i < field.size(); i++)
	{
		_field[i].SetHealth(field[i].GetHealth());
		_field[i].SetUp(field[i].GetUp());
		_field[i].SetDown(field[i].GetDown());
		_field[i].SetLeft(field[i].GetLeft());
		_field[i].SetRight(field[i].GetRight());
	}
}

void BrickField::SetScore(int score)
{
	_score = score;
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
			switch (_field[i].GetType())
			{
			case 8:
				_field[i].SetTexture(_textureSilver);
				break;
			case 9:
				_field[i].SetTexture(_textureGold);
				break;
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
			_nbBrickLeft++;
		}
	}
	//Resets the number of brick counted if it is not equal to 0
	if (_nbBrickLeft != 0)
	{
		_nbBrickLeft = 0;
	}
	else if (_nbBrickLeft == 0)
	{
		_nbBrickLeft = -1;
	}
}

void BrickField::Reset()
{
	_field.clear();
	_shadowField.clear();
}
