
#include <iostream>
#include <ncurses.h>
#include "Player.hpp"
#include "Bullet.hpp"

Player	*Player::_singleton = 0;

Player	&Player::getPlayer( void )
{
	if (Player::_singleton == 0)
	{
		Player::_singleton = new Player;
	}
	return *Player::_singleton;
}

void	Player::deleteInstance( void )
{
	if (Player::_singleton != 0)
	{
		delete Player::_singleton;
		Player::_singleton = 0;
	}
}

Player::Player( void ) :
	AUnit(),
	_score( 0 ),
	_stats_win( 0 ), _shoot_state (true)
{
	return ;
}

Player::Player( const Player & inst ) :
	AUnit( inst ),
	_score( inst.getScore() ),
	_stats_win( 0 )
{
	this->_score = inst._score;
	this->_shoot_state = inst._shoot_state;
	return ;
}

Player::~Player( void )
{
	return ;
}

Player	&	Player::operator=( const Player & lhs )
{
	AUnit::operator=(lhs);
	return *this;
}

AutoUnit	*Player::shoot( void ) const
{
	return new Bullet(_posX, _posY - 1);
}

void		Player::print( WINDOW * win ) const
{
	std::string pattern = "O";
	mvwaddstr(win, _posY, _posX, pattern.c_str());
}

void		Player::printScore( void ) const
{
	if (_stats_win != 0)
	{
		std::string		message = std::string("Current score :: ") + std::to_string(_score);
		wclear(_stats_win);
		mvwaddstr(_stats_win, 9, 10, "####################");
		mvwaddstr(_stats_win, 10, 10, message.c_str());
		mvwaddstr(_stats_win, 11, 10, "####################");
	//	wrefresh(_stats_win);
	}
}

void		Player::setScore(int score) {
	this->_score = score;
	printScore();
}

void		Player::addScorePoints(int points) {
	this->_score += points;
	printScore();
}

int			Player::getScore( void ) const{
	return (this->_score);
}

void		Player::setStatsWindow( WINDOW * win )
{
	_stats_win = win;
}


bool		Player::getShootState( void ) {
	return (this->_shoot_state);
}
void		Player::setShootState(bool state) {
	this->_shoot_state = state;
}
