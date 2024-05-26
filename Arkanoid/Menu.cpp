/*====================================
// Filename : Menu.h
// Description : This file contains the implementation of the Menu class
//				 which contains the menu logic, states and screens
// Author : Samy Larochelle
// Date : May 13th, 2024
====================================*/
#include "Menu.h"
using namespace sf;
using namespace std;

Menu::Menu()
{
	//Attributes
	_state = TITLE;
	_option = 1;
	_knownLevels = 2;
	//Checks
	escapeIsPressed = false;
	enterIsPressed = false;
	upIsPressed = false;
	downIsPressed = false;
	leftIsPressed = false;
	rightIsPressed = false;
	//Text Positions
	_chooseEpisodeX = 0;
	_chooseEpisodeY = 0;
	_firstOptionY = 0;
	_secondOptionY = 0;
	_thirdOptionY = 0;
	_fourthOptionY = 0;
	_fifthOptionY = 0;

	//Make the music loop
	_music.setLoop(true);


	//Images
	_logo.setPosition(1920 / 2, 200);
	_logo.setOrigin(96, 20);
	_logo.setSize(Vector2f(193, 41));
	_logo.setScale(4, 4);
	_background.setPosition(0, 0);
	_background.setSize(Vector2f(1920, 1080));
	_textBG.setPosition(1920 / 2, 1080 / 2);
	_textBG.setSize(Vector2f(1431, 838));
	_textBG.setOrigin(1431 / 2, 838 / 2);
	_textBG.setFillColor(sf::Color(0, 0, 0, 200));
	_levelOverlay.setPosition(1920 / 2, 1080 / 2);
	_levelOverlay.setSize(Vector2f(1920, 1080));
	_levelOverlay.setOrigin(1920 / 2, 1080 / 2);
	//Shadows
	_Slogo.setPosition(1920 / 2 + 16, 200 + 16);
	_Slogo.setOrigin(96, 20);
	_Slogo.setSize(Vector2f(193, 41));
	_Slogo.setScale(4, 4);

	//Menu Options
	_firstOption.setString("OPTION 1");
	_firstOption.setFont(font);
	_firstOptionShadow.setString("OPTION 1");
	_firstOptionShadow.setFont(font);
	_firstOptionShadow.setFillColor(Color::Black);
	_secondOption.setString("OPTION 2");
	_secondOption.setFont(font);
	_secondOptionShadow.setString("OPTION 2");
	_secondOptionShadow.setFont(font);
	_secondOptionShadow.setFillColor(Color::Black);
	_thirdOption.setString("OPTION 3");
	_thirdOption.setFont(font);
	_thirdOptionShadow.setString("OPTION 3");
	_thirdOptionShadow.setFont(font);
	_thirdOptionShadow.setFillColor(Color::Black);
	_fourthOption.setString("OPTION 4");
	_fourthOption.setFont(font);
	_fourthOptionShadow.setString("OPTION 4");
	_fourthOptionShadow.setFont(font);
	_fourthOptionShadow.setFillColor(Color::Black);
	_fifthOption.setString("OPTION 5");
	_fifthOption.setFont(font);
	_fifthOptionShadow.setString("OPTION 5");
	_fifthOptionShadow.setFont(font);
	_fifthOptionShadow.setFillColor(Color::Black);
	//Episodes Selection
	_headerText.setString("CHOOSE XXX");
	_headerText.setFont(font);
	_headerTextShadow.setString("CHOOSE XXX");
	_headerTextShadow.setFont(font);
	_headerTextShadow.setFillColor(Color::Black);
	_episodePreview.setPosition(1250, 600);
	_episodePreview.setOrigin(859 / 2, 627 / 2);
	_episodePreview.setSize(Vector2f(803, 570));
	_episodePreview.setScale(0.9, 0.9);
	//Level Selection
	_previewMiddle.setPosition(1920 / 2, 550);
	_previewMiddle.setOrigin(803 / 2, 570 / 2);
	_previewMiddle.setSize(Vector2f(803, 570));
	_previewMiddle.setScale(0.9, 0.9);
	_previewLeft.setPosition(150, 570);
	_previewLeft.setOrigin(803 / 2, 627 / 2);
	_previewLeft.setSize(Vector2f(803, 570));
	_previewLeft.setScale(0.7, 0.7);
	_previewRight.setPosition(1770, 550);
	_previewRight.setOrigin(803 / 2, 570 / 2);
	_previewRight.setSize(Vector2f(803, 570));
	_previewRight.setScale(0.7, 0.7);
	_previewRightLocked.setPosition(1770, 550);
	_previewRightLocked.setOrigin(803 / 2, 570 / 2);
	_previewRightLocked.setSize(Vector2f(803, 570));
	_previewRightLocked.setScale(0.7, 0.7);
	_levelNumber.setString("LEVEL X");
	_levelNumber.setFont(font);
	_levelNumber.setPosition(740, 200);
	_levelNumber.setFillColor(Color::White);
	_levelNumberShadow.setString("LEVEL X");
	_levelNumberShadow.setFont(font);
	_levelNumberShadow.setPosition(740 + 8, 200 + 8);
	_levelNumberShadow.setFillColor(Color::Black);

	cout << "[Menu] Menu has been created " << endl;
}

bool Menu::LoadLogo()
{
	if (!_logoTexture.loadFromFile("ArkanoidUltra_Data/Sprites/Menu/Logo.png"))
	{
		return false;
	}
	_logo.setTexture(&_logoTexture);

	if (!_SlogoTexture.loadFromFile("ArkanoidUltra_Data/Sprites/Menu/LogoS.png"))
	{
		return false;
	}
	_Slogo.setTexture(&_SlogoTexture);
	return true;
}

bool Menu::LoadFont()
{
	if (!font.loadFromFile("ArkanoidUltra_Data/Font/nintendo-nes-font.ttf"))
	{
		return false;
	}
	return true;
}

bool Menu::LoadMusic()
{
	if (!_buffer.loadFromFile("ArkanoidUltra_Data/Musics/Menu.wav"))
		return false;
	_music.setBuffer(_buffer);
	return true;
}

bool Menu::LoadSounds()
{
	if (!_confirmBuffer.loadFromFile("ArkanoidUltra_Data/Sounds/MenuAccept.wav"))
		return false;
	_confirmSound.setBuffer(_confirmBuffer);
	if (!_changeBuffer.loadFromFile("ArkanoidUltra_Data/Sounds/MenuChange.wav"))
		return false;
	_changeSound.setBuffer(_changeBuffer);
	return true;
}

bool Menu::LoadBackground()
{
	if (!_textureBackground.loadFromFile("ArkanoidUltra_Data/Sprites/Level/MenuBG.png"))
		return false;
	_background.setTexture(&_textureBackground);

	if (!_textureLevelOverlay.loadFromFile("ArkanoidUltra_Data/Sprites/Menu/TerminalOverlay.png"))
		return false;
	_levelOverlay.setTexture(&_textureLevelOverlay, true);

	return true;
}

//Set the state to the parameter one, resets the option variable to 1 and change the maxOption depending on the menu state
void Menu::SetState(int state)
{
	_option = 1;
	_state = state;
	cout << "[Menu] Switching state to " << state << endl;
	UpdateMaxOptionNumber();
}

int Menu::GetState() const
{
	return _state;
}

//Changes the maxOption depending on the menustate
void Menu::UpdateMaxOptionNumber()
{
	switch (_state)
	{
	case TITLE:
		_maxOption = 2;
		break;
	case EPISODES:
		_maxOption = 5;
		break;
	case GAMEOVER:
		_maxOption = 2;
		break;
	case PAUSE:
		_maxOption = 2;
		break;
	}
	cout << "[Menu] Max Option is now "<< _maxOption << endl;
}

//Changes the text variable's string depending on the menu state
void Menu::UpdateText(int level)
{
	switch (_state)
	{
	case TITLE:
		_firstOption.setString("PLAY");
		_secondOption.setString("EXIT");
		_firstOptionShadow.setString("PLAY");
		_secondOptionShadow.setString("EXIT");
		_firstOptionY = 500;
		_secondOptionY = 600;
		break;
	case EPISODES:
		//Text
		_headerText.setString("CHOOSE AN EPISODE");
		_headerTextShadow.setString("CHOOSE AN EPISODE");
		_firstOption.setString("EPISODE 1");
		_secondOption.setString("EPISODE 2");
		_thirdOption.setString("EPISODE 3");
		_fourthOption.setString("EPISODE 4");
		_fifthOption.setString("HOW TO PLAY");
		_firstOptionShadow.setString("EPISODE 1");
		_secondOptionShadow.setString("EPISODE 2");
		_thirdOptionShadow.setString("EPISODE 3");
		_fourthOptionShadow.setString("EPISODE 4");
		_fifthOptionShadow.setString("HOW TO PLAY");
		//
		_firstOption.setPosition(500, 460);
		_firstOptionShadow.setPosition(500 + 8, 460 + 8);
		_secondOption.setPosition(500, 530);
		_secondOptionShadow.setPosition(500 + 8, 530 + 8);
		_thirdOption.setPosition(500, 600);
		_thirdOptionShadow.setPosition(500 + 8, 600 + 8);
		_fourthOption.setPosition(500, 670);
		_fourthOptionShadow.setPosition(500 + 8, 670 + 8);
		_fifthOption.setPosition(532, 760);
		_fifthOptionShadow.setPosition(532 + 8, 760 + 8);

		_chooseEpisodeX = 610;
		_chooseEpisodeY = 230;
		break;
	case LEVELS:
		_headerText.setString("CHOOSE A LEVEL");
		_headerTextShadow.setString("CHOOSE A LEVEL");
		_levelNumber.setString("LEVEL ");
		number = _levelNumber.getString();
		number.append(to_string(level));
		_levelNumber.setString(number);
		_levelNumberShadow.setString(number);
		_chooseEpisodeX = 1920 / 2;
		_chooseEpisodeY = 230;
		break;
	case GAMEOVER:
		_firstOption.setString("YES");
		_secondOption.setString("NO");
		_firstOptionShadow.setString("YES");
		_secondOptionShadow.setString("NO");
		_headerText.setString("CONTINUE?");
		_headerTextShadow.setString("CONTINUE?");

		_firstOption.setPosition(1920 / 2 - 100, 800);
		_firstOptionShadow.setPosition(1920 / 2 - 100 + 8, 800 + 8);
		_secondOption.setPosition(1920 / 2 + 100, 800);
		_secondOptionShadow.setPosition(1920 / 2 + 100 + 8, 800 + 8);
		_chooseEpisodeY = 700;
		break;
	case PAUSE:
		_firstOption.setString("RESUME");
		_secondOption.setString("QUIT");
		_firstOptionShadow.setString("RESUME");
		_secondOptionShadow.setString("QUIT");
		_headerText.setString("-PAUSE-");
		_headerTextShadow.setString("-PAUSE-");

		_firstOptionY = 550;
		_secondOptionY = 620;
		_chooseEpisodeY = 450;
		break;
	}

	//--Center Text Horizontally
	//Choose Episode
	textRect = _headerText.getLocalBounds();
	_headerText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	textRect = _headerTextShadow.getLocalBounds();
	_headerText.setPosition(sf::Vector2f(_chooseEpisodeX, _chooseEpisodeY));
	_headerTextShadow.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	_headerTextShadow.setPosition(sf::Vector2f(_chooseEpisodeX + 8, _chooseEpisodeY + 8));
	//Level Number
	textRect = _levelNumber.getLocalBounds();
	_levelNumber.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	textRect = _levelNumberShadow.getLocalBounds();
	_levelNumber.setPosition(sf::Vector2f(1920 / 2, 865));
	_levelNumberShadow.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	_levelNumberShadow.setPosition(sf::Vector2f(1920 / 2 + 8, 865 + 8));
	//Options
	//1
	textRect = _firstOption.getLocalBounds();
	_firstOption.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	textRect = _firstOptionShadow.getLocalBounds();
	_firstOptionShadow.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	//2
	textRect = _secondOption.getLocalBounds();
	_secondOption.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	textRect = _secondOptionShadow.getLocalBounds();
	_secondOptionShadow.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	//3
	textRect = _thirdOption.getLocalBounds();
	_thirdOption.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	textRect = _thirdOptionShadow.getLocalBounds();
	_thirdOptionShadow.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	//4
	textRect = _fourthOption.getLocalBounds();
	_fourthOption.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	textRect = _fourthOptionShadow.getLocalBounds();
	_fourthOptionShadow.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	//5
	textRect = _fifthOption.getLocalBounds();
	_fifthOption.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	textRect = _fifthOptionShadow.getLocalBounds();
	_fifthOptionShadow.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	if (_state == TITLE || _state == PAUSE)
	{
		_firstOption.setPosition(sf::Vector2f(1920 / 2, _firstOptionY));
		_firstOptionShadow.setPosition(sf::Vector2f(1920 / 2 + 8, _firstOptionY + 8));
		_secondOption.setPosition(sf::Vector2f(1920 / 2, _secondOptionY));
		_secondOptionShadow.setPosition(sf::Vector2f(1920 / 2 + 8, _secondOptionY + 8));
		_thirdOption.setPosition(sf::Vector2f(1920 / 2, _thirdOptionY));
		_thirdOptionShadow.setPosition(sf::Vector2f(1920 / 2 + 8, _thirdOptionY + 8));
		_fourthOption.setPosition(sf::Vector2f(1920 / 2, _fourthOptionY));
		_fourthOptionShadow.setPosition(sf::Vector2f(1920 / 2 + 8, _fourthOptionY + 8));
		_fifthOption.setPosition(sf::Vector2f(1920 / 2, _fourthOptionY));
		_fifthOptionShadow.setPosition(sf::Vector2f(1920 / 2 + 8, _fourthOptionY + 8));
	}
}

void Menu::Draw(sf::RenderWindow& window)
{
	if (!(_state == -1 || _state == GAMEOVER || _state == PAUSE))
		window.draw(_background);

	switch (_state)
	{
	case TITLE:
		window.draw(_textBG);
		window.draw(_Slogo);
		window.draw(_logo);
		window.draw(_firstOptionShadow);
		window.draw(_secondOptionShadow);
		window.draw(_firstOption);
		window.draw(_secondOption);
		break;
	case EPISODES:
		window.draw(_textBG);
		window.draw(_headerTextShadow);
		window.draw(_headerText);
		window.draw(_firstOptionShadow);
		window.draw(_secondOptionShadow);
		window.draw(_firstOption);
		window.draw(_secondOption);
		window.draw(_thirdOptionShadow);
		window.draw(_thirdOption);
		window.draw(_fourthOptionShadow);
		window.draw(_fourthOption);
		window.draw(_fifthOptionShadow);
		window.draw(_fifthOption);
		window.draw(_episodePreview);
		break;
	case LEVELS:
		window.draw(_textBG);
		window.draw(_headerTextShadow);
		window.draw(_headerText);
		window.draw(_previewLeft);
		window.draw(_previewMiddle);
		window.draw(_previewRight);
		window.draw(_previewRightLocked);
		window.draw(_levelNumberShadow);
		window.draw(_levelNumber);
		window.draw(_levelOverlay);
		break;
	case GAMEOVER:
		window.draw(_textBG);
		window.draw(_headerTextShadow);
		window.draw(_headerText);
		window.draw(_firstOptionShadow);
		window.draw(_secondOptionShadow);
		window.draw(_firstOption);
		window.draw(_secondOption);
		break;
	case PAUSE:
		window.draw(_textBG);
		window.draw(_headerTextShadow);
		window.draw(_headerText);
		window.draw(_firstOptionShadow);
		window.draw(_secondOptionShadow);
		window.draw(_firstOption);
		window.draw(_secondOption);
	}
}

int Menu::GetOption() const
{
	return _option;
}

//Changes the text background's size depending on the menu state
void Menu::UpdateTextBG()
{
	switch (_state)
	{
	case TITLE:
	{
		_textBG.setPosition(1920 / 2, 1080 / 2 + 20);
		_textBG.setSize(Vector2f(250, 250));
		_textBG.setOrigin(250 / 2, 250 / 2);
		break;
	}
	case EPISODES:
		_textBG.setPosition(1920 / 2, 1080 / 2);
		_textBG.setSize(Vector2f(1431, 838));
		_textBG.setOrigin(1431 / 2, 838 / 2);
		break;
	case LEVELS:
		_textBG.setPosition(1920 / 2, 1080 / 2);
		_textBG.setSize(Vector2f(1580, 878));
		_textBG.setOrigin(1580 / 2, 878 / 2);
		break;
	case GAMEOVER:
		_textBG.setSize(Vector2f(400, 200));
		_textBG.setOrigin(400 / 2, 200 / 2);
		_textBG.setPosition(1920 / 2, 750);
		break;
	case PAUSE:
		_textBG.setSize(Vector2f(400, 350));
		_textBG.setOrigin(400 / 2, 500 / 2);
		_textBG.setPosition(1920 / 2, 620);
		break;
	}
}

void Menu::Initialize()
{
	SetState(TITLE);
	HighlightOption();
	LoadMusic();
	LoadSounds();
	LoadFont();
	LoadLogo();
	LoadLevelPreview(_option);
	LoadEpisodePreview(_option);
	LoadBackground();
	_music.setVolume(13.f);
	_music.play();
}

//Checks if a key has been released so it can be pressed again
void Menu::IsKeyPressed(Event event)
{
	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::Space) {
			if (enterIsPressed == true) 
			{
				enterIsPressed = false;
				cout << "[Menu::Keybind] Enter key released" << endl;

			}
		}
		if (event.key.code == sf::Keyboard::Escape) {
			if (escapeIsPressed == true) 
			{
				escapeIsPressed = false;
				cout << "[Menu::Keybind] Escape key released" << endl;
			}
		}
		if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) {
			if (upIsPressed == true)
			{
				upIsPressed = false;
				cout << "[Menu::Keybind] Up or W key released" << endl;
			}

		}
		if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
			if (downIsPressed == true)
			{
				downIsPressed = false;
				cout << "[Menu::Keybind] Down or S key released" << endl;
			}
		}
		if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
			if (leftIsPressed == true)
			{
				leftIsPressed = false;
				cout << "[Menu::Keybind] Left or A key released" << endl;
			}

		}
		if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
			if (rightIsPressed == true)
			{
				rightIsPressed = false;
				cout << "[Menu::Keybind] Right or D key released" << endl;
			}
		}
	}
}

//Change the text variables' color depending on the option's value
void Menu::HighlightOption()
{
	switch (_option)
	{
	case 1:
		_firstOption.setFillColor(Color::White);
		cout << "[Menu::Text] Option 1 has been highlighted" << endl;
		_secondOption.setFillColor(sf::Color(67, 68, 66));
		_thirdOption.setFillColor(sf::Color(67, 68, 66));
		_fourthOption.setFillColor(sf::Color(67, 68, 66));
		_fifthOption.setFillColor(sf::Color(67, 68, 66));
		break;
	case 2:
		_secondOption.setFillColor(Color::White);
		cout << "[Menu::Text] Option 2 has been highlighted" << endl;
		if (_state == GAMEOVER || _state == PAUSE || _state == TITLE)
			_secondOption.setFillColor(Color::Red);
		_firstOption.setFillColor(sf::Color(67, 68, 66));
		_thirdOption.setFillColor(sf::Color(67, 68, 66));
		_fourthOption.setFillColor(sf::Color(67, 68, 66));
		_fifthOption.setFillColor(sf::Color(67, 68, 66));
		break;
	case 3:
		_thirdOption.setFillColor(Color::White);
		cout << "[Menu::Text] Option 3 has been highlighted" << endl;
		_firstOption.setFillColor(sf::Color(67, 68, 66));
		_secondOption.setFillColor(sf::Color(67, 68, 66));
		_fourthOption.setFillColor(sf::Color(67, 68, 66));
		_fifthOption.setFillColor(sf::Color(67, 68, 66));
		break;
	case 4:
		_fourthOption.setFillColor(Color::White);
		cout << "[Menu::Text] Option 4 has been highlighted" << endl;
		_firstOption.setFillColor(sf::Color(67, 68, 66));
		_secondOption.setFillColor(sf::Color(67, 68, 66));
		_thirdOption.setFillColor(sf::Color(67, 68, 66));
		_fifthOption.setFillColor(sf::Color(67, 68, 66));
		break;
	case 5:
		_fifthOption.setFillColor(Color::White);
		cout << "[Menu::Text] Option 5 has been highlighted" << endl;
		_firstOption.setFillColor(sf::Color(67, 68, 66));
		_secondOption.setFillColor(sf::Color(67, 68, 66));
		_thirdOption.setFillColor(sf::Color(67, 68, 66));
		_fourthOption.setFillColor(sf::Color(67, 68, 66));
		break;
	}
}

int Menu::ChangeOption()
{
	UpdateTextBG();
	UpdateText(_option);

	if (_state == LEVELS)
	{
		if (leftIsPressed == false)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				leftIsPressed = true;
				cout << "[Menu::Keybind] Left or A key has been pressed" << endl;
				if (_option != 1)
				{
					_changeSound.play();
					_option--;
				}
				LoadLevelPreview(_option);
			}
		}
		if (rightIsPressed == false)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				rightIsPressed = true;
				cout << "[Menu::Keybind] Right or D key has been pressed" << endl;
				if (_option != _knownLevels)
				{
					_changeSound.play();
					_option++;
				}
				LoadLevelPreview(_option);
			}
		}
	}
	else if (_state == GAMEOVER)
	{
		if (leftIsPressed == false)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				leftIsPressed = true;
				cout << "[Menu::Keybind] Left or A key has been pressed" << endl;
				if (_option != 1)
				{
					_changeSound.play();
					_option--;
					HighlightOption();
				}
				LoadLevelPreview(_option);
			}
		}
		if (rightIsPressed == false)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				rightIsPressed = true;
				cout << "[Menu::Keybind] Left or A key has been pressed" << endl;
				if (_option != _knownLevels)
				{
					_changeSound.play();
					_option++;
					HighlightOption();
				}
				LoadLevelPreview(_option);
			}
		}
	}
	else
	{
		if (upIsPressed == false)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				upIsPressed = true;
				cout << "[Menu::Keybind] Up or W key has been pressed" << endl;
				if (_option != _minOption)
				{
					_changeSound.play();
					_option--;
					HighlightOption();
					if (_state == EPISODES)
						LoadEpisodePreview(_option);
				}
			}
		}
		if (downIsPressed == false)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				downIsPressed = true;
				cout << "[Menu::Keybind] Down or S key has been pressed" << endl;
				if (_option != _maxOption)
				{
					_changeSound.play();
					_option++;
					HighlightOption();
					if (_state == EPISODES)
						LoadEpisodePreview(_option);
				}
			}
		}
	}
	if (enterIsPressed == false)
	{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (_option != 5)
				_confirmSound.play();
			enterIsPressed = true;
			HighlightOption();
			cout << "[Menu::Keybind] Enter or Space key has been pressed" << endl;
			if (_state == LEVELS)
				_music.stop();
			return ConfirmOption(_option);
		}
	}
	if (escapeIsPressed == false)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			_changeSound.play();
			_option = 1;
			HighlightOption();
			escapeIsPressed = true;
			cout << "[Menu::Keybind] Escape key has been pressed" << endl;
			switch (_state)
			{
			case EPISODES:
				SetState(TITLE);
				break;
			case LEVELS:
				SetState(EPISODES);
				break;
			case -1:
				SetState(PAUSE);
				break;
			}
			UpdateMaxOptionNumber();
		}
	}
	return 0;
}

int Menu::ConfirmOption(int option)
{
	return option;
}

bool Menu::LoadLevelPreview(int level)
{
	std::string middlePreviewPath = _levelPreviewPath;
	std::string leftPreviewPath = _levelPreviewPath;
	std::string rightPreviewPath = _levelPreviewPath;
	middlePreviewPath.append(to_string(level));
	leftPreviewPath.append(to_string(level - 1));
	rightPreviewPath.append(to_string(level + 1));
	middlePreviewPath.append(_imgFileExtension);
	leftPreviewPath.append(_imgFileExtension);
	rightPreviewPath.append(_imgFileExtension);

	//Left
	if (level == 1)
	{
		cout << "[Menu::Load] Loading left preview for no level" << endl;
		if (!_texturePreviewLeft.loadFromFile("ArkanoidUltra_Data/Previews/Levels/None.png"))
		{
			return false;
		}
		_previewLeft.setTexture(&_texturePreviewLeft, true);
	}
	else if (!_texturePreviewLeft.loadFromFile(leftPreviewPath))
	{
		cout << "[Menu::Load] Loading left preview for level " << level - 1 << endl;
		return false;
	}
	_previewLeft.setTexture(&_texturePreviewLeft, true);

	//Middle
	cout << "[Menu::Load] Loading middle preview for level " << level << endl;
	if (!_texturePreviewMiddle.loadFromFile(middlePreviewPath))
	{
		return false;
	}
	_previewMiddle.setTexture(&_texturePreviewMiddle, true);

	//Right
	if (level == _maxLevels)
	{
		cout << "[Menu::Load] Loading right preview for no level" << endl;
		if (!_texturePreviewRight.loadFromFile("ArkanoidUltra_Data/Previews/Levels/None.png"))
		{
			return false;
		}
		_previewRight.setTexture(&_texturePreviewRight, true);
	}
	else if (!_texturePreviewRight.loadFromFile(rightPreviewPath))
	{
		cout << "[Menu::Load] Loading right preview for level " << level + 1 << endl;
		return false;
	}
	_previewRight.setTexture(&_texturePreviewRight, true);
	cout << "[Menu::Load] Next level is unlocked (" << level + 1 << ")" << endl;
	if (!_texturePreviewRightLocked.loadFromFile("ArkanoidUltra_Data/Previews/Levels/None.png"))
	{
		return false;
	}
	_previewRightLocked.setTexture(&_texturePreviewRightLocked, true);

	if (level == _knownLevels)
	{
		cout << "[Menu::Load] Next level is locked (" << level + 1 << ")" << endl;
		if (!_texturePreviewRightLocked.loadFromFile("ArkanoidUltra_Data/Previews/Levels/Locked.png"))
		{
			return false;
		}
		_previewRightLocked.setTexture(&_texturePreviewRightLocked, true);
	}
	return true;
}

bool Menu::LoadEpisodePreview(int option)
{
	std::string previewPath = _episodePreviewPath;
	previewPath.append(to_string(option));
	previewPath.append(_imgFileExtension);
	_episodePreview.setScale(1, 1);
	cout << "[Menu::Load] Loading episode preview for Episode " << option << endl;
	if (!_textureEpisodePreview.loadFromFile(previewPath))
	{
		return false;
	}
	_episodePreview.setTexture(&_textureEpisodePreview);

	return true;
}