#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Player.h"
#include "Ball.h"
using namespace sf;		// Namespace pour les objets de la librairie SFML
using namespace std;	// Namespace pour les objets de la librairie standard en C++

class Game
{
private:
	sf::Texture _texture;
	sf::Texture _texture2;
	sf::RectangleShape _background;
	sf::RectangleShape _border;

	sf::SoundBuffer _buffer;
	sf::Sound _music;

	bool _isDead;
public:
	Game();

	void StartGame(int level);

	bool SetBackground(int level);
	bool SetBorder();
	bool SetMusic(int level);

	int checkCollision(Player player, Ball ball);

	void draw(sf::RenderWindow& window);
	void drawBorder(sf::RenderWindow& window);
};

