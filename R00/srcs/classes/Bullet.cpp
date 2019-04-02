
#include <ncurses.h>
#include "Bullet.hpp"

#include <ncurses.h>
Bullet::Bullet( void ) :
	AutoUnit( 0, 0, "^" )
{
	return ;
}

Bullet::Bullet( int x, int y ) :
	AutoUnit( x, y, "^" )
{
	return ;
}

Bullet::Bullet( const Bullet & inst ) :
	AutoUnit( inst.getPosX(), inst.getPosY(), "^" )
{
	return ;
}

Bullet::~Bullet( void )
{
	return ;
}

Bullet	&	Bullet::operator=( const Bullet & lhs )
{
	AutoUnit::operator=( lhs );
	return *this;
}

void		Bullet::print( WINDOW *win ) const
{
	mvwaddch(win, _posY, _posX, '.');
}
