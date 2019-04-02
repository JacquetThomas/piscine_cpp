#ifndef AUNIT_HPP
# define AUNIT_HPP

# include <ncurses.h>
# include "IUnit.hpp"

class AUnit : public IUnit
{
	public:
		AUnit( void );
		AUnit( int x, int y );
		AUnit( const AUnit & inst );
		~AUnit( void );

		AUnit	&	operator=( const AUnit & lhs );

		int		getPosX( void ) const;
		int		getPosY( void ) const;
		int		getOldPosX( void ) const;
		int		getOldPosY( void ) const;

		void	setPosX( int );
		void	setPosY( int );

		void	moveLeft( void );
		void	moveRight( void );
		void	moveTop( void );
		void	moveBottom( void );

		bool		is_alive( void ) const;
		void		set_alive( bool );
		void		die( void );

		bool		is_enemy( void ) const;

	protected:
		int		_posX;
		int		_posY;

		int		_oldPosX;
		int		_oldPosY;

		int		_alive;

		bool	_enemy;
};

#endif
