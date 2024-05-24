#include "Menu.h"

Menu::Menu()
{
	//Variables
	_state = TITLE;
	_option = 1;
	_level = 1;
	_knownLevels = 3;
	enterIsPressed = false;
	upIsPressed = false;
	downIsPressed = false;
	leftIsPressed = false;
	rightIsPressed = false;

	//Load Ressources
	loadFont();
	loadLogo();
	loadPreview(_level);

	//Images
	_logo.setPosition(1920 / 2, 200);
	_logo.setOrigin(96, 20);
	_logo.setSize(Vector2f(193, 41));
	_logo.setScale(4, 4);
	_background.setPosition(0, 0);
	_background.setSize(Vector2f(1920, 1080));
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
	//Episodes Selection
	_chooseEpisode.setString("CHOOSE EPISODE");
	_chooseEpisode.setFont(font);
	_chooseEpisode.setPosition(740, 200);
	_chooseEpisode.setFillColor(Color::White);
	_SchooseEpisode.setString("CHOOSE EPISODE");
	_SchooseEpisode.setFont(font);
	_SchooseEpisode.setPosition(740 + 8, 200 + 8);
	_SchooseEpisode.setFillColor(Color::Black);
	//Level Selection
	_previewMiddle.setPosition(1920 / 2, 700);
	_previewMiddle.setOrigin(859 / 2, 627 / 2);
	_previewMiddle.setSize(Vector2f(859, 627));
	_previewLeft.setPosition(20, 700);
	_previewLeft.setOrigin(859 / 2, 627 / 2);
	_previewLeft.setSize(Vector2f(859, 627));
	_previewLeft.setScale(0.7, 0.7);
	_previewRight.setPosition(1900, 700);
	_previewRight.setOrigin(859 / 2, 627 / 2);
	_previewRight.setSize(Vector2f(859, 627));
	_previewRight.setScale(0.7, 0.7);
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
}

bool Menu::loadFont()
{
	if (!font.loadFromFile("ArkanoidUltra_Data/Font/nintendo-nes-font.ttf"))
	{
		return false;
	}
}

bool Menu::SetMusic()
{
	if (!_buffer.loadFromFile("ArkanoidUltra_Data/Musics/Menu.wav"))
		return false;
	_music.setBuffer(_buffer);
}

bool Menu::SetBackground()
{
	if (!_textureBackground.loadFromFile("ArkanoidUltra_Data/Sprites/Level/MenuBG.png"))
		return false;
	_background.setTexture(&_textureBackground);

}

void Menu::SetState(int state)
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
	case EPISODES:
		_maxOption = 4;
	}
}

void Menu::updateText()
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
		_SfirstOption.setString("EPISODE 1");
		_SsecondOption.setString("EPISODE 2");
		_SthirdOption.setString("EPISODE 3");
		_SfourthOption.setString("EPISODE 4");
		_firstOptionY = 460;
		_secondOptionY = 530;
		_thirdOptionY = 600;
		_fourthOptionY = 670;
		break;
	case LEVELS:
		_chooseEpisode.setString("CHOOSE A LEVEL");
		_SchooseEpisode.setString("CHOOSE A LEVEL");
		break;
	}

	//Center horizontally
	textRect = _chooseEpisode.getLocalBounds();
	_chooseEpisode.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	_chooseEpisode.setPosition(sf::Vector2f(1920 / 2, 200));
	textRect = _SchooseEpisode.getLocalBounds();
	_SchooseEpisode.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	_SchooseEpisode.setPosition(sf::Vector2f(1920 / 2 + 8, 200 + 8));
	textRect = _firstOption.getLocalBounds();
	_firstOption.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	_firstOption.setPosition(sf::Vector2f(1920 / 2, _firstOptionY));
	textRect = _secondOption.getLocalBounds();
	_secondOption.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	_secondOption.setPosition(sf::Vector2f(1920 / 2, _secondOptionY));
	textRect = _thirdOption.getLocalBounds();
	_thirdOption.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	_thirdOption.setPosition(sf::Vector2f(1920 / 2, _thirdOptionY));
	textRect = _fourthOption.getLocalBounds();
	_fourthOption.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	_fourthOption.setPosition(sf::Vector2f(1920 / 2, _fourthOptionY));
	textRect = _SfirstOption.getLocalBounds();
	_SfirstOption.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	_SfirstOption.setPosition(sf::Vector2f(1920 / 2 + 8, _firstOptionY + 8));
	textRect = _SsecondOption.getLocalBounds();
	_SsecondOption.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	_SsecondOption.setPosition(sf::Vector2f(1920 / 2 + 8, _secondOptionY + 8));
	textRect = _SthirdOption.getLocalBounds();
	_SthirdOption.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	_SthirdOption.setPosition(sf::Vector2f(1920 / 2 + 8, _thirdOptionY + 8));
	textRect = _SfourthOption.getLocalBounds();
	_SfourthOption.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	_SfourthOption.setPosition(sf::Vector2f(1920 / 2 + 8, _fourthOptionY + 8));

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
		break;
	case LEVELS:
		window.draw(_SchooseEpisode);
		window.draw(_chooseEpisode);
		window.draw(_previewLeft);
		window.draw(_previewMiddle);
		window.draw(_previewRight);
		break;
	}

}

void Menu::Initialize()
{
	SetMusic();
	SetBackground();
	_music.setVolume(13.f);
	_music.play();
}

void Menu::IsKeyPressed(Event event)
{
	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::Enter) {
			enterIsPressed = false;
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
		break;
	case 2:
		_secondOption.setFillColor(Color::White);

		_firstOption.setFillColor(sf::Color(67, 68, 66));
		_thirdOption.setFillColor(sf::Color(67, 68, 66));
		_fourthOption.setFillColor(sf::Color(67, 68, 66));
		break;
	case 3:
		_thirdOption.setFillColor(Color::White);

		_firstOption.setFillColor(sf::Color(67, 68, 66));
		_secondOption.setFillColor(sf::Color(67, 68, 66));
		_fourthOption.setFillColor(sf::Color(67, 68, 66));
		break;
	case 4:
		_fourthOption.setFillColor(Color::White);

		_firstOption.setFillColor(sf::Color(67, 68, 66));
		_secondOption.setFillColor(sf::Color(67, 68, 66));
		_thirdOption.setFillColor(sf::Color(67, 68, 66));

		break;
	}


}

int Menu::ChangeOption()
{
	if (upIsPressed == false)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{

			upIsPressed = true;
			if (_option != _minOption)
			{
				_option--;
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
				_option++;
			}
		}
	}
	if (leftIsPressed == false)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			leftIsPressed = true;
			if (_level != 1)
				_level--;
			loadPreview(_level);
		}
	}
	if (rightIsPressed == false)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			rightIsPressed = true;
			if (_level != _knownLevels)
				_level++;
			loadPreview(_level);
		}
	}
	if (enterIsPressed == false)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			enterIsPressed = true;
			return ConfirmOption(_option);
		}
	}
	return 0;
}

int Menu::ConfirmOption(int option)
{
	return option;
}

bool Menu::loadPreview(int level)
{

	std::string middlePreviewPath = _previewPath;
	std::string leftPreviewPath = _previewPath;
	std::string rightPreviewPath = _previewPath;
	middlePreviewPath.append(to_string(level));
	leftPreviewPath.append(to_string(level - 1));
	rightPreviewPath.append(to_string(level + 1));
	middlePreviewPath.append(_imgFileExtension);
	leftPreviewPath.append(_imgFileExtension);
	rightPreviewPath.append(_imgFileExtension);

	//Left
	if (level == 1)
	{
		if (!_texturePreviewLeft.loadFromFile("ArkanoidUltra_Data/Level/Previews/None.png"))
		{
			return false;
		}
		_previewLeft.setTexture(&_texturePreviewLeft);
	}
	else if (!_texturePreviewLeft.loadFromFile(leftPreviewPath))
	{
		return false;
	}
	_previewLeft.setTexture(&_texturePreviewLeft);

	//Middle
	if (!_texturePreviewMiddle.loadFromFile(middlePreviewPath))
	{
		return false;
	}
	_previewMiddle.setTexture(&_texturePreviewMiddle);

	//Right
	if (level == _knownLevels)
	{
		if (!_texturePreviewRight.loadFromFile("ArkanoidUltra_Data/Level/Previews/None.png"))
		{
			return false;
		}
		_previewRight.setTexture(&_texturePreviewRight);
	}
	else if (!_texturePreviewRight.loadFromFile(rightPreviewPath))
	{
		return false;
	}
	_previewRight.setTexture(&_texturePreviewRight);
}
