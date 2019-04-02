
#include <pthread.h>
#include <ncurses.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <signal.h>
#include <sys/time.h>
#include "ft_retro.hpp"
#include "AUnit.hpp"
#include "Game.hpp"
#include "Player.hpp"

int			global = 0;

void	play(WINDOW *win, int sizeX, int sizeY, WINDOW * stats)
{
	/*
	**	Map is a matrice of pointer to AUnit :
		[
			[ 0, 0, 0, 0, inst, 0]
			[ 0, inst, 0, 0, inst, 0]
			etc
		]
	*/

	Game		&game = Game::set_instance( sizeX, sizeY );
	Player		&player = Player::getPlayer();
	double		now_time;
	

	game.set_window(win);

	signal(SIGALRM, &game_cycle);

	struct itimerval it_val;	/* for setting itimer */
	it_val.it_value.tv_sec = 0;
	it_val.it_value.tv_usec = 100000;
	it_val.it_interval = it_val.it_value;
	setitimer(ITIMER_REAL, &it_val, NULL);

	srand(time(0));
	do
	{
		game.set_start_time(time(0));
		game.clear_units();
		player.setScore( 0 );

		player.set_alive( true );
		player.setPosX( sizeX / 2 );
		player.setPosY( sizeY - 2 );
		player.setStatsWindow( stats );

		player.printScore();

		while (player.is_alive())
		{
			
			if (global != 0)
			{
				global = 0;
				wesh();
			}
			if (key_hook(player, game, sizeX, sizeY) == 1)
			{
				break ;
			}

			werase(win);
			print_cloud(win, sizeX, sizeY);
			game.filter_units();
			player.print(win);
			game.print_units(win);

			wrefresh(win);

			now_time = difftime( time(0), game.get_start_time());

			std::stringstream	timestamp;
			timestamp 
				<< std::setfill('0') 
				<< std::setw(2) 
				<< std::to_string((int)now_time / 60) 
				<< ":" 
				<< std::setfill('0') 
				<< std::setw(2) 
				<< std::to_string((int)now_time % 60);

			mvwaddstr(stats, 15, 10, (std::string("Units number == ") + std::to_string(game.get_units_number()) ).c_str()    );
			mvwaddstr(stats, 16, 10, (std::string("Playing time == ") + timestamp.str()).c_str()  );
			wrefresh(stats);
		}

	} while (play_again(win));

	signal(SIGALRM, SIG_IGN);
	it_val.it_value.tv_sec = 0;
	it_val.it_value.tv_usec = 0;
	it_val.it_interval = it_val.it_value;
	setitimer(ITIMER_REAL, &it_val, NULL);
	player.setStatsWindow( 0 );
	Game::delete_instance();
	Player::deleteInstance();
}
