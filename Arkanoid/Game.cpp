#include "Game.h"

Game::Game()
{
	_background;
	_textureBG;
}

bool Game::bgSetTexture()
{
	if (!_textureBG.loadFromFile("Ressources/Sprites/LevelBG1.png"))
		return false;

	_background.setTexture(_textureBG);
}

sf::Sprite Game::getBackground()
{
	return _background;
}
