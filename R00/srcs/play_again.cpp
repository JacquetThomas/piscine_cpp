
#include <sstream>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include "ft_retro.hpp"

bool		play_again(WINDOW * win)
{
	signal(SIGALRM, SIG_IGN);

	std::string		msg;
	std::stringstream toto(
		" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"
		" ~                                      ~ \n"
		" ~                                      ~ \n"
		" ~                                      ~ \n"
		" ~     The impossible happened          ~ \n"
		" ~                                      ~ \n"
		" ~                                      ~ \n"
		" ~          YOU LOST                    ~ \n"
		" ~                                      ~ \n"
		" ~                                      ~ \n"
		" ~    Try again ?? y / n                ~ \n"
		" ~                                      ~ \n"
		" ~                                      ~ \n"
		" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
	size_t			i = 0;


	wclear(win);
	while (std::getline(toto, msg, '\n'))
	{
		mvwaddstr(win, 10 + i++, 10, msg.c_str());
	}
	wrefresh(win);

	usleep(1000000);
	while (getch() != ERR);

	switch (getchar())
	{
		case 'y':
			signal(SIGALRM, game_cycle);
			return true;
		default:
			return false;
	}
}
