#pragma once
#include <SFML/Graphics.hpp>
class Menu
{
private:
	sf::RectangleShape _titre;
	sf::Texture _textureTitre;
public:
	Menu();
	bool setTextureTitre();
	void drawTitre(sf::RenderWindow& window);
};

