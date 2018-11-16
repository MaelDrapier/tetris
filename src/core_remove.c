/*
** core_remove.c for tetris in /home/spiki/delivery/B2/PSU/lul/PSU_2016_tetris/src/
**
** Made by etienne.filliat
** Login   <etienne.filliat@epitech.eu>
**
** Started on  Wed Mar 15 12:29:04 2017 etienne.filliat
** Last update Mon Mar 20 17:29:16 2017 mael drapier
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include "tetris.h"

void		display_line(t_game *game, char *line, int j)
{
  int	x;
  int	y;

  y = ((LINES / 2) + j) - (game->height / 2);
  x = COLS / 2;
  if (COLS < game->width + 1 || LINES < game->height + 1)
    mvprintw(LINES / 2, x - 10, "enlarge the terminal");
  else
    mvprintw(y, x - game->width / 2, line);
  refresh();
  usleep(500000);
  game->score = game->score + 10;
  if (game->score % LEVEL_SCORE == 0)
    game->level = game->level + 1;
  if (game->level > 16)
    game->level = 16;
  game->delay = (int) 5000 - (game->level * 300);
}

void		down_them(char **map, int y)
{
  while ((y - 1) >= 9)
    {
      my_strcpy(map[y], map[y - 1]);
      y--;
    }
}

void		replace_full(int count, int y, t_game *game)
{
  int		x;

  x = 1;
  if (count == (game->width - 1) / 2)
    {
      while (x < (game->width - 1))
	{
	  game->wndw[y][x] = ' ';
	  x++;
	}
      display_line(game, game->wndw[y], y);
      down_them(game->wndw, y);
    }
}

void		remove_full(t_game *game)
{
  int		x;
  int		y;
  int		count;

  x = 1;
  y = 1;
  count = 0;
  while (game->wndw[y] != '\0')
    {
      while (game->wndw[y][x] != '\0')
	{
	  if (game->wndw[y][x] == '*')
	    count++;
	  x++;
	}
      replace_full(count, y, game);
      count = 0;
      x = 1;
      y++;
    }
}
