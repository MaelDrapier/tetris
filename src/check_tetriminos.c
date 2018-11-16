/*
** check_tetrimino.c for tetris in /home/mael/TETRIS_TMP
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Tue Feb 28 16:09:27 2017 mael drapier
** Last update Wed Mar 15 17:20:37 2017 mael drapier
*/

#include <stdlib.h>
#include "tetris.h"

int	check_height(t_tetriminos tetri)
{
  int	j;

  j = 0;
  while (tetri.draw[0][j] != NULL)
    {
      j = j + 1;
    }
  if (j != tetri.height)
    return (RETURN_FAIL);
  return (RETURN_SUCCESS);
}

int	count_a_line(char *line)
{
  int	i;

  i = 0;
  while (line[i] != '\0')
    {
      if (check_end_line(line, i) == 1)
	return (i);
      i = i + 1;
    }
  return (i);
}

int	check_width(t_tetriminos tetri)
{
  int	j;
  int	max;

  j = 0;
  max = 0;
  while (tetri.draw[0][j] != NULL)
    {
      if (count_a_line(tetri.draw[0][j]) > max)
	max = count_a_line(tetri.draw[0][j]);
      if (count_a_line(tetri.draw[0][j]) == -1)
	return (RETURN_FAIL);
      j = j + 1;
    }
  if (max != tetri.width)
    return (RETURN_FAIL);
  return (RETURN_SUCCESS);
}

t_tetriminos	*check_tetriminos(t_tetriminos *tetris, int nb_tetri)
{
  int	i;

  i = 0;
  while (i < nb_tetri)
    {
      if (check_height(tetris[i]) == RETURN_FAIL)
	tetris[i].width = 0;
      if (check_width(tetris[i]) == RETURN_FAIL)
	tetris[i].width = 0;
      if (tetris[i].height == 0 || tetris[i].color == 0)
	tetris[i].width = 0;
      i = i + 1;
    }
  return (tetris);
}
