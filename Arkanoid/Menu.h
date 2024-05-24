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
	const std::string _previewPath = "ArkanoidUltra_Data/Level/Previews/";
	const std::string _imgFileExtension = ".png";
	int _state;
	int _level;
	int _knownLevels;
	enum state { TITLE, EPISODES, LEVELS, QUIT,INSTRUCTION };

	sf::Font font;

	int _firstOptionY;
	int _secondOptionY;
	int _thirdOptionY;
	int _fourthOptionY;

	//Checks
	bool enterIsPressed;
	bool upIsPressed;
	bool downIsPressed;
	bool leftIsPressed;
	bool rightIsPressed;

	//Images
	sf::Texture _textureBackground;
	sf::RectangleShape _background;

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

	//Text Options
	sf::Text _firstOption;
	sf::Text _secondOption;
	sf::Text _thirdOption;
	sf::Text _fourthOption;
	//--Shadows
	sf::Text _SfirstOption;
	sf::Text _SsecondOption;
	sf::Text _SthirdOption;
	sf::Text _SfourthOption;
	sf::Text _chooseEpisode;
	sf::Text _SchooseEpisode;

	sf::FloatRect textRect;

	//Audios
	sf::SoundBuffer _buffer;
	sf::Sound _music;
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
	bool loadPreview(int level);
	bool SetMusic();
	bool SetBackground();
	//Setters
	void SetState(int state);
	//Getters
	int GetState();

	//Select Option
	void HighlightOption(sf::RenderWindow& window);
	int ChangeOption();
	int ConfirmOption(int option);

	//Other
	void updateMaxOptionNumber();
	void updateText();
	void Draw(sf::RenderWindow& window);
};

