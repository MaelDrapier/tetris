/*
** useful.c for tetris in /home/mael/TETRIS_TMP
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Tue Feb 28 10:20:45 2017 mael drapier
** Last update Fri Mar 17 13:13:00 2017 mael drapier
*/

#include <stdlib.h>
#include "tetris.h"

void		print_unseen(int fd, char *str)
{
  int		x;

  x = 0;
  while (str[x] != '\0')
    {
      if (str[x] == 27)
	my_putstr(fd, ESC);
      else if (str[x] == ' ')
	my_putstr(fd, SPACE);
      else
	my_putchar(str[x]);
      x++;
    }
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] && str[i] != -1)
    i = i + 1;
  return (i);
}

int	my_getnbr(char *str)
{
  int	i;
  int	res;

  i = 0;
  res = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (res);
      res = res * 10;
      res = res + str[i] - 48;
      i = i + 1;
    }
  return (res);
}

int	increase_k(char *str, int k)
{
  while (str[k] == ' ' && str[k] != '\0')
    k = k + 1;
  return (k);
}

char	**my_str_to_wordtab(char **tab, char *str, int i, int j)
{
  int	k;

  k = 0;
  while (k < 4)
    {
      if ((tab[k] = my_uber_malloc(sizeof(char) * my_strlen(str))) == NULL)
	return (NULL);
      k = k + 1;
    }
  k = 0;
  k = increase_k(str, k);
  while (str[k] != '\0')
    {
      if (str[k] == ' ')
	{
	  j = j + 1;
	  i = 0;
	  k = increase_k(str, k);
	}
      tab[j][i] = str[k];
      i = i + 1;
      k = k + 1;
    }
  tab[3] = NULL;
  return (tab);
}
