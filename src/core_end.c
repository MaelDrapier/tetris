/*
** core_end.c for tetris in /home/mael/TETRIS_TMP
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Wed Mar 15 18:26:39 2017 mael drapier
** Last update Thu Mar 16 17:28:14 2017 mael drapier
*/

#include "struct.h"

int		lost(t_game *game)
{
  int		x;
  int		count;

  x = 1;
  count = 0;
  while (game->wndw[9][x] != '\0')
    {
      if (game->wndw[9][x] == '*')
	count++;
      x++;
    }
  if (count != 0)
    return (0);
  else
    return (1);
}
