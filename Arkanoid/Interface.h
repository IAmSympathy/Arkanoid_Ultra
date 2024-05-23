#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Font.hpp>
class Interface
{
private:
	//Attributes
	int _option;
	const int _minOption = 1;
	const int _maxOption = 2;
 	sf::Font font;


	//Title Screen
	sf::RectangleShape _logo;
	sf::Texture _logoTexture;
	sf::Text _optionPlay;
	sf::Text _optionExit;
	sf::Texture _textureBackground;
	sf::RectangleShape _background;

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
	sf::Text _SoptionPlay;
	sf::Text _SoptionExit;
	sf::RectangleShape _Slogo;
	sf::Texture _SlogoTexture;

	//Audios
	sf::SoundBuffer _buffer;
	sf::Sound _music;

public:
	//Constructor
	Interface();

	///Actions
	void Initialize();
	//Title Screen
	void HighlightOption(sf::RenderWindow& window);
	std::string ChangeOption();
	std::string ConfirmOption(int option);
	//In-Game
	void updateStats(int scoreValue, int highscoreValue, int lives, int level);

	//Load
	bool loadLogo();
	bool loadLiveIcon();
	bool loadFont();
	bool SetMusic();
	bool SetBackground();

	//Draw
	void DrawTitleScreen(sf::RenderWindow& window);
	void DrawInGameStats(sf::RenderWindow& window);
};

