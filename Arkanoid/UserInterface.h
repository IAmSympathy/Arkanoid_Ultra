/*====================================
// Filename : UserInterface.h
// Description : This file contains the definition of the UserInterface class
//				 which contains the stats' texts and icons and logic
// Author : Samy Larochelle
// Date : May 16th, 2024
====================================*/
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Font.hpp>

class UserInterface
{
private:
	//Attributes
	sf::Font font;
	sf::RectangleShape _liveIcon;
	sf::Texture _liveIconTexture;
	sf::Text _livesText;
	sf::Text _lives;
	sf::Text _score;
	sf::Text _scoreText;
	sf::Text _highscore;
	sf::Text _highscoreText;
	sf::Text _level;
	sf::Text _levelText;
	///Shadows
	sf::RectangleShape _liveIconShadow;
	sf::Texture _liveIconTextureShadow;
	sf::Text _livesTextShadow;
	sf::Text _livesShadow;
	sf::Text _scoreShadow;
	sf::Text _scoreTextShadow;
	sf::Text _highscoreShadow;
	sf::Text _highscoreTextShadow;
	sf::Text _levelShadow;
	sf::Text _levelTextShadow;
public:
	//Constructor
	UserInterface();

	//Action
	void updateStats(int scoreValue, int highscoreValue, int lives, int level);

	//Load
	bool loadLiveIcon();
	bool loadFont();

	//Draw
	void DrawInGameStats(sf::RenderWindow& window);
};

