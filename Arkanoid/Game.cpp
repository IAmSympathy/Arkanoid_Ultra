#include "Game.h"
Game::Game()
{
	_level = 1;
	_lives = 3;
	_score = 0;
	_highscore = 10000;
	//Checks
	_ballCollision = 0;
	_isDead = false;
	_SpawnSoundOnce = false;
	_paused = false;
	escapeIsPressed = false;

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

	_ball.SetTexture();
	_ballShadow.SetTexture();
	_player.SetTexture();
	_playerShadow.SetTexture();
}

void Game::StartLevel(int &level, int &section, int &episode)
{
	_level = level;
	if (level >= 1 && level <= 7)
		section = 1;
	else if (level >= 8 && level <= 15)
		section = 2;
	else if (level >= 16 && level <= 23)
		section = 3;
	else if (level >= 24 && level <= 30)
		section = 4;
	else if (level == 31)
		section = 5;
	SetMusic(section);
	_music.setVolume(13.f);
	_music.play();
	SetBackground(episode, section);
	SetBorder(NORMAL);

	_ball.SetBorders(_leftBorder, _rightBorder, _upBorder);
	_player.SetBorders(_leftBorder, _rightBorder, _upBorder);
	_player.Reset();
}

void Game::Play()
{
	if (_paused == false)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
			_score++;
		}
		//Vérification mort
		if (_player.GetPlayerStatus() != ALIVE)
			_ball.Reset(2);
		else if (_ball.GetState() == 2)
			_player.Die();

		//Actions de la balle
		_ball.CheckCollision(CheckCollision(_player, _ball));
		_ball.Move();
		_ballShadow.move(_ball.getBall());

		//Actions du joueur
		_player.Move();
		_playerShadow.move(_player.GetPlayer());
		if (_ball.GetState() == 0)
			_ball.MoveThrow(_player.GetPlayer());
		checkLives(_player);
		if (_lives == 0)
			_music.stop();
	}
	
	if (_player.GetPlayerStatus() == ALIVE)
	{
		if (escapeIsPressed == false)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				escapeIsPressed = true;
				if (_paused == false)
					_paused = true;
			}
		}
	}
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

void Game::Reset()
{
	_music.stop();
	_score = 0;
	_lives = 3;
}

int Game::GetLives()
{
	return _lives;
}

int Game::GetScore()
{
	return _score;
}

int Game::GetHighScore()
{
	return _highscore;
}

int Game::GetLevel()
{
	return _level;
}

int Game::GetPlayerState()
{
	return _player.GetPlayerStatus();
}

bool Game::GetPaused()
{
	return _paused;
}

bool Game::SetBackground(int &episode, int &section)
{
	switch (episode)
	{
	case 1:
		switch (section)
		{
		case 1:
			if (!_textureBackground.loadFromFile("ArkanoidUltra_Data/Sprites/Level/OneBG1.png"))
				return false;
			break;
		case 2:
			if (!_textureBackground.loadFromFile("ArkanoidUltra_Data/Sprites/Level/OneBG2.png"))
				return false;
			break;
		case 3:
			if (!_textureBackground.loadFromFile("ArkanoidUltra_Data/Sprites/Level/OneBG3.png"))
				return false;
			break;
		case 4:
			if (!_textureBackground.loadFromFile("ArkanoidUltra_Data/Sprites/Level/OneBG4.png"))
				return false;
			break;
		case 5:
			if (!_textureBackground.loadFromFile("ArkanoidUltra_Data/Sprites/Level/OneBG5.png"))
				return false;
			break;
		case 6:
			if (!_textureBackground.loadFromFile("ArkanoidUltra_Data/Sprites/Level/OneBG6.png"))
				return false;
			break;
		}
		break;
	case 2:
		switch (section)
		{
		case 1:
			if (!_textureBackground.loadFromFile("ArkanoidUltra_Data/Sprites/Level/TwoBG1.png"))
				return false;
			break;
		case 2:
			if (!_textureBackground.loadFromFile("ArkanoidUltra_Data/Sprites/Level/TwoBG2.png"))
				return false;
			break;
		case 3:
			if (!_textureBackground.loadFromFile("ArkanoidUltra_Data/Sprites/Level/TwoBG3.png"))
				return false;
			break;
		case 4:
			if (!_textureBackground.loadFromFile("ArkanoidUltra_Data/Sprites/Level/TwoBG4.png"))
				return false;
			break;
		case 5:
			if (!_textureBackground.loadFromFile("ArkanoidUltra_Data/Sprites/Level/TwoBG5.png"))
				return false;
			break;
		case 6:
			if (!_textureBackground.loadFromFile("ArkanoidUltra_Data/Sprites/Level/TwoBG6.png"))
				return false;
			break;
		}
		break;
	case 3:
		switch (section)
		{
		case 1:
			if (!_textureBackground.loadFromFile("ArkanoidUltra_Data/Sprites/Level/ThreeBG1.png"))
				return false;
			break;
		case 2:
			if (!_textureBackground.loadFromFile("ArkanoidUltra_Data/Sprites/Level/ThreeBG2.png"))
				return false;
			break;
		case 3:
			if (!_textureBackground.loadFromFile("ArkanoidUltra_Data/Sprites/Level/ThreeBG3.png"))
				return false;
			break;
		case 4:
			if (!_textureBackground.loadFromFile("ArkanoidUltra_Data/Sprites/Level/ThreeBG4.png"))
				return false;
			break;
		case 5:
			if (!_textureBackground.loadFromFile("ArkanoidUltra_Data/Sprites/Level/ThreeBG5.png"))
				return false;
			break;
		case 6:
			if (!_textureBackground.loadFromFile("ArkanoidUltra_Data/Sprites/Level/ThreeBG6.png"))
				return false;
			break;
		}
		break;
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

void Game::SetPaused(bool value)
{
	_paused = value;
}

void Game::IsKeyPressed(Event event)
{
	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::Escape) {
			escapeIsPressed = false;
		}
	}
}

void Game::checkLives(Player &player)
{
	_lives = player.GetLive();
}

double Game::CheckCollision(Player player, Ball ball)
{
	Vector2f playerPosition = _player.GetPlayer().getPosition();
	Vector2f ballPosition = _ball.getBall().getPosition();
	if(ballPosition.y - 2 * 4 )
	if (_ball.getBall().getGlobalBounds().intersects(_player.GetHitbox().getGlobalBounds()))
	{
		//Calcul de la différence entre les positions
		double dx = ballPosition.x - playerPosition.x;
		double dy = ballPosition.y - 2*4 - playerPosition.y;
		//Calcul l'angle
		double theta = atan2(dy, dx) * 180.0 / M_PI;
		if (theta < 0)
			theta *= -1;
		return theta;
	}
	else
		return -6969;
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

