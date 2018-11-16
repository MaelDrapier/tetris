/*
** tetriminos2.c for tetris in /home/mael/TETRIS_TMP
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Tue Feb 28 11:45:39 2017 mael drapier
** Last update Wed Mar 15 17:19:23 2017 mael drapier
*/

#include <stdlib.h>
#include "tetris.h"
#include "gnl.h"

int	check_end_line(char *str, int i)
{
  while (str[i] != '\0')
    {
      if (str[i] == '*')
	return (0);
      i = i + 1;
    }
  return (1);
}

char	*fill_line(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      if (check_end_line(src, i) == 1)
	{
	  dest[i] = '\0';
	  return (dest);
	}
      i = i + 1;
    }
  return (dest);
}

char	*fill_good_line(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}

t_tetriminos	fill_tetri(t_tetriminos tetri, int fd)
{
  char		*s;
  int		j;

  j = 0;
  tetri.draw = malloc(sizeof(char **) * 5);
  if ((tetri.draw[0] = my_uber_malloc(sizeof(char *) * (tetri.height + 1)))
      == NULL)
    return (tetri);
  while (j < tetri.height && (s = get_next_line(fd)) != NULL)
    {
      if ((tetri.draw[0][j] = my_uber_malloc(sizeof(char) * (tetri.width + 1)))
	  == NULL)
	return (tetri);
      tetri.draw[0][j] = fill_line(tetri.draw[0][j], s);
      j = j + 1;
    }
  tetri.draw[0][j] = NULL;
  tetri.draw[4] = NULL;
  while (get_next_line(fd) != NULL);
  return (tetri);
}

t_tetriminos	*my_sort_tetris(t_tetriminos *tetris, int nb_tetri)
{
  int		i;
  int		j;
  t_tetriminos	tmp;

  i = 0;
  j = 0;
  while (j < nb_tetri)
    {
      while (i < nb_tetri - 1)
	{
	  if (my_strcmp(tetris[i].name, tetris[i + 1].name, 0) > 0)
	    {
	      tmp = tetris[i];
	      tetris[i] = tetris[i + 1];
	      tetris[i + 1] = tmp;
	    }
	  i = i + 1;
	}
      i = 0;
      j = j + 1;
    }
  return (tetris);
}
