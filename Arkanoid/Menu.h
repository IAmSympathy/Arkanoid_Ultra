#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
class Menu
{
private:
	sf::RectangleShape _titre;
	sf::Texture _textureTitre;

	sf::Text _play;
	sf::Text _exit;
	sf::Font font;
	int option;
public:
	Menu();
	bool setTextureTitre();
	bool setTitre();
	void drawTitre(sf::RenderWindow& window);
	void drawOption(sf::RenderWindow& window);
	int switchMenu(sf::Event& event);
	void defaultOption(sf::RenderWindow& window);
	void confirmOption(sf::RenderWindow& window, int option);
};

