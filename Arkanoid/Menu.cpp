#include "Menu.h"

Menu::Menu()
{
	//Variables
	_state = TITLE;
	_option = 1;
	_knownLevels = 2;
	escapeIsPressed = false;
	enterIsPressed = false;
	upIsPressed = false;
	downIsPressed = false;
	leftIsPressed = false;
	rightIsPressed = false;
	_chooseEpisodeX = 0;
	_firstOptionY = 0;
	_secondOptionY = 0;
	_thirdOptionY = 0;
	_fourthOptionY = 0;
	_fifthOptionY = 0;

	//Load Ressources


	//Images
	_logo.setPosition(1920 / 2, 200);
	_logo.setOrigin(96, 20);
	_logo.setSize(Vector2f(193, 41));
	_logo.setScale(4, 4);
	_background.setPosition(0, 0);
	_background.setSize(Vector2f(1920, 1080));
	_TerminalBG.setPosition(1920/2, 1080/2);
	_TerminalBG.setSize(Vector2f(1431, 838));
	_TerminalBG.setOrigin(1431 / 2, 838 / 2);
	_TerminalOverlay.setPosition(1920 / 2, 1080 / 2);
	_TerminalOverlay.setSize(Vector2f(1920, 1080));
	_TerminalOverlay.setOrigin(1920 / 2, 1080 / 2);
	//Shadows
	_Slogo.setPosition(1920 / 2 + 16, 200 + 16);
	_Slogo.setOrigin(96, 20);
	_Slogo.setSize(Vector2f(193, 41));
	_Slogo.setScale(4, 4);

	//--Menu Options
	_firstOption.setString("OPTION 1");
	_firstOption.setFont(font);
	_firstOption.setPosition(915, 500);
	_firstOption.setFillColor(Color::White);
	_SfirstOption.setString("OPTION 1");
	_SfirstOption.setFont(font);
	_SfirstOption.setPosition(915 + 8, 500 + 8);
	_SfirstOption.setFillColor(Color::Black);
	_secondOption.setString("OPTION 2");
	_secondOption.setFont(font);
	_secondOption.setPosition(915, 600);
	_secondOption.setFillColor(Color::White);
	_SsecondOption.setString("OPTION 2");
	_SsecondOption.setFont(font);
	_SsecondOption.setPosition(915 + 8, 600 + 8);
	_SsecondOption.setFillColor(Color::Black);

	_thirdOption.setString("OPTION 3");
	_thirdOption.setFont(font);
	_thirdOption.setPosition(915, 700);
	_thirdOption.setFillColor(Color::White);
	_SthirdOption.setString("OPTION 3");
	_SthirdOption.setFont(font);
	_SthirdOption.setPosition(915 + 8, 700 + 8);
	_SthirdOption.setFillColor(Color::Black);
	_fourthOption.setString("OPTION 4");
	_fourthOption.setFont(font);
	_fourthOption.setPosition(915, 800);
	_fourthOption.setFillColor(Color::White);
	_SfourthOption.setString("OPTION 4");
	_SfourthOption.setFont(font);
	_SfourthOption.setPosition(915 + 8, 800 + 8);
	_SfourthOption.setFillColor(Color::Black);

	_fifthOption.setString("OPTION 5");
	_fifthOption.setFont(font);
	_fifthOption.setPosition(915, 900);
	_fifthOption.setFillColor(Color::White);
	_SfifthOption.setString("OPTION 5");
	_SfifthOption.setFont(font);
	_SfifthOption.setPosition(915 + 8, 900 + 8);
	_SfifthOption.setFillColor(Color::Black);
	//Episodes Selection
	_chooseEpisode.setString("CHOOSE EPISODE");
	_chooseEpisode.setFont(font);
	_chooseEpisode.setPosition(740, 200);
	_chooseEpisode.setFillColor(Color::White);
	_SchooseEpisode.setString("CHOOSE EPISODE");
	_SchooseEpisode.setFont(font);
	_SchooseEpisode.setPosition(740 + 8, 200 + 8);
	_SchooseEpisode.setFillColor(Color::Black);

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

	_levelNumber.setString("LEVEL ");
	_levelNumber.setFont(font);
	_levelNumber.setPosition(740, 200);
	_levelNumber.setFillColor(Color::White);
	_SlevelNumber.setString("LEVEL ");
	_SlevelNumber.setFont(font);
	_SlevelNumber.setPosition(740 + 8, 200 + 8);
	_SlevelNumber.setFillColor(Color::Black);
}

bool Menu::loadLogo()
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

bool Menu::loadFont()
{
	if (!font.loadFromFile("ArkanoidUltra_Data/Font/nintendo-nes-font.ttf"))
	{
		return false;
	}
	return true;
}

bool Menu::SetMusic()
{
	if (!_buffer.loadFromFile("ArkanoidUltra_Data/Musics/Menu.wav"))
		return false;
	_music.setBuffer(_buffer);
	return true;
}

bool Menu::SetSounds()
{
	if (!_confirmBuffer.loadFromFile("ArkanoidUltra_Data/Sounds/MenuAccept.wav"))
		return false;
	_confirmSound.setBuffer(_confirmBuffer);
	if (!_changeBuffer.loadFromFile("ArkanoidUltra_Data/Sounds/MenuChange.wav"))
		return false;
	_changeSound.setBuffer(_changeBuffer);
	return true;
}

bool Menu::SetBackground()
{
	if (!_textureBackground.loadFromFile("ArkanoidUltra_Data/Sprites/Level/MenuBG.png"))
		return false;
	_background.setTexture(&_textureBackground);

	if (_state == EPISODES)
	{
		if (!_textureTerminalBG.loadFromFile("ArkanoidUltra_Data/Sprites/Menu/TerminalBG.png"))
			return false;
		_TerminalBG.setTexture(&_textureTerminalBG, true);
	}
	else if (_state == LEVELS)
	{
		if (!_textureTerminalBG.loadFromFile("ArkanoidUltra_Data/Sprites/Menu/TerminalBGLevels.png"))
			return false;
		_TerminalBG.setTexture(&_textureTerminalBG, true);

		if (!_textureTerminalOverlay.loadFromFile("ArkanoidUltra_Data/Sprites/Menu/TerminalOverlay.png"))
			return false;
		_TerminalOverlay.setTexture(&_textureTerminalOverlay, true);
	}
	return true;
}

void Menu::SetState(int state)
{
	_option = 1;
	_state = state;
	updateMaxOptionNumber();
	updateTerminalBG();
}

int Menu::GetState()
{
	return _state;
}

void Menu::updateMaxOptionNumber()
{
	switch (_state)
	{
	case TITLE:
		_maxOption = 2;
		break;
	case EPISODES:
		_maxOption = 5;
		break;
	case INSTRUCTIONS:
		_maxOption = 1;
		break;
	}
}

void Menu::updateText(int level)
{
	switch (_state)
	{
	case TITLE:
		_firstOption.setString("PLAY");
		_secondOption.setString("EXIT");
		_SfirstOption.setString("PLAY");
		_SsecondOption.setString("EXIT");
		_firstOptionY = 460;
		_secondOptionY = 560;
		break;
	case EPISODES:
		//Text
		_chooseEpisode.setString("CHOOSE AN EPISODE");
		_SchooseEpisode.setString("CHOOSE AN EPISODE");
		_firstOption.setString("EPISODE 1");
		_secondOption.setString("EPISODE 2");
		_thirdOption.setString("EPISODE 3");
		_fourthOption.setString("EPISODE 4");
		_fifthOption.setString("HOW TO PLAY");
		_SfirstOption.setString("EPISODE 1");
		_SsecondOption.setString("EPISODE 2");
		_SthirdOption.setString("EPISODE 3");
		_SfourthOption.setString("EPISODE 4");
		_SfifthOption.setString("HOW TO PLAY");
		//
		_firstOption.setPosition(500, 460);
		_SfirstOption.setPosition(500 + 8, 460 + 8);
		_secondOption.setPosition(500, 530);
		_SsecondOption.setPosition(500 + 8, 530 + 8);
		_thirdOption.setPosition(500, 600);
		_SthirdOption.setPosition(500 + 8, 600 + 8);
		_fourthOption.setPosition(500, 670);
		_SfourthOption.setPosition(500 + 8, 670 + 8);
		_fifthOption.setPosition(532, 760);
		_SfifthOption.setPosition(532 + 8, 760 + 8);

		_chooseEpisodeX = 610;
		break;
	case LEVELS:
		_chooseEpisode.setString("CHOOSE A LEVEL");
		_SchooseEpisode.setString("CHOOSE A LEVEL");
		_chooseEpisodeX = 1920 / 2;
		_levelNumber.setString("LEVEL ");
		number = _levelNumber.getString();
		number.append(to_string(level));
		_levelNumber.setString(number);
		_SlevelNumber.setString(number);
		break;
	}

	//--Center Text Horizontally
	//Choose Episode
	textRect = _chooseEpisode.getLocalBounds();
	_chooseEpisode.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	textRect = _SchooseEpisode.getLocalBounds();
	_chooseEpisode.setPosition(sf::Vector2f(_chooseEpisodeX, 230));
	_SchooseEpisode.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	_SchooseEpisode.setPosition(sf::Vector2f(_chooseEpisodeX + 8, 230 + 8));
	//Level Number
	textRect = _levelNumber.getLocalBounds();
	_levelNumber.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	textRect = _SlevelNumber.getLocalBounds();
	_levelNumber.setPosition(sf::Vector2f(1920 / 2, 865));
	_SlevelNumber.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	_SlevelNumber.setPosition(sf::Vector2f(1920/2 + 8, 865 + 8));
	//Options
	//1
	textRect = _firstOption.getLocalBounds();
	_firstOption.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	textRect = _SfirstOption.getLocalBounds();
	_SfirstOption.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	//2
	textRect = _secondOption.getLocalBounds();
	_secondOption.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	textRect = _SsecondOption.getLocalBounds();
	_SsecondOption.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	//3
	textRect = _thirdOption.getLocalBounds();
	_thirdOption.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	textRect = _SthirdOption.getLocalBounds();
	_SthirdOption.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	//4
	textRect = _fourthOption.getLocalBounds();
	_fourthOption.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	textRect = _SfourthOption.getLocalBounds();
	_SfourthOption.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	//5
	textRect = _fifthOption.getLocalBounds();
	_fifthOption.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	textRect = _SfifthOption.getLocalBounds();
	_SfifthOption.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	if (_state != EPISODES)
	{
		_firstOption.setPosition(sf::Vector2f(1920 / 2, _firstOptionY));
		_SfirstOption.setPosition(sf::Vector2f(1920 / 2 + 8, _firstOptionY + 8));
		_secondOption.setPosition(sf::Vector2f(1920 / 2, _secondOptionY));
		_SsecondOption.setPosition(sf::Vector2f(1920 / 2 + 8, _secondOptionY + 8));
		_thirdOption.setPosition(sf::Vector2f(1920 / 2, _thirdOptionY));
		_SthirdOption.setPosition(sf::Vector2f(1920 / 2 + 8, _thirdOptionY + 8));
		_fourthOption.setPosition(sf::Vector2f(1920 / 2, _fourthOptionY));
		_SfourthOption.setPosition(sf::Vector2f(1920 / 2 + 8, _fourthOptionY + 8));
		_fifthOption.setPosition(sf::Vector2f(1920 / 2, _fourthOptionY));
		_SfifthOption.setPosition(sf::Vector2f(1920 / 2 + 8, _fourthOptionY + 8));
	}
}

void Menu::Draw(sf::RenderWindow& window)
{
	window.draw(_background);

	switch (_state)
	{
	case TITLE:
		window.draw(_Slogo);
		window.draw(_logo);
		window.draw(_SfirstOption);
		window.draw(_SsecondOption);
		window.draw(_firstOption);
		window.draw(_secondOption);
		break;
	case EPISODES:
		window.draw(_TerminalBG);
		window.draw(_SchooseEpisode);
		window.draw(_chooseEpisode);
		window.draw(_SfirstOption);
		window.draw(_SsecondOption);
		window.draw(_firstOption);
		window.draw(_secondOption);
		window.draw(_SthirdOption);
		window.draw(_thirdOption);
		window.draw(_SfourthOption);
		window.draw(_fourthOption);
		window.draw(_SfifthOption);
		window.draw(_fifthOption);
		window.draw(_episodePreview);
		break;
	case LEVELS:
		window.draw(_TerminalBG);
		window.draw(_SchooseEpisode);
		window.draw(_chooseEpisode);
		window.draw(_previewLeft);
		window.draw(_previewMiddle);
		window.draw(_previewRight);
		window.draw(_SlevelNumber);
		window.draw(_levelNumber);
		window.draw(_TerminalOverlay);
		break;
	}
}

int Menu::GetOption()
{
	return _option;
}

void Menu::updateTerminalBG()
{
	switch (_state)
	{
	case EPISODES:
		_TerminalBG.setPosition(1920 / 2, 1080 / 2);
		_TerminalBG.setSize(Vector2f(1431, 838));
		_TerminalBG.setOrigin(1431 / 2, 838 / 2);
		break;
	case LEVELS:
		_TerminalBG.setPosition(1920 / 2, 1080 / 2);
		_TerminalBG.setSize(Vector2f(1580, 878));
		_TerminalBG.setOrigin(1580 / 2, 878 / 2);
		break;
	}
	SetBackground();
}

void Menu::Initialize()
{
	SetState(TITLE);
	SetMusic();
	SetSounds();
	loadFont();
	loadLogo();
	loadLevelPreview(_option);
	loadEpisodePreview(_option);
	SetBackground();
	_music.setVolume(13.f);
	_music.play();
}

void Menu::IsKeyPressed(Event event)
{
	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::Space) {
			enterIsPressed = false;
		}
		if (event.key.code == sf::Keyboard::Escape) {
			escapeIsPressed = false;
		}
		if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) {
			upIsPressed = false;
		}
		if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
			downIsPressed = false;
		}
		if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
			leftIsPressed = false;
		}
		if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
			rightIsPressed = false;
		}
	}
}

void Menu::HighlightOption(sf::RenderWindow& window)
{

	switch (_option)
	{
	case 1:
		_firstOption.setFillColor(Color::White);

		_secondOption.setFillColor(sf::Color(67, 68, 66));
		_thirdOption.setFillColor(sf::Color(67, 68, 66));
		_fourthOption.setFillColor(sf::Color(67, 68, 66));
		_fifthOption.setFillColor(sf::Color(67, 68, 66));
		break;
	case 2:
		_secondOption.setFillColor(Color::White);

		_firstOption.setFillColor(sf::Color(67, 68, 66));
		_thirdOption.setFillColor(sf::Color(67, 68, 66));
		_fourthOption.setFillColor(sf::Color(67, 68, 66));
		_fifthOption.setFillColor(sf::Color(67, 68, 66));
		break;
	case 3:
		_thirdOption.setFillColor(Color::White);

		_firstOption.setFillColor(sf::Color(67, 68, 66));
		_secondOption.setFillColor(sf::Color(67, 68, 66));
		_fourthOption.setFillColor(sf::Color(67, 68, 66));
		_fifthOption.setFillColor(sf::Color(67, 68, 66));
		break;
	case 4:
		_fourthOption.setFillColor(Color::White);

		_firstOption.setFillColor(sf::Color(67, 68, 66));
		_secondOption.setFillColor(sf::Color(67, 68, 66));
		_thirdOption.setFillColor(sf::Color(67, 68, 66));
		_fifthOption.setFillColor(sf::Color(67, 68, 66));
		break;
	case 5:
		_fifthOption.setFillColor(Color::White);

		_firstOption.setFillColor(sf::Color(67, 68, 66));
		_secondOption.setFillColor(sf::Color(67, 68, 66));
		_thirdOption.setFillColor(sf::Color(67, 68, 66));
		_fourthOption.setFillColor(sf::Color(67, 68, 66));
		break;
	}
}

int Menu::ChangeOption()
{
	if (_state == LEVELS)
	{
		if (leftIsPressed == false)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				leftIsPressed = true;
				if (_option != 1)
				{
					_changeSound.play();
					_option--;
				}
				loadLevelPreview(_option);
			}
		}
		if (rightIsPressed == false)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				rightIsPressed = true;
				if (_option != _knownLevels)
				{
					_changeSound.play();
					_option++;
				}
				loadLevelPreview(_option);
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
				if (_option != _minOption)
				{
					_changeSound.play();
					_option--;
					if (_state == EPISODES)
						loadEpisodePreview(_option);
				}
			}
		}
		if (downIsPressed == false)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				downIsPressed = true;
				if (_option != _maxOption)
				{
					_changeSound.play();
					_option++;
					if (_state == EPISODES)
						loadEpisodePreview(_option);
				}
			}
		}
	}
	if (enterIsPressed == false)
	{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			_confirmSound.play();
			enterIsPressed = true;
			if(_state == LEVELS)
				_music.stop();
			return ConfirmOption(_option);
		}
	}
	if (escapeIsPressed == false)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			_option = 1;
			escapeIsPressed = true;
			switch (_state)
			{
			case EPISODES:
				SetState(TITLE);
				break;
			case LEVELS:
				SetState(EPISODES);
				break;
			}
			updateMaxOptionNumber();
		}
	}
	return 0;
}

int Menu::ConfirmOption(int option)
{
	return option;
}

bool Menu::loadLevelPreview(int level)
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
		if (!_texturePreviewLeft.loadFromFile("ArkanoidUltra_Data/Previews/Levels/None.png"))
		{
			return false;
		}
		_previewLeft.setTexture(&_texturePreviewLeft, true);
	}
	else if (!_texturePreviewLeft.loadFromFile(leftPreviewPath))
	{
		return false;
	}
	_previewLeft.setTexture(&_texturePreviewLeft, true);

	//Middle
	if (!_texturePreviewMiddle.loadFromFile(middlePreviewPath))
	{
		return false;
	}
	_previewMiddle.setTexture(&_texturePreviewMiddle, true);

	//Right
	if (level == _maxLevels)
	{
		if (!_texturePreviewRight.loadFromFile("ArkanoidUltra_Data/Previews/Levels/None.png"))
		{
			return false;
		}
		_previewRight.setTexture(&_texturePreviewRight, true);
	}
	else if (!_texturePreviewRight.loadFromFile(rightPreviewPath))
	{
		return false;
	}
	_previewRight.setTexture(&_texturePreviewRight, true);
	return true;
}

bool Menu::loadEpisodePreview(int option)
{
	std::string previewPath = _episodePreviewPath;
	previewPath.append(to_string(option));
	previewPath.append(_imgFileExtension);

	if (option == 5)
	{
		_episodePreview.setScale(0, 0);
	}
	else
	{
		_episodePreview.setScale(1, 1);
		if (!_textureEpisodePreview.loadFromFile(previewPath))
		{
			return false;
		}
		_episodePreview.setTexture(&_textureEpisodePreview);
	}

	return true;
}