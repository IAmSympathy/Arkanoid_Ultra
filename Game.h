#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Game
{
private:
	sf::RectangleShape _fondEcran;

public:
	Game();
	void drawDecorations();
};

