#include "Interface.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace::std;
using namespace::sf;

Interface::Interface()
{
	_scoreText.setString("SCORE");
	_score.setString("");
	_highscoreText.setString("HIGHSCORE");
	_highscore.setString("");
	_livesText.setString("LIVES");
	_lives.setString("");
	_level.setString("");
	_levelText.setString("ROUND");
	//Shadow
	_SscoreText.setString("SCORE");
	_Sscore.setString("");
	_ShighscoreText.setString("HIGHSCORE");
	_Shighscore.setString("");
	_SlivesText.setString("LIVES");
	_Slives.setString("");
	_Slevel.setString("");
	_SlevelText.setString("ROUND");
	_option = 1;

	loadFont();
	loadLiveIcon();
	loadLogo();

	//Images
	_logo.setPosition(1920 / 2, 200);
	_logo.setOrigin(96, 20);
	_logo.setSize(Vector2f(193, 41));
	_logo.setScale(4, 4);
	_background.setPosition(0, 0);		// On définit sa position
	_background.setSize(Vector2f(1920, 1080));	// On définit ses dimensions


	//Text Options
	_optionPlay.setString("PLAY");
	_optionPlay.setFont(font);
	_optionPlay.setPosition(915, 500);
	_optionPlay.setFillColor(Color::Red);
	_SoptionPlay.setString("PLAY");
	_SoptionPlay.setFont(font);
	_SoptionPlay.setPosition(915 + 8, 500 + 8);
	_SoptionPlay.setFillColor(Color::Black);

	_optionExit.setString("EXIT");
	_optionExit.setFont(font);
	_optionExit.setPosition(915 , 600);
	_optionExit.setFillColor(Color::White);
	_SoptionExit.setString("EXIT");
	_SoptionExit.setFont(font);
	_SoptionExit.setPosition(915 + 8, 600 + 8);
	_SoptionExit.setFillColor(Color::Black);

	//In-Game Stats
	_scoreText.setFont(font);
	_scoreText.setPosition(180, 140);
	_scoreText.setFillColor(Color::Red);
	_scoreText.setCharacterSize(32);
	_score.setFont(font);
	_score.setPosition(180, 200);
	_score.setFillColor(Color::White);
	_score.setCharacterSize(32);

	_highscoreText.setFont(font);
	_highscoreText.setPosition(180, 400);
	_highscoreText.setFillColor(Color::Yellow);
	_highscoreText.setCharacterSize(32);
	_highscore.setFont(font);
	_highscore.setPosition(180, 460);
	_highscore.setFillColor(Color::White);
	_highscore.setCharacterSize(32);

	_livesText.setFont(font);
	_livesText.setPosition(180, 900);
	_livesText.setFillColor(Color::Blue);
	_livesText.setCharacterSize(32);
	_liveIcon.setPosition(190, 965);
	_liveIcon.setSize(Vector2f(16, 8));
	_liveIcon.setScale(4, 4);
	_lives.setFont(font);
	_lives.setPosition(290, 960);
	_lives.setFillColor(Color::White);
	_lives.setCharacterSize(32);

	_levelText.setFont(font);
	_levelText.setPosition(1490, 550);
	_levelText.setFillColor(Color::Green);
	_levelText.setCharacterSize(40);
	_level.setFont(font);
	_level.setPosition(1750, 550);
	_level.setFillColor(Color::White);
	_level.setCharacterSize(40);
	//Shadows
	_Slogo.setPosition(1920 / 2 + 16, 200 + 16);
	_Slogo.setOrigin(96, 20);
	_Slogo.setSize(Vector2f(193, 41));
	_Slogo.setScale(4, 4);

	_SscoreText.setFont(font);
	_SscoreText.setPosition(180 + 8, 140 + 8);
	_SscoreText.setFillColor(Color::Black);
	_SscoreText.setCharacterSize(32);
	_Sscore.setFont(font);
	_Sscore.setPosition(180 + 8, 200 + 8);
	_Sscore.setFillColor(Color::Black);
	_Sscore.setCharacterSize(32);

	_ShighscoreText.setFont(font);
	_ShighscoreText.setPosition(180 + 8, 400 + 8);
	_ShighscoreText.setFillColor(Color::Black);
	_ShighscoreText.setCharacterSize(32);
	_Shighscore.setFont(font);
	_Shighscore.setPosition(180 + 8, 460 + 8);
	_Shighscore.setFillColor(Color::Black);
	_Shighscore.setCharacterSize(32);

	_SlivesText.setFont(font);
	_SlivesText.setPosition(180 + 8, 900 + 8);
	_SlivesText.setFillColor(Color::Black);
	_SlivesText.setCharacterSize(32);
	_Slives.setFont(font);
	_Slives.setPosition(290 + 8, 960 + 8);
	_Slives.setFillColor(Color::Black);
	_Slives.setCharacterSize(32);

	_SlevelText.setFont(font);
	_SlevelText.setPosition(1490 + 8, 550 + 8);
	_SlevelText.setFillColor(Color::Black);
	_SlevelText.setCharacterSize(40);
	_Slevel.setFont(font);
	_Slevel.setPosition(1750 + 8, 550 + 8);
	_Slevel.setFillColor(Color::Black);
	_Slevel.setCharacterSize(40);
}

void Interface::updateStats(int scoreValue, int highscoreValue, int lives, int level)
{
	_lives.setString(std::to_string(lives));
	_score.setString(std::to_string(scoreValue));
	_level.setString(std::to_string(level));
	//Shadow
	_Slives.setString(std::to_string(lives));
	_Sscore.setString(std::to_string(scoreValue));
	_Slevel.setString(std::to_string(level));

	if (scoreValue > highscoreValue)
	{
		_highscore.setString(std::to_string(scoreValue));
		_Shighscore.setString(std::to_string(scoreValue));
	}

	else
	{
		_highscore.setString(std::to_string(highscoreValue));
		_Shighscore.setString(std::to_string(highscoreValue));
	}

}

bool Interface::loadLogo()
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

bool Interface::loadLiveIcon()
{
	if (!_liveTexture.loadFromFile("ArkanoidUltra_Data/Sprites/Menu/IconLive.png"))
	{
		return false;
	}

	_liveIcon.setTexture(&_liveTexture);
}

bool Interface::loadFont()
{
	if (!font.loadFromFile("ArkanoidUltra_Data/Font/nintendo-nes-font.ttf"))
	{
		return false;
	}
}

bool Interface::SetMusic()
{
	if (!_buffer.loadFromFile("ArkanoidUltra_Data/Musics/Menu.wav"))
		return false;
	_music.setBuffer(_buffer);
}

bool Interface::SetBackground()
{
	if (!_textureBackground.loadFromFile("ArkanoidUltra_Data/Sprites/Level/MenuBG.png"))
		return false;
	_background.setTexture(&_textureBackground);

}

void Interface::DrawTitleScreen(sf::RenderWindow& window)
{
	window.draw(_background);
	window.draw(_Slogo);
	window.draw(_logo);
	window.draw(_SoptionPlay);
	window.draw(_SoptionExit);
	window.draw(_optionPlay);
	window.draw(_optionExit);
}

void Interface::DrawInGameStats(sf::RenderWindow& window)
{
	//Shadows
	window.draw(_SscoreText);
	window.draw(_Sscore);
	window.draw(_ShighscoreText);
	window.draw(_Shighscore);
	window.draw(_SlivesText);
	window.draw(_Slives);
	window.draw(_Slevel);
	window.draw(_SlevelText);
	//Text
	window.draw(_scoreText);
	window.draw(_score);
	window.draw(_highscoreText);
	window.draw(_highscore);
	window.draw(_livesText);
	window.draw(_liveIcon);
	window.draw(_lives);
	window.draw(_level);
	window.draw(_levelText);



}

void Interface::Initialize()
{
	SetMusic();
	SetBackground();
	_music.setVolume(13.f);
	_music.play();
}

void Interface::HighlightOption(sf::RenderWindow& window)
{
	switch (_option)
	{
	case 1:
		_optionPlay.setFillColor(Color::White);

		_optionExit.setFillColor(sf::Color(67, 68, 66));
		break;
	case 2:
		_optionPlay.setFillColor(sf::Color(67, 68, 66));

		_optionExit.setFillColor(Color::White);
		break;
	}
}

string Interface::ChangeOption()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (_option != _minOption)
		{
			_option--;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (_option != _maxOption)
		{
			_option++;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		return ConfirmOption(_option);
	}
	return "NONE";
}

string Interface::ConfirmOption(int option)
{
	if (option == 1)
	{
		return "PLAY";
	}
	if (option == 2)
	{
		return "QUIT";
	}
	return "NONE";
}