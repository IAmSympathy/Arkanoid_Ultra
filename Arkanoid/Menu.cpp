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

	//--Menu Options
	_firstOption.setString("OPTION 1");
	_firstOption.setFont(font);
	_SfirstOption.setString("OPTION 1");
	_SfirstOption.setFont(font);
	_SfirstOption.setFillColor(Color::Black);
	_secondOption.setString("OPTION 2");
	_secondOption.setFont(font);
	_SsecondOption.setString("OPTION 2");
	_SsecondOption.setFont(font);
	_SsecondOption.setFillColor(Color::Black);

	_thirdOption.setString("OPTION 3");
	_thirdOption.setFont(font);
	_SthirdOption.setString("OPTION 3");
	_SthirdOption.setFont(font);
	_SthirdOption.setFillColor(Color::Black);
	_fourthOption.setString("OPTION 4");
	_fourthOption.setFont(font);
	_SfourthOption.setString("OPTION 4");
	_SfourthOption.setFont(font);
	_SfourthOption.setFillColor(Color::Black);

	_fifthOption.setString("OPTION 5");
	_fifthOption.setFont(font);
	_SfifthOption.setString("OPTION 5");
	_SfifthOption.setFont(font);
	_SfifthOption.setFillColor(Color::Black);
	//Episodes Selection
	_chooseEpisode.setString("CHOOSE XXX");
	_chooseEpisode.setFont(font);
	_SchooseEpisode.setString("CHOOSE XXX");
	_SchooseEpisode.setFont(font);
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

	_levelNumber.setString("LEVEL X");
	_levelNumber.setFont(font);
	_levelNumber.setPosition(740, 200);
	_levelNumber.setFillColor(Color::White);
	_SlevelNumber.setString("LEVEL X");
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

	if (!_textureLevelOverlay.loadFromFile("ArkanoidUltra_Data/Sprites/Menu/TerminalOverlay.png"))
		return false;
	_levelOverlay.setTexture(&_textureLevelOverlay, true);

	return true;
}

void Menu::Reset(int state)
{
	_option = 1;
	_state = state;
	updateMaxOptionNumber();
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
	case GAMEOVER:
		_maxOption = 2;
		break;
	case PAUSE:
		_maxOption = 2;
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
		_firstOptionY = 500;
		_secondOptionY = 600;
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
		_chooseEpisodeY = 230;
		break;
	case LEVELS:
		_chooseEpisode.setString("CHOOSE A LEVEL");
		_SchooseEpisode.setString("CHOOSE A LEVEL");
		_levelNumber.setString("LEVEL ");
		number = _levelNumber.getString();
		number.append(to_string(level));
		_levelNumber.setString(number);
		_SlevelNumber.setString(number);
		_chooseEpisodeX = 1920 / 2;
		_chooseEpisodeY = 230;
		break;
	case GAMEOVER:
		_firstOption.setString("YES");
		_secondOption.setString("NO");
		_SfirstOption.setString("YES");
		_SsecondOption.setString("NO");
		_chooseEpisode.setString("CONTINUE?");
		_SchooseEpisode.setString("CONTINUE?");

		_firstOption.setPosition(1920 / 2 - 100, 800);
		_SfirstOption.setPosition(1920 / 2 - 100 + 8, 800 + 8);
		_secondOption.setPosition(1920 / 2 + 100, 800);
		_SsecondOption.setPosition(1920 / 2 + 100 + 8, 800 + 8);
		_chooseEpisodeY = 700;
		break;
	case PAUSE:
		_firstOption.setString("RESUME");
		_secondOption.setString("QUIT");
		_SfirstOption.setString("RESUME");
		_SsecondOption.setString("QUIT");
		_chooseEpisode.setString("-PAUSE-");
		_SchooseEpisode.setString("-PAUSE-");

		_firstOptionY = 550;
		_secondOptionY = 620;
		_chooseEpisodeY = 450;
		break;
	}

	//--Center Text Horizontally
	//Choose Episode
	textRect = _chooseEpisode.getLocalBounds();
	_chooseEpisode.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	textRect = _SchooseEpisode.getLocalBounds();
	_chooseEpisode.setPosition(sf::Vector2f(_chooseEpisodeX, _chooseEpisodeY));
	_SchooseEpisode.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	_SchooseEpisode.setPosition(sf::Vector2f(_chooseEpisodeX + 8, _chooseEpisodeY + 8));
	//Level Number
	textRect = _levelNumber.getLocalBounds();
	_levelNumber.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	textRect = _SlevelNumber.getLocalBounds();
	_levelNumber.setPosition(sf::Vector2f(1920 / 2, 865));
	_SlevelNumber.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	_SlevelNumber.setPosition(sf::Vector2f(1920 / 2 + 8, 865 + 8));
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
	if (_state == TITLE || _state == PAUSE)
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
	if (!(_state == -1 || _state == GAMEOVER || _state == PAUSE))
		window.draw(_background);

	switch (_state)
	{
	case TITLE:
		window.draw(_textBG);
		window.draw(_Slogo);
		window.draw(_logo);
		window.draw(_SfirstOption);
		window.draw(_SsecondOption);
		window.draw(_firstOption);
		window.draw(_secondOption);
		break;
	case EPISODES:
		window.draw(_textBG);
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
		window.draw(_textBG);
		window.draw(_SchooseEpisode);
		window.draw(_chooseEpisode);
		window.draw(_previewLeft);
		window.draw(_previewMiddle);
		window.draw(_previewRight);
		window.draw(_SlevelNumber);
		window.draw(_levelNumber);
		window.draw(_levelOverlay);
		break;
	case GAMEOVER:
		window.draw(_textBG);
		window.draw(_SchooseEpisode);
		window.draw(_chooseEpisode);
		window.draw(_SfirstOption);
		window.draw(_SsecondOption);
		window.draw(_firstOption);
		window.draw(_secondOption);
		break;
	case PAUSE:
		window.draw(_textBG);
		window.draw(_SchooseEpisode);
		window.draw(_chooseEpisode);
		window.draw(_SfirstOption);
		window.draw(_SsecondOption);
		window.draw(_firstOption);
		window.draw(_secondOption);
	}
}

int Menu::GetOption()
{
	return _option;
}

void Menu::updateTextBG()
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
	Reset(TITLE);
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
		if (_state == GAMEOVER || _state == PAUSE || _state == TITLE)
			_secondOption.setFillColor(Color::Red);
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
	else if (_state == GAMEOVER)
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
			if (_option != 5)
				_confirmSound.play();
			enterIsPressed = true;
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
			escapeIsPressed = true;
			switch (_state)
			{
			case EPISODES:
				Reset(TITLE);
				break;
			case LEVELS:
				Reset(EPISODES);
				break;
			case -1:
				Reset(PAUSE);
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