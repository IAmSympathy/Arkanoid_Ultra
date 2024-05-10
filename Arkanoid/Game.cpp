#include "Game.h"

Game::Game()
{
	_background.setPosition(0, 0);		// On définit sa position
	_background.setSize(Vector2f(1920, 1080));	// On définit ses dimensions
	_border.setPosition(0, 0);		// On définit sa position
	_border.setSize(Vector2f(1920, 1080));	// On définit ses dimensions
}

void Game::StartGame(int level)
{
	switch (level)
	{
	case 1:
		SetMusic(level);
	}
	_music.setVolume(13.f);
	_music.play();
}

bool Game::SetBackground(int level)
{
	switch (level)
	{
	case 1:
		if (!_texture.loadFromFile("Ressources/Sprites/LevelBG1.png"))
			return false;
	}
	_background.setTexture(&_texture);
}

bool Game::SetBorder()
{
	if (!_texture2.loadFromFile("Ressources/Sprites/LevelBorder.png"))
		return false;

	_border.setTexture(&_texture2);
}

bool Game::SetMusic(int level)
{
	switch (level)
	{
	case 1:
		if (!_buffer.loadFromFile("Ressources/Audio/Music/Level1.wav"))
			return false;
		break;
	}
	_music.setBuffer(_buffer);
}

void Game::draw(sf::RenderWindow& window)
{
	window.draw(_background);
	window.draw(_border);
}

void Game::drawBorder(sf::RenderWindow& window)
{
	window.draw(_border);
}
