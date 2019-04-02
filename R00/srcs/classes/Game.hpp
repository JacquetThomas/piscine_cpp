#ifndef GAME_HPP
# define GAME_HPP

# include <cstdlib>
# include <time.h>
# include "AUnit.hpp"
# include "AutoUnit.hpp"

class Game
{
	/*
	**	This class stores game's units
	**	They are stored as a contiguous array of AUnit
	**	filter_units remove the dead ones and repack the array
	*/
	public:
		~Game( void );

		size_t		get_max_units( void ) const;
		size_t		get_units_number( void ) const;
		size_t		get_sizeX( void ) const;
		size_t		get_sizeY( void ) const;

		/*
		**	Store a unit
		**	Returns -1 if unit could not be stored
		*/
		int			add_unit( AutoUnit *unit );

		/*	Filter out dead units */
		void		filter_units( void );

		void		print_units( WINDOW * win ) const;
		void		cycle_move( void );

		void		clear_units( void );

		/* Handle Collide */
		void		handle_collide( void );

		static Game			&get_instance( void );
		static Game			&set_instance( size_t sizeX, size_t sizeY );
		static void			delete_instance( void );

		/* game window getter and setter */
		WINDOW	*get_window( void );
		void	set_window(WINDOW *win);


		/* time_t start_time getter and setter */
		time_t			get_start_time( void );
		void			set_start_time(time_t time);
		
	private:

		static Game			*_instance;

		const size_t	_max_units;
		const size_t	_sizeX;
		const size_t	_sizeY;

		AutoUnit		**_units;
		size_t			_units_number;

		AUnit			***_matrice;
		AUnit			***_old_matrice;

		/* game window */
		WINDOW 			*_win;

		/* help for handle_collide */
		void		clean_matrice(void);
		void		copy_matrice(AUnit ***current, AUnit ***old);
		bool		enemyAutoCollide(AUnit *one, AUnit *two);

		void		generate_matrice( int sizeX, int sizeY );
		/*
		**	Do not use these constructors
		*/
		Game( void );
		Game( size_t sizeX, size_t sizeY );
		Game( const Game & inst );
		Game	&operator=( const Game & inst );

		/*
		** Keep tracking time
		*/
		time_t		_start_time;

};

#endif
