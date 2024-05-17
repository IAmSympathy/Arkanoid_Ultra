#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
class Interface
{
private:
	//Attributes
 	sf::Font font;

	//Title Screen
	int option;
	sf::RectangleShape _logo;
	sf::Texture _logoTexture;
	sf::Text _optionPlay;
	sf::Text _optionExit;

	//In-Game Stats
	sf::RectangleShape _live;
	sf::Texture _liveTexture;
	sf::Text _score;
	sf::Text _highscore;

public:
	//Constructor
	Interface();

	///Actions
	void Initialize();
	//Title Screen
	void HighlightOption(sf::RenderWindow& window);
	int ChangeOption(sf::Event& event);
	void ConfirmOption(sf::RenderWindow& window, int option);
	//In-Game
	void updateScore(int scoreValue, int highscoreValue);

	//Load
	bool loadLogo();
	bool loadLiveIcon();
	bool loadFont();

	//Draw
	void DrawTitleScreen(sf::RenderWindow& window);
	void DrawInGameStats(sf::RenderWindow& window);
};

