#include "Functions.h"

void MenuLogic(sf::RenderWindow& window, Game& game, Menu& menu)
{
	int option = 0;
	int level = 0;
	int section = 1;
	int episode = 0;

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
