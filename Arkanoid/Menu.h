/*====================================
// Filename : Menu.h
// Description : This file contains the definitions of the Menu class
//				 which contains the menu logic, states and screens
// Author : Samy Larochelle
// Date : May 13th, 2024
====================================*/
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Font.hpp>


class Menu
{
private:
	//Attributes
	int _option;
	const int _minOption = 1;
	int _maxOption = 2;
	int _state;
	int _knownLevels;
	const int _maxLevels = 3;
	enum state { TITLE, EPISODES, LEVELS, QUIT, INSTRUCTIONS, GAMEOVER, PAUSE };
	const std::string _levelPreviewPath = "ArkanoidUltra_Data/Previews/Levels/";
	const std::string _episodePreviewPath = "ArkanoidUltra_Data/Previews/Episodes/";
	const std::string _imgFileExtension = ".png";
	sf::Font font;

	//Checks
	bool enterIsPressed;
	bool escapeIsPressed;
	bool upIsPressed;
	bool downIsPressed;
	bool leftIsPressed;
	bool rightIsPressed;

	//Text positions
	int _firstOptionY;
	int _secondOptionY;
	int _thirdOptionY;
	int _fourthOptionY;
	int _fifthOptionY;
	int _chooseEpisodeX;
	int _chooseEpisodeY;
	//Text Options
	sf::Text _firstOption;
	sf::Text _secondOption;
	sf::Text _thirdOption;
	sf::Text _fourthOption;
	sf::Text _fifthOption;
	sf::FloatRect textRect;
	//Shadows
	sf::Text _firstOptionShadow;
	sf::Text _secondOptionShadow;
	sf::Text _thirdOptionShadow;
	sf::Text _fourthOptionShadow;
	sf::Text _fifthOptionShadow;
	sf::Text _headerText;
	sf::Text _headerTextShadow;
	sf::Text _levelNumber;
	sf::Text _levelNumberShadow;
	std::string number;

	//Image actors
	sf::Texture _textureBackground;
	sf::RectangleShape _background;
	sf::RectangleShape _textBG;
	sf::Texture _textureLevelOverlay;
	sf::RectangleShape _levelOverlay;
	sf::RectangleShape _logo;
	sf::Texture _logoTexture;
	sf::RectangleShape _Slogo;
	sf::Texture _SlogoTexture;
	sf::Texture _texturePreviewLeft;
	sf::RectangleShape _previewLeft;
	sf::Texture _texturePreviewMiddle;
	sf::RectangleShape _previewMiddle;
	sf::Texture _texturePreviewRight;
	sf::RectangleShape _previewRight;
	sf::Texture _texturePreviewRightLocked;
	sf::RectangleShape _previewRightLocked;
	sf::Texture _textureEpisodePreview;
	sf::RectangleShape _episodePreview;

	//Audio
	sf::SoundBuffer _buffer;
	sf::Sound _music;
	sf::SoundBuffer _confirmBuffer;
	sf::Sound _confirmSound;
	sf::SoundBuffer _changeBuffer;
	sf::Sound _changeSound;
public:
	//Constructors
	Menu();

	///Actions
	void Initialize();
	void HighlightOption();
	int ChangeOption();
	int ConfirmOption(int option);
	void UpdateMaxOptionNumber();
	void UpdateText(int level);
	void UpdateTextBG();
	//Checks
	void IsKeyPressed(sf::Event event);

	//Getters
	int GetState() const;
	int GetOption() const;
	//Setters
	void SetState(int state);

	//Load ressources
	bool LoadLogo();
	bool LoadFont();
	bool LoadLevelPreview(int level);
	bool LoadEpisodePreview(int option);
	bool LoadMusic();
	bool LoadSounds();
	bool LoadBackground();

	//Other
	void Draw(sf::RenderWindow& window);
};

