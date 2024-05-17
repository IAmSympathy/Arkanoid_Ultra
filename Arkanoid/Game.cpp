#include "Game.h"

Game::Game()
{
	_score = 999999;
	_highscore = 999999;
	//Checks
	_ballCollision = 0;
	_isDead = false;
	_SpawnSoundOnce = false;

	//Shadows
	_playerShadow.SetType("Player");
	_ballShadow.SetType("Ball");

	//Collisions
	_leftBorder = 0;
	_rightBorder = 0;
	_upBorder = 0;

	//Decorations
	_background.setPosition(0, 0);		// On définit sa position
	_background.setSize(Vector2f(1920, 1080));	// On définit ses dimensions
	_border.setPosition(0, 0);		// On définit sa position
	_border.setSize(Vector2f(1920, 1080));	// On définit ses dimensions
	_borderS.setPosition(0, 0);		// On définit sa position
	_borderS.setSize(Vector2f(1920, 1080));	// On définit ses dimensions
	_borderBG.setPosition(0, 0);		// On définit sa position
	_borderBG.setSize(Vector2f(1920, 1080));	// On définit ses dimensions
}

void Game::StartLevel(int level)
{
	SetMusic(level);
	_music.setVolume(13.f);
	_music.play();

	SetBackground(level);
	SetBorder(NORMAL);

	_ball.SetTexture();
	_ballShadow.SetTexture();
	_ball.SetBorders(_leftBorder, _rightBorder, _upBorder);

	_player.SetTexture();
	_playerShadow.SetTexture();
	_player.SetBorders(_leftBorder, _rightBorder, _upBorder);
}

void Game::Play()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		_score++;
	}
	//Vérification mort
	if (_player.GetPlayerStatus() != ALIVE)
		_ball.SetState(2);
	else if (_ball.GetState() == 2)
		_player.Die();

	//Actions de la balle
	_ballCollision = CheckCollision(_player, _ball);
	_ball.CheckCollision(_ballCollision);
	_ball.Move();
	_ballShadow.move(_ball.getBall());

	//Actions du joueur
	_player.Move();
	_playerShadow.move(_player.GetPlayer());

	int playerStatus = _player.GetPlayerStatus();
	switch (playerStatus)
	{
	case SPAWNING:
		if (_player.GetLive() > 0)
		{
			if (_SpawnSoundOnce == false)
			{
				_player.PlaySound(1);
				_SpawnSoundOnce = true;
			}

			_player.SpawnAnimation();
				if (_player.GetIsSpawned() == true)
				{
					_player.Revive();
					_ball.Revive();
				}
		}
		break;
	case ALIVE:
		_player.IdleAnimation();
		break;
	case DYING:
		_SpawnSoundOnce = false;
		_player.DieAnimation();
		break;
	case EXPLODING:
		_player.ExplodeAnimation();
		break;
	}
}

int Game::GetScore()
{
	return _score;
}

int Game::GetHighScore()
{
	return _highscore;
}

bool Game::SetBackground(int section)
{
	switch (section)
	{
	case 1:
		if (!_textureBackground.loadFromFile("ArkanoidUltra_Data/Sprites/Level/LevelBG1.png"))
			return false;
	}
	_background.setTexture(&_textureBackground);
}

bool Game::SetBorder(int size)
{
	switch (size)
	{
	case NORMAL:
		if (!_textureBorder.loadFromFile("ArkanoidUltra_Data/Sprites/Level/LevelBorder.png"))
			return false;
		_border.setTexture(&_textureBorder);

		if (!_textureBorderS.loadFromFile("ArkanoidUltra_Data/Sprites/Level/LevelBorder_S.png"))
			return false;
		_borderS.setTexture(&_textureBorderS);

		if (!_textureBorderBG.loadFromFile("ArkanoidUltra_Data/Sprites/Level/LevelBorder_BG.png"))
			return false;
		_borderBG.setTexture(&_textureBorderBG);

		_leftBorder = 544;
		_rightBorder = 1372;
		_upBorder = 152;
	}
}

bool Game::SetMusic(int section)
{
	switch (section)
	{
	case 1:
		if (!_buffer.loadFromFile("ArkanoidUltra_Data/Musics/Level1.wav"))
			return false;
		break;
	}
	_music.setBuffer(_buffer);
}

int Game::CheckCollision(Player player, Ball ball)
{
	if (ball.getBall().getGlobalBounds().intersects(player.GetCol(1).getGlobalBounds()))
	{
		return 1;
	}
	else if (ball.getBall().getGlobalBounds().intersects(player.GetCol(2).getGlobalBounds()))
	{
		return 2;
	}
	else if (ball.getBall().getGlobalBounds().intersects(player.GetCol(3).getGlobalBounds()))
	{
		return 3;
	}
	else if (ball.getBall().getGlobalBounds().intersects(player.GetCol(4).getGlobalBounds()))
	{
		return 4;
	}
	else if (ball.getBall().getGlobalBounds().intersects(player.GetCol(5).getGlobalBounds()))
	{
		return 5;
	}
	else if (ball.getBall().getGlobalBounds().intersects(player.GetCol(6).getGlobalBounds()))
	{
		return 6;
	}
	else
		return 0;
}

void Game::Draw(sf::RenderWindow& window)
{
	window.draw(_background);
	window.draw(_borderBG);
	window.draw(_borderS);
	if (_player.GetPlayerStatus() == ALIVE)
	{
		_playerShadow.draw(window);
		_ballShadow.draw(window);
		_ball.Draw(window);
	}
	_player.Draw(window);
	window.draw(_border);
}

