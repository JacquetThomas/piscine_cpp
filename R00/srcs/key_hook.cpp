
#include <ncurses.h>
#include "Player.hpp"
#include "Game.hpp"

int		key_hook(Player &player, Game &game, int sizeX, int sizeY)
{
	switch (getch())
	{
		/* Quit the program */
		case 'q':
			return 1;
			break ;

		/* An escape sequence */
		case 0x1b:
			getch(); /* Skip one char */

			switch( getch() )
			{
				case 'A': /* Pressed arrow up */
					if (player.getPosY() > 0)
						player.moveTop();
					break ;
				case 'B': /* Pressed arrow down */
					if (player.getPosY() < sizeY - 1)
						player.moveBottom();
					break ;
				case 'C': /* Pressed arrow right */
					if (player.getPosX() < sizeX - 1)
						player.moveRight();
					break ;
				case 'D': /* Pressed arrow left */
					if (player.getPosX() > 0)
						player.moveLeft();
					break ;
			}
			break ;
		case ' ':
			if (player.getShootState()) {
				game.add_unit(
					player.shoot()
				);
				player.setShootState(false);
			}
			break ;
	}
	while (getch() != ERR) ;
	return 0;
}
