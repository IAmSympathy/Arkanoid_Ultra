#include "Game.h"

Game::Game()
{
	_background.setPosition(0, 0);		// On définit sa position
	_background.setSize(Vector2f(1920, 1080));	// On définit ses dimensions
}

bool Game::bgSetTexture()
{
	if (!_textureBG.loadFromFile("Ressources/Sprites/LevelBG1.png"))
		return false;

	_background.setTexture(&_textureBG);
}

void Game::drawBG(sf::RenderWindow& window)
{
	window.draw(_background);
}
