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

	//In-Game Stats
	sf::RectangleShape _liveIcon;
	sf::Texture _liveTexture;
	sf::Text _livesText;
	sf::Text _lives;
	sf::Text _score;
	sf::Text _scoreText;
	sf::Text _highscore;
	sf::Text _highscoreText;
	sf::Text _level;
	sf::Text _levelText;
	///Shadow
	sf::RectangleShape _SliveIcon;
	sf::Texture _SliveTexture;
	sf::Text _SlivesText;
	sf::Text _Slives;
	sf::Text _Sscore;
	sf::Text _SscoreText;
	sf::Text _Shighscore;
	sf::Text _ShighscoreText;
	sf::Text _Slevel;
	sf::Text _SlevelText;

public:
	//Constructor
	UserInterface();

	//In-Game
	void updateStats(int scoreValue, int highscoreValue, int lives, int level);

	//Load
	bool loadLiveIcon();
	bool loadFont();

	//Draw
	void DrawInGameStats(sf::RenderWindow& window);
};

