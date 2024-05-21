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
	option = 1;
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
	if (!_logoTexture.loadFromFile("Titre.png"))
	{
		return false;
	}

	_logo.setTexture(&_logoTexture);
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

void Interface::DrawTitleScreen(sf::RenderWindow& window)
{
	window.draw(_logo);
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
	loadFont();
	loadLiveIcon();
	loadLogo();

	//Images
	_logo.setPosition(371, 200);
	_logo.setSize(Vector2f(193, 41));
	_logo.setScale(3, 3);


	//Text Options
	_optionPlay.setString("Play");
	_optionPlay.setFont(font);
	_optionPlay.setPosition(915, 500);
	_optionPlay.setFillColor(Color::Red);

	_optionExit.setString("Exit");
	_optionExit.setFont(font);
	_optionExit.setPosition(920, 600);
	_optionExit.setFillColor(Color::White);

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
	_Slevel.setPosition(1750+ 8, 550 + 8);
	_Slevel.setFillColor(Color::Black);
	_Slevel.setCharacterSize(40);
}

void Interface::HighlightOption(sf::RenderWindow& window)
{
	switch (option)
	{
	case 1:
		_optionPlay.setFillColor(Color::Red);

		_optionExit.setFillColor(Color::White);
		break;
	case 2:
		_optionPlay.setFillColor(Color::White);

		_optionExit.setFillColor(Color::Red);
		break;
	}
}

int Interface::ChangeOption(sf::Event& event)
{

	switch (event.type)
	{
	case sf::Event::KeyPressed:
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
			if (option != 1)
			{
				option--;
			}
			break;
		case sf::Keyboard::Down:
			if (option != 2)
			{
				option++;
			}
			break;
		case sf::Keyboard::Enter:
			return option;
			break;
		}
		break;
	}
}

void Interface::ConfirmOption(sf::RenderWindow& window, int option)
{
	if (option == 1)
	{

	}
	if (option == 2)
	{
		window.close();
	}
}