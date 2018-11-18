/*
** core_move.c for tetris in /home/mael/PSU_2016_tetris
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Wed Mar 15 00:59:50 2017 mael drapier
** Last update Fri Mar 17 13:02:53 2017 mael drapier
*/

#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include "tetris.h"

int	try_left(t_game *game, t_tetriminos tetri)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (tetri.draw[game->turn][j] != NULL)
    {
      while (tetri.draw[game->turn][j][i] == ' ')
	i = i + 1;
      if (game->wndw[game->y + j + 1][game->x + i - 1] == '*')
	return (0);
      if (game->wndw[game->y + j + 1][game->x + i] == '|')
	return (0);
      i = 0;
      j = j + 1;
    }
  clear();
  return (1);
}

int	try_right(t_game *game, t_tetriminos tetri)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (tetri.draw[game->turn][j] != NULL)
    {
      while (tetri.draw[game->turn][j][i] != '\0')
	i = i + 1;
      if (game->wndw[game->y + j + 1][game->x + i + 2] == '*')
	return (0);
      if (game->wndw[game->y + j + 1][game->x + i + 1] == '|')
	return (0);
      i = 0;
      j = j + 1;
    }
  clear();
  return (1);
}

void	try_move(char *buf, t_debug *key, t_game *game, t_tetriminos tetri)
{
  if (my_strcmp(buf, key->left, 0) == 0)
    {
      if (try_left(game, tetri) == 1)
	game->x = game->x - 2;
    }
  else if (my_strcmp(buf, key->right, 0) == 0)
    {
      if (try_right(game, tetri) == 1)
	game->x = game->x + 2;
    }
}
