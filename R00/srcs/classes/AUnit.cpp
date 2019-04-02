
#include "AUnit.hpp"

AUnit::AUnit( void ) :
	_posX( 0 ),
	_posY( 0 ),
	_oldPosX( 0 ),
	_oldPosY( 0 ),
	_alive( true ),
	_enemy ( false )
{
	return ;
}

AUnit::AUnit( int x, int y ) :
	_posX( x ),
	_posY( y ),
	_oldPosX( 0 ),
	_oldPosY( 0 ),
	_alive( true ),
	_enemy ( false )
{
	return ;
}

AUnit::AUnit( const AUnit & inst ):
	_posX( inst.getPosX() ),
	_posY( inst.getPosY() ),
	_oldPosX( inst.getOldPosX() ),
	_oldPosY( inst.getOldPosY() ),
	_alive( inst.is_alive() ),
	_enemy ( inst._enemy )
{
	return ;
}

AUnit::~AUnit( void )
{
	return ;
}

AUnit	&	AUnit::operator=( const AUnit & lhs )
{
	_posX = lhs.getPosX();
	_posY = lhs.getPosY();
	_oldPosX = lhs.getOldPosX();
	_oldPosY = lhs.getOldPosY();
	_alive = lhs.is_alive();
	_enemy = lhs.is_enemy();
	return *this;
}

int			AUnit::getPosX( void ) const { return _posX; }
int			AUnit::getPosY( void ) const { return _posY; }
int			AUnit::getOldPosX( void ) const { return _oldPosX; }
int			AUnit::getOldPosY( void ) const { return _oldPosY; }

void		AUnit::setPosX( int x ) {
	_oldPosX = _posX;
	_posX = x;
}
void		AUnit::setPosY( int y ) {
	_oldPosY = _posY;
	_posY = y;
}

void		AUnit::moveLeft( ) {
	_oldPosX = _posX;
	_posX--;
}
void		AUnit::moveRight( ) {
	_oldPosX = _posX;
	_posX++;
}
void		AUnit::moveTop( ) {
	_oldPosY = _posY;
	_posY--;
}
void		AUnit::moveBottom( ) {
	_oldPosY = _posY;
	_posY++;
}

bool		AUnit::is_alive( void ) const { return _alive; }
void		AUnit::set_alive( bool alive ) { _alive = alive; }
void		AUnit::die( void ) { _alive = false; }
bool		AUnit::is_enemy( void ) const { return _enemy; }
