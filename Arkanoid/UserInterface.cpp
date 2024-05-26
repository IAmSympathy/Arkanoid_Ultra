/*====================================
// Filename : UserInterface.cpp
// Description : This file contains the implementation of the UserInterface class
//				 which contains the stats' texts and icons and logic
// Author : Samy Larochelle
// Date : May 16th, 2024
====================================*/

#include "UserInterface.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace::std;
using namespace::sf;

UserInterface::UserInterface()
{
	//Load ressources
	loadFont();
	loadLiveIcon();

	//Text actors
	_scoreText.setString("SCORE");
	_score.setString("");
	_scoreText.setFont(font);
	_scoreText.setPosition(160, 140);
	_scoreText.setFillColor(Color::Red);
	_scoreText.setCharacterSize(32);
	_score.setFont(font);
	_score.setPosition(180, 200);
	_score.setFillColor(Color::White);
	_score.setCharacterSize(32);
	_highscoreText.setString("HIGHSCORE");
	_highscore.setString("");
	_highscoreText.setFont(font);
	_highscoreText.setPosition(160, 400);
	_highscoreText.setFillColor(Color::Yellow);
	_highscoreText.setCharacterSize(32);
	_highscore.setFont(font);
	_highscore.setPosition(180, 460);
	_highscore.setFillColor(Color::White);
	_highscore.setCharacterSize(32);
	_livesText.setString("LIVES");
	_livesText.setFont(font);
	_livesText.setPosition(160, 900);
	_livesText.setFillColor(Color::Blue);
	_livesText.setCharacterSize(32);
	_liveIcon.setPosition(190, 965);
	_liveIcon.setSize(Vector2f(16, 8));
	_liveIcon.setScale(4, 4);
	_lives.setString("");
	_lives.setFont(font);
	_lives.setPosition(290, 960);
	_lives.setFillColor(Color::White);
	_lives.setCharacterSize(32);
	_levelText.setString("ROUND");
	_levelText.setFont(font);
	_levelText.setPosition(1490, 550);
	_levelText.setFillColor(Color::Green);
	_levelText.setCharacterSize(40);
	_level.setString("");
	_level.setFont(font);
	_level.setPosition(1750, 550);
	_level.setFillColor(Color::White);
	_level.setCharacterSize(40);
	//Shadows
	_scoreTextShadow.setString("SCORE");
	_scoreShadow.setString("");
	_scoreTextShadow.setFont(font);
	_scoreTextShadow.setPosition(160 + 8, 140 + 8);
	_scoreTextShadow.setFillColor(Color::Black);
	_scoreTextShadow.setCharacterSize(32);
	_scoreShadow.setFont(font);
	_scoreShadow.setPosition(180 + 8, 200 + 8);
	_scoreShadow.setFillColor(Color::Black);
	_scoreShadow.setCharacterSize(32);
	_highscoreTextShadow.setString("HIGHSCORE");
	_highscoreShadow.setString("");
	_highscoreTextShadow.setFont(font);
	_highscoreTextShadow.setPosition(160 + 8, 400 + 8);
	_highscoreTextShadow.setFillColor(Color::Black);
	_highscoreTextShadow.setCharacterSize(32);
	_highscoreShadow.setFont(font);
	_highscoreShadow.setPosition(180 + 8, 460 + 8);
	_highscoreShadow.setFillColor(Color::Black);
	_highscoreShadow.setCharacterSize(32);
	_livesTextShadow.setString("LIVES");
	_livesTextShadow.setFont(font);
	_livesTextShadow.setPosition(160 + 8, 900 + 8);
	_livesTextShadow.setFillColor(Color::Black);
	_livesTextShadow.setCharacterSize(32);
	_livesShadow.setString("");
	_livesShadow.setFont(font);
	_livesShadow.setPosition(290 + 8, 960 + 8);
	_livesShadow.setFillColor(Color::Black);
	_livesShadow.setCharacterSize(32);
	_levelTextShadow.setString("ROUND");
	_levelTextShadow.setFont(font);
	_levelTextShadow.setPosition(1490 + 8, 550 + 8);
	_levelTextShadow.setFillColor(Color::Black);
	_levelTextShadow.setCharacterSize(40);
	_levelShadow.setString("");
	_levelShadow.setFont(font);
	_levelShadow.setPosition(1750 + 8, 550 + 8);
	_levelShadow.setFillColor(Color::Black);
	_levelShadow.setCharacterSize(40);
}

void UserInterface::updateStats(int scoreValue, int highscoreValue, int lives, int level)
{
	_lives.setString(std::to_string(lives));
	_score.setString(std::to_string(scoreValue));
	_level.setString(std::to_string(level));
	//Shadow
	_livesShadow.setString(std::to_string(lives));
	_scoreShadow.setString(std::to_string(scoreValue));
	_levelShadow.setString(std::to_string(level));

	if (scoreValue > highscoreValue)
	{
		_highscore.setString(std::to_string(scoreValue));
		_highscoreShadow.setString(std::to_string(scoreValue));
	}

	else
	{
		_highscore.setString(std::to_string(highscoreValue));
		_highscoreShadow.setString(std::to_string(highscoreValue));
	}

}

bool UserInterface::loadFont()
{
	if (!font.loadFromFile("ArkanoidUltra_Data/Font/nintendo-nes-font.ttf"))
	{
		return false;
	}
}

bool UserInterface::loadLiveIcon()
{
	if (!_liveIconTexture.loadFromFile("ArkanoidUltra_Data/Sprites/Menu/IconLive.png"))
	{
		return false;
	}

	_liveIcon.setTexture(&_liveIconTexture);
}

void UserInterface::DrawInGameStats(sf::RenderWindow& window)
{
	//Shadows
	window.draw(_scoreTextShadow);
	window.draw(_scoreShadow);
	window.draw(_highscoreTextShadow);
	window.draw(_highscoreShadow);
	window.draw(_livesTextShadow);
	window.draw(_livesShadow);
	window.draw(_levelShadow);
	window.draw(_levelTextShadow);
	//Text
	window.draw(_scoreText);
	window.draw(_score);
	window.draw(_highscoreText);
	window.draw(_highscore);
	window.draw(_livesText);
	window.draw(_liveIcon);
	window.draw(_lives);
	window.draw(_level);
	window.draw(_levelText);
}

