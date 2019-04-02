
#include <ncurses.h>
#include <typeinfo>
#include "Player.hpp"
#include "Game.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "Sniper.hpp"

Game::Game( void ) :
	_max_units( 0 ),
	_sizeX( 0 ),
	_sizeY( 0 ),
	_units( 0 ),
	_units_number( 0 ),
	_matrice( 0 )
{
	return ;
}

Game::Game( size_t sizeX, size_t sizeY ) :
	_max_units( sizeX * sizeY ),
	_sizeX( sizeX ),
	_sizeY( sizeY ),
	_units( new AutoUnit*[_max_units] ),
	_units_number( 0 ),
	_matrice( 0 )
{
	generate_matrice( _sizeX, _sizeY );
	for (size_t i = 0; i < _max_units; i++)
	{
		_units[i] = 0;
	}
	return ;
}

Game::Game( const Game & inst ) :
	_max_units( inst.get_max_units() ),
	_sizeX( inst.get_sizeX() ),
	_sizeY( inst.get_sizeY() ),
	_units( new AutoUnit*[_max_units] ),
	_units_number( inst.get_units_number() ),
	_matrice( 0 )
{
	generate_matrice( _sizeX, _sizeY );
	for (size_t i = 0; i < _max_units; i++)
	{
		_units[i] = 0;
	}
	return ;
}

Game::~Game( void )
{
	if (_matrice != 0)
	{
		for (size_t x = 0; x < _sizeX; x++)
		{
			delete _matrice[x];
			_matrice[x] = 0;
		}
		delete _matrice;
		_matrice = 0;
	}
	if (_old_matrice != 0)
	{
		for (size_t x = 0; x < _sizeX; x++)
		{
			delete _old_matrice[x];
			_old_matrice[x] = 0;
		}
		delete _old_matrice;
		_old_matrice = 0;
	}
	for (size_t i = 0; i < _units_number; i++)
	{
		delete _units[i];
		_units[i] = 0;
	}
	delete[] _units;
	_units = 0;
	return ;
}

Game	&	Game::operator=( const Game & lhs )
{
	( void )lhs; // Should never be used
	return *this;
}

size_t		Game::get_sizeX( void ) const { return _sizeX; }
size_t		Game::get_sizeY( void ) const { return _sizeY; }
size_t		Game::get_max_units( void ) const { return _max_units; }
size_t		Game::get_units_number( void ) const { return _units_number; }

int		Game::add_unit( AutoUnit *unit )
{
	if ( _units_number + 1 < _max_units )
	{
		_units[_units_number++] = unit;
		return 0;
	}
	return -1;
}

void	Game::filter_units( void )
{
	size_t		dead_units = 0;

	for (size_t i = 0; i < _units_number; i++)
	{
		if (_units[i] != 0
			&& _units[i]->is_alive() == false)
		{
			delete _units[i];
			_units[i] = 0;
			dead_units++;
		}
	}
	if (dead_units > 0)
	{
		/* Repack the array */
		size_t	iback = 0;
		size_t	ifront = 0;

		while (ifront < _units_number)
		{
			if (_units[ifront] != 0) // not a removed one
			{
				if (ifront != iback) // move only if necessary
				{
					_units[iback] = _units[ifront];
				}
				iback++;
			}
			ifront++;
		}

	}
	_units_number -= dead_units;
}

void		Game::clear_units( void )
{
	for (size_t i = 0; i < _units_number; i++)
	{
		delete _units[i];
		_units[i] = 0;
	}
	_units_number = 0;
}

void		Game::print_units( WINDOW *win ) const
{
	for (size_t i = 0; i < _units_number; i++)
	{
		if (_units[i] != 0)
			_units[i]->print(win);
	}
}

void	Game::generate_matrice( int sizeX, int sizeY )
{
	AUnit		***map;

	for (int cpt = 0; cpt < 2; cpt++)
	{
		map = new AUnit**[sizeX + 15];
		for (int x = 0; x < sizeX; x++)
		{
			map[x] = new AUnit*[sizeY + 15];
			for (int y = 0; y < sizeY; y++)
			{
				map[x][y] = 0;
			}
		}
		if (cpt % 2)
			_matrice = map;
		else
			_old_matrice = map;
	}
}

void	Game::cycle_move( void )
{
	for (size_t i = 0; i < _units_number; i++)
	{
		_units[i]->move();
		if (_units[i]->getPosX() < 0 || _units[i]->getPosX() >= (int)_sizeX)
			_units[i]->die();
		if (_units[i]->getPosY() < 0 || _units[i]->getPosY() >= (int)_sizeY)
			_units[i]->die();
	}
}

bool	Game::enemyAutoCollide(AUnit *one, AUnit *two) {
	return (one->is_enemy() && two->is_enemy());
}

void	Game::handle_collide( void )
{
	Player	&tmPlayer = Player::getPlayer();
	int		UPosX;
	int		UPosY;

	clean_matrice();
	_matrice[tmPlayer.getPosX()][tmPlayer.getPosY()] = &tmPlayer;
	for (size_t i = 0; i < _units_number; i++)
	{
		UPosX = _units[i]->getPosX();
		UPosY = _units[i]->getPosY();

		/*
		** Handle direct collisions : If there is several units on the same square,
		**	kill all. No pity
		*/

		if (_matrice[UPosX][UPosY] != 0)
		{
			_matrice[UPosX][UPosY]->die();
			_units[i]->die();
			if (!enemyAutoCollide(_matrice[UPosX][UPosY], _units[i]))
				tmPlayer.addScorePoints(1);
		}

		/*
		**	Direct collision can miss some, like when two units just swap their positions
		**	Check for swaps, and same results : The death
		*/

		AUnit	*other_unit = _matrice[tmPlayer.getOldPosX()][tmPlayer.getOldPosY()];

		if (other_unit != 0)
		{
			if (
				_old_matrice[UPosX][UPosY] == other_unit
				&& _matrice[other_unit->getOldPosX()][other_unit->getOldPosY()] == _units[i]
			)
			{
				_units[i]->die();
				other_unit->die();
				if (!enemyAutoCollide(_matrice[UPosX][UPosY], _units[i]))
					tmPlayer.addScorePoints(1);
			}
		}

		_matrice[UPosX][UPosY] = _units[i];
	}
	copy_matrice(_matrice, _old_matrice);
}

void	Game::clean_matrice( void )
{
	for (size_t x = 0; x < _sizeX; x++)
	{
		for (size_t y = 0; y < _sizeY; y++)
		{
			_matrice[x][y] = 0;
		}
	}
}

void	Game::copy_matrice(AUnit ***current, AUnit ***old)
{
	for (size_t x = 0; x < _sizeX; x++)
	{
		for (size_t y = 0; y < _sizeY; y++)
		{
			old[x][y] = current[x][y];
		}
	}
}


Game		*Game::_instance = 0;

Game		&Game::set_instance( size_t sizeX, size_t sizeY )
{
	if (_instance == 0)
	{
		Game::_instance = new Game( sizeX, sizeY );
	}
	return *Game::_instance;
}

void		Game::delete_instance( void )
{
	if (_instance != 0)
	{
		delete Game::_instance;
		Game::_instance = 0;
	}
}

Game		&Game::get_instance( void )
{
	return *Game::_instance;
}

WINDOW	*Game::get_window( void ) {
	return (this->_win);
}

void	Game::set_window(WINDOW *win) {
	this->_win = win;
}


time_t	Game::get_start_time( void ) {
	return (this->_start_time);
}

void	Game::set_start_time(time_t time) {
	this->_start_time = time;
}