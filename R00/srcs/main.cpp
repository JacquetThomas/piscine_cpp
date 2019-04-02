
#include <iostream>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_retro.hpp"

int		init_windows(WINDOW *origin, win (&windows)[2])
{

	if (COLS < MIN_X_GAME)
	{
		return -1;
	}
	windows[0].width = std::min(MAX_X_GAME, COLS);
	windows[0].height = LINES;
	if (!(windows[0].win = subwin(origin, windows[0].height, windows[0].width, 0, 0)))
	{
		return -1;
	}

	if (COLS > MAX_X_GAME + X_STATS)
	{
		windows[1].width = X_STATS;
		windows[1].height = LINES;
		windows[1].win = subwin(origin, windows[1].height, windows[1].width, 0, windows[0].width);
	}

	return 0;
}

int		main(void)
{
	WINDOW		*w;
	win			windows[2] = {{}};

	/*
	**	Ncurses initialisation
	**
	**	Disable cursor's highlight
	*/
	if (!isatty(0) || !isatty(1))
	{
		std::cerr << "Could not initialise terminal properly" << std::endl;
		return 1;
	}
	if ((w = initscr()) == NULL)
	{
		std::cerr << "Could not initialise terminal properly" << std::endl;
		return 1;
	}
	if (init_windows(w, windows) == -1)
	{
		std::cerr << "Could not initialise terminal's windows properly" << std::endl;
		return 1;
	}
	cbreak();
	nodelay(windows[0].win, true);
	nodelay(stdscr, true);
	curs_set(0);
	noecho();

	play(
		windows[0].win,
		windows[0].width,
		windows[0].height,
		windows[1].win
	);

	delwin(windows[0].win);
	if (windows[1].win != NULL)
	{
		delwin(windows[1].win);
	}

	delwin(w);
	endwin();
	return EXIT_SUCCESS;
}
