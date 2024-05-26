/*====================================
// Filename : main.cpp
// Description : This file contains the main function for the Arkanoind game
// Author : Samy Larochelle
// Date : May 9th, 2024
====================================*/
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "UserInterface.h"
#include "Game.h"
#include "ObjectShadow.h"
#include "Brick.h"
#include "Player.h"
#include "Ball.h"

using namespace sf;
using namespace std;

int main() {

	//Initialize
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Arkanoid Ultra!");
	window.setFramerateLimit(144);

	Game game;
	Menu menu;
	UserInterface userInterface;
	int option = 0;
	int level = 0;
	int section = 1;
	int episode = 0;
	enum state { TITLE, EPISODES, LEVELS, QUIT, INSTRUCTIONS, GAMEOVER, PAUSE };
	enum playerStates { SPAWNING, ALIVE, DYING, EXPLODING, THROW };
	menu.Initialize();

	//Main loop
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}

		window.clear(Color::Black);

		//Menu logic
		if (menu.GetState() != -1)
		{

			switch (menu.GetState())
			{
			case TITLE:
				if (menu.ChangeOption() == 1)
				{
					menu.SetState(EPISODES);

				}
				else if ((menu.ChangeOption() == 2))
				{
					window.close();
				}
				break;
			case EPISODES:
				episode = menu.ChangeOption();
				if (!(episode == 0 || episode == 5))
				{
					menu.SetState(LEVELS);
				}
				break;
			case LEVELS:
				level = menu.ChangeOption();
				if (level != 0)
				{
					game.StartLevel(level, section, episode);
					menu.SetState(-1);
				}
			case GAMEOVER:
				option = menu.ChangeOption();
				if (option == 1)
				{
					menu.SetState(-1);
					game.Reset();
					game.StartLevel(level, section, episode);
				}
				if (option == 2)
				{
					menu.Initialize();
					game.Reset();
				}
			case PAUSE:
				option = menu.ChangeOption();
				if (option == 1)
				{
					game.SetPaused(false);
					menu.SetState(-1);
				}
				if (option == 2)
				{
					menu.Initialize();
					game.Reset();
					game.SetPaused(false);
				}
			}

		}
		//Game logic
		else
		{
			game.Play();
			userInterface.updateStats(game.GetScore(), game.GetHighScore(), game.GetLives(), game.GetLevel());
			if (game.GetLives() == 0 && game.GetPlayerState() == SPAWNING)
			{
				menu.SetState(GAMEOVER);
			}
			if (game.GetPaused() == true)
				menu.SetState(PAUSE);
		}
		game.Draw(window);
		userInterface.DrawInGameStats(window);
		menu.IsKeyPressed(event);
		game.IsKeyPressed(event);
		menu.Draw(window);
		window.display();
	}
}
