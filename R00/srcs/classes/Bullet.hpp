#ifndef BULLET_HPP
# define BULLET_HPP

# include "AutoUnit.hpp"

class Bullet : public AutoUnit
{
	public:
		~Bullet( void );
		Bullet( int x, int y );

		void	print( WINDOW * win ) const;

	private:
		Bullet( void );
		Bullet( const Bullet & inst );

		Bullet	&operator=( const Bullet & inst );
};

#endif
