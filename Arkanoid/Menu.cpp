#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace::std;
using namespace::sf;


Menu::Menu()
{
    _titre.setPosition(671, 200);		// On définit sa position
    _titre.setSize(Vector2f(193, 41));	// On définit ses dimensions
    _titre.setScale(3, 3);
    option = 1;
}

bool Menu::setTextureTitre()
{
    if (!_textureTitre.loadFromFile("Titre.png"))
    {
        return false;
    }

    _titre.setTexture(&_textureTitre); 
}

bool Menu::setTitre()
{
    if (!font.loadFromFile("Pixel Digivolve.otf"))
    {
        return false;
    }

}

void Menu::drawTitre(sf::RenderWindow& window)
{
    window.draw(_titre);

}

void Menu::drawOption(sf::RenderWindow& window)
{
    switch (option)
    {
    case 1:
        _play.setFillColor(Color::Red);

        _exit.setFillColor(Color::White);
        break;
    case 2:
        _play.setFillColor(Color::White);

        _exit.setFillColor(Color::Red);
        break;
    }
    window.draw(_play);
    window.draw(_exit);
}

int Menu::switchMenu(sf::Event& event)
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

void Menu::defaultOption(sf::RenderWindow& window)
{
    _play.setString("Play");
    _play.setFont(font);
    _play.setPosition(915, 500);
    _play.setFillColor(Color::Red);

    _exit.setString("Exit");
    _exit.setFont(font);
    _exit.setPosition(920, 600);
    _exit.setFillColor(Color::White);
}

void Menu::confirmOption(sf::RenderWindow& window, int option)
{
    if (option == 1)
    {

    }
    if (option == 2 )
    {
        window.close();
    }
}



