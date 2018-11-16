/*
** core_rotate.c for tetris in /home/mael/PSU_2016_tetris
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Wed Mar 15 17:44:10 2017 mael drapier
** Last update Sat Mar 18 17:11:35 2017 mael drapier
*/

#include <stdlib.h>
#include "tetris.h"

int	check_rotate_left(t_game *game, char **draw)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (draw[j] != NULL)
    {
      while (draw[j][i] != '\0')
      	{
	  if (draw[j][i] == '*')
	    {
	      if (game->wndw[game->y + j + 1][game->x + i + 1] == '*')
		return (0);
              if (game->wndw[game->y + j + 1][game->x + i] == '|')
		return (0);
	    }
	  i = i + 1;
	}
      i = 0;
      j = j + 1;
    }
  return (1);
}

int	check_rotate_more(t_game *game, t_tetriminos tetri, int turn)
{
  int	i;

  i = 0;
  while (i < tetri.height * 2)
    {
      if (check_rotate_left(game, tetri.draw[turn]) == 1)
	return (1);
      game->x = game->x - 2;
      i = i + 1;
    }
  game->x = game->x + (i * 2);
  return (0);
}

int	check_rotate(t_game *game, t_tetriminos tetri, int turn)
{
  int	width;
  int	diff;

  if (turn > 3)
    turn = 0;
  width = calc_size(tetri.draw[turn], 1);
  if (try_right(game, tetri) == 0)
    {
      if (width > tetri.width)
	{
	  diff = width - tetri.width;
	  game->x = game->x - diff;
          if (check_rotate_left(game, tetri.draw[turn]) == 0)
	    {
	      game->x = game->x + diff;
	      return (0);
	    }
	  else
	    return (1);
	}
    }
  if (try_left(game, tetri) == 1)
    return (check_rotate_more(game, tetri, turn));
  else
    return (1);
}

t_tetriminos	try_rotate(char *buf, t_debug *key,
			   t_game *game, t_tetriminos tetri)
{
  if (my_strcmp(buf, key->turn, 0) == 0)
    {
      if (check_rotate(game, tetri, game->turn + 1) == 1)
	{
	  game->turn = game->turn + 1;
	  if (game->turn > 3)
	    game->turn = 0;
	  tetri.width = calc_size(tetri.draw[game->turn], 1);
	  tetri.height = calc_size(tetri.draw[game->turn], 2);
	}
    }
  return (tetri);
}
