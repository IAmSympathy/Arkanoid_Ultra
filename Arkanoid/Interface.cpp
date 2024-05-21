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
	option = 1;
}

void Interface::updateStats(int scoreValue, int highscoreValue, int lives)
{
	_lives.setString(std::to_string(lives));
	_score.setString(std::to_string(scoreValue));

	if (scoreValue > highscoreValue)
		_highscore.setString(std::to_string(scoreValue));
	else
		_highscore.setString(std::to_string(highscoreValue));
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
	window.draw(_scoreText);
	window.draw(_score);
	window.draw(_highscoreText);
	window.draw(_highscore);
	window.draw(_livesText);
	window.draw(_liveIcon);
	window.draw(_lives);


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
	_scoreText.setPosition(200, 140);
	_scoreText.setFillColor(Color::Red);
	_scoreText.setCharacterSize(32);
	_score.setFont(font);
	_score.setPosition(200, 190);
	_score.setFillColor(Color::White);
	_score.setCharacterSize(32);

	_highscoreText.setFont(font);
	_highscoreText.setPosition(200, 340);
	_highscoreText.setFillColor(Color::Yellow);
	_highscoreText.setCharacterSize(32);
	_highscore.setFont(font);
	_highscore.setPosition(200, 390);
	_highscore.setFillColor(Color::White);
	_highscore.setCharacterSize(32);

	_livesText.setFont(font);
	_livesText.setPosition(200, 800);
	_livesText.setFillColor(Color::Blue);
	_livesText.setCharacterSize(32);
	_liveIcon.setPosition(210, 855);
	_liveIcon.setSize(Vector2f(16, 8));
	_liveIcon.setScale(4, 4);
	_lives.setFont(font);
	_lives.setPosition(320, 850);
	_lives.setFillColor(Color::White);
	_lives.setCharacterSize(32);

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