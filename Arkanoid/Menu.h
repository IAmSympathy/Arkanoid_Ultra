#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Font.hpp>

using namespace sf;
using namespace std;

class Menu
{
private:
	//Attributes
	int _option;
	const int _minOption = 1;
	int _maxOption = 2;
	const std::string _levelPreviewPath = "ArkanoidUltra_Data/Previews/Levels/";
	const std::string _episodePreviewPath = "ArkanoidUltra_Data/Previews/Episodes/";
	const std::string _imgFileExtension = ".png";
	int _state;
	int _knownLevels;
	const int _maxLevels = 3;
	enum state { TITLE, EPISODES, LEVELS, QUIT, INSTRUCTIONS, GAMEOVER, PAUSE };

	sf::Font font;

	int _firstOptionY;
	int _secondOptionY;
	int _thirdOptionY;
	int _fourthOptionY;
	int _fifthOptionY;
	int _chooseEpisodeX;
	int _chooseEpisodeY;
	//Checks
	bool enterIsPressed;
	bool escapeIsPressed;
	bool upIsPressed;
	bool downIsPressed;
	bool leftIsPressed;
	bool rightIsPressed;

	//Images
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
	sf::Texture _textureEpisodePreview;
	sf::RectangleShape _episodePreview;
	//Text Options
	sf::Text _firstOption;
	sf::Text _secondOption;
	sf::Text _thirdOption;
	sf::Text _fourthOption;
	sf::Text _fifthOption;
	sf::FloatRect textRect;
	//--Shadows
	sf::Text _SfirstOption;
	sf::Text _SsecondOption;
	sf::Text _SthirdOption;
	sf::Text _SfourthOption;
	sf::Text _SfifthOption;
	sf::Text _chooseEpisode;
	sf::Text _SchooseEpisode;
	sf::Text _levelNumber;
	sf::Text _SlevelNumber;
	std::string number;


	//Audios
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

	//Checks
	void IsKeyPressed(Event event);

	//Load
	bool loadLogo();
	bool loadFont();
	bool loadLevelPreview(int level);
	bool loadEpisodePreview(int option);
	bool SetMusic();
	bool SetSounds();
	bool SetBackground();
	//Setters
	void Reset(int state);
	//Getters
	int GetState();
	int GetOption();

	//Select Option
	void HighlightOption(sf::RenderWindow& window);
	int ChangeOption();
	int ConfirmOption(int option);

	//Other
	void updateMaxOptionNumber();
	void updateText(int level);
	void updateTextBG();
	void Draw(sf::RenderWindow& window);
};

