#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "AUnit.hpp"
# include "AutoUnit.hpp"

class Player : public AUnit
{
	public:
		static Player	&getPlayer( void );
		static void		deleteInstance( void );

		~Player( void );

		Player	&operator=( const Player & inst );

		AutoUnit	*shoot( void ) const;
		bool		collide( int x, int y );

		void		print( WINDOW * win ) const;
		void		setScore(int score);
		void		addScorePoints(int points);
		int			getScore( void ) const ;
		void		printScore( void ) const ;
		void		setStatsWindow( WINDOW * win );
		bool		getShootState( void );
		void		setShootState(bool state);

	private:
		Player( void );
		Player( const Player & inst );
		int			_score;
		WINDOW		* _stats_win;
		bool		_shoot_state;

		static Player	*	_singleton;

		/* We are not going to free player on collision, but keep a state instead */
};

#endif
