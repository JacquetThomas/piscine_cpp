
#include <string>
#include "AutoUnit.hpp"

AutoUnit::AutoUnit( void ) :
	AUnit(),
	_pattern( std::string() ),
	_pattern_pos( 0 )
{
	return ;
}

AutoUnit::AutoUnit( int x, int y, const std::string & pattern ) :
	AUnit( x, y ),
	_pattern( pattern ),
	_pattern_pos( 0 )
{
	return ;
}

AutoUnit::AutoUnit( const AutoUnit & inst ) :
	AUnit( inst ),
	_pattern( inst.get_pattern() ),
	_pattern_pos( inst.get_pattern_pos() )
{
	return ;
}

AutoUnit::~AutoUnit( void )
{
	return ;
}

AutoUnit	&	AutoUnit::operator=( const AutoUnit & lhs )
{
	AUnit::operator=( lhs );
	return *this;
}

std::string		AutoUnit::get_pattern( void ) const { return _pattern; }
size_t			AutoUnit::get_pattern_pos( void ) const { return _pattern_pos; }

void			AutoUnit::move( void )
{
	if (_pattern.length() > 0)
	{
		switch(_pattern[_pattern_pos])
		{
			case '>':
				moveLeft();
				break ;
			case '<':
				moveRight();
				break ;
			case '^':
				moveTop();
				break ;
			case 'v':
				moveBottom();
				break ;
		}
		_pattern_pos = (_pattern_pos + 1) % _pattern.length();
	}
}
