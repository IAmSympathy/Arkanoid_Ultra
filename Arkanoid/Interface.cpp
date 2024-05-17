#include "Interface.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace::std;
using namespace::sf;


Interface::Interface()
{
    option = 1;
}

void Interface::updateScore(int scoreValue, int highscoreValue)
{
    _score.setString(std::to_string(scoreValue));
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

    _live.setTexture(&_liveTexture);
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
    window.draw(_score);
    window.draw(_highscore);
    window.draw(_live);
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
    _live.setPosition(96, 48);
    _live.setSize(Vector2f(16, 8));
    _live.setScale(3.5, 3.5);

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
    _score.setFont(font);
    _score.setPosition(920, 600);
    _score.setFillColor(Color::White);

    _highscore.setFont(font);
    _highscore.setPosition(920, 800);
    _highscore.setFillColor(Color::White);
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
    if (option == 2 )
    {
        window.close();
    }
}