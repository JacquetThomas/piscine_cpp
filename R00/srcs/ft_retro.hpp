#ifndef FT_RETRO_HPP
# define FT_RETRO_HPP

# include <ncurses.h>
# include "Player.hpp"
# include "Game.hpp"


# define MIN_X_GAME		60
# define MAX_X_GAME		120
# define X_STATS		60

struct		win
{
	WINDOW		*win;
	size_t		width;
	size_t		height;
};

void	game_cycle(int sign);
bool	play_again(WINDOW *win);
int		key_hook(Player &player, Game &game, int sizeX, int sizeY);
void	play(WINDOW *, int, int, WINDOW *);
void	wesh(void);
void	print_cloud(WINDOW *win, size_t x, size_t y);

#endif
