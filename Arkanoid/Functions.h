#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"

int option = 0;
int level = 0;
int section = 1;
int episode = 0;

enum state { TITLE, EPISODES, LEVELS, QUIT, INSTRUCTIONS, GAMEOVER, PAUSE };
enum playerStates { SPAWNING, ALIVE, DYING, EXPLODING, THROW };

void MenuLogic(sf::RenderWindow& window, Game &game, Menu &menu);