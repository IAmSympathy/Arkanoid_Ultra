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
}

bool Menu::setTextureTitre()
{
    if (!_textureTitre.loadFromFile("Titre.png"))
    {
        return false;
    }
        
    _titre.setTexture(&_textureTitre); // Applique la texture à l’élément souhaité

}

void Menu::drawTitre(sf::RenderWindow& window)
{
    window.draw(_titre);
}


