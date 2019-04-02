#ifndef IUNIT_HPP
# define IUNIT_HPP

# include <ncurses.h>

class IUnit
{
	public:
		virtual ~IUnit() {};

		virtual void		moveTop( ) = 0;
		virtual void		moveBottom( ) = 0;
		virtual void		moveLeft( ) = 0;
		virtual void		moveRight( ) = 0;

		virtual void		print( WINDOW * win ) const = 0;
};

#endif
