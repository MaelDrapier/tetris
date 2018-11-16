/*
** rotate_tetriminos.c for tetris in /home/mael/PSU_2016_tetris
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Wed Mar 15 14:37:22 2017 mael drapier
** Last update Wed Mar 15 17:23:35 2017 mael drapier
*/

#include <stdlib.h>
#include "tetris.h"

char	*remove_spaces(char *line)
{
  int	i;

  i = 0;
  while (line[i] != '\0')
    {
      if (check_end_line(line, i) == 1)
	{
	  line[i] = '\0';
	  return (line);
	}
      i = i + 1;
    }
  return (line);
}

char	*rotate_line(char *line, char **draw, int j, int height)
{
  int	i;
  int	y;

  i = 0;
  y = height - 1;
  while (y >= 0)
    {
      if (my_strlen(draw[y]) < j + 1)
	line[i] = ' ';
      else
	line[i] = draw[y][j];
      i = i + 1;
      y = y - 1;
    }
  line = remove_spaces(line);
  return (line);
}

char	**rotate_left(char **left, char **draw, int width, int height)
{
  int	j;

  j = 0;
  left = my_uber_malloc(sizeof(char *) * (width + 1));
  left[0] = my_uber_malloc(sizeof(char) * (height + 1));
  while (j < width)
    {
      left[j] = rotate_line(left[j], draw, j, height);
      j = j + 1;
      left[j] = my_uber_malloc(sizeof(char) * (height + 1));
    }
  left[j] = NULL;
  return (left);
}

int	calc_size(char **draw, int nb)
{
  int	i;
  int	max;

  i = 0;
  max = 0;
  while (draw[i] != NULL)
    {
      if (my_strlen(draw[i]) > max)
	max = my_strlen(draw[i]);
      i = i + 1;
    }
  if (nb == 1)
    return (max);
  else
    return (i);
}

t_tetriminos	rotate_tetriminos(t_tetriminos tetri)
{
  int		width;
  int		height;

  width = tetri.width;
  height = tetri.height;
  tetri.draw[1] = rotate_left(tetri.draw[1], tetri.draw[0], width, height);
  width = calc_size(tetri.draw[1], 1);
  height = calc_size(tetri.draw[1], 2);
  tetri.draw[2] = rotate_left(tetri.draw[2], tetri.draw[1], width, height);
  tetri.draw[1] = enlarge_others(tetri.draw[1], width);
  width = calc_size(tetri.draw[2], 1);
  height = calc_size(tetri.draw[2], 2);
  tetri.draw[3] = rotate_left(tetri.draw[3], tetri.draw[2], width, height);
  tetri.draw[2] = enlarge_others(tetri.draw[2], width);
  width = calc_size(tetri.draw[3], 1);
  tetri.draw[3] = enlarge_others(tetri.draw[3], width);
  return (tetri);
}
