
#include <ncurses.h>
#include "ft_retro.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "Enemy.hpp"
#include "Sniper.hpp"

extern int global;

void		wesh()
{
	static int		generate = 0;

	Game	&game = Game::get_instance();
	WINDOW	*win = game.get_window();
	Player	&player = Player::getPlayer();
	int		randE = rand() % game.get_sizeX();

	if (player.is_alive() == false)
	{
		return ;
	}

	player.setShootState(true);
	game.cycle_move();
	game.filter_units();
	game.handle_collide();
	game.filter_units();

	if (generate++ % 3 == 0)
	{
		if (randE % 2)
			game.add_unit(
				new Enemy( randE, 0 )
			);
		else
			game.add_unit(
				new Sniper( randE, 0 )
			);
	}

	if (win != 0)
	{
		wclear(win);
		print_cloud(win, game.get_sizeX(), game.get_sizeY());
		player.print(win);
		game.print_units(win);
		wrefresh(win);
	}
}

void	game_cycle(int sign)
{
	(void)sign;
	global = 1;
}
