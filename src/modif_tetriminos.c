/*
** modif_tetriminos.c for tetris in /home/mael/PSU_2016_tetris
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Wed Mar 15 13:23:27 2017 mael drapier
** Last update Fri Mar 17 14:49:53 2017 etienne.filliat
*/

#include <stdlib.h>
#include "tetris.h"

char	*enlarge_line(char *line, int width)
{
  char	*tmp;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((tmp = my_uber_malloc(sizeof(char) * (width + 1))) == NULL)
    exit(84);
  tmp = my_strcpy(tmp, line);
  free(line);
  if ((line = my_uber_malloc(sizeof(char) * (width * 2))) == NULL)
    exit(84);
  while (i < width)
    {
      line[j] = tmp[i];
      if (j % 2 != 0 && check_end_line(tmp, i) == 0)
	line[j] = ' ';
      else
	i = i + 1;
      j = j + 1;
    }
  remove_spaces(line);
  free(tmp);
  return (line);
}

t_tetriminos	enlarge_this(t_tetriminos tetri)
{
  int		j;

  j = 0;
  tetri.width = (tetri.width * 2) - 1;
  while (tetri.draw[0][j] != NULL)
    {
      tetri.draw[0][j] = enlarge_line(tetri.draw[0][j], tetri.width);
      j = j + 1;
    }
  return (tetri);
}

char	**enlarge_others(char **draw, int width)
{
  int		j;

  j = 0;
  while (draw[j] != NULL)
    {
      draw[j] = enlarge_line(draw[j], width);
      j = j + 1;
    }
  return (draw);
}

t_tetriminos	*enlarge_tetriminos(t_tetriminos *tetris, int nb_tetri)
{
  int		j;

  j = 0;
  while (j < nb_tetri)
    {
      if (tetris[j].width != 0)
	{
	  tetris[j] = rotate_tetriminos(tetris[j]);
	  tetris[j] = enlarge_this(tetris[j]);
	}
      j = j + 1;
    }
  return (tetris);
}
