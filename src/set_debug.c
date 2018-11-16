/*
** set_debug.c for tetris in /home/spiki/delivery/B2/PSU/PSU_2016_tetris/src/
**
** Made by etienne.filliat
** Login   <etienne.filliat@epitech.eu>
**
** Started on  Tue Feb 28 11:09:26 2017 etienne.filliat
** Last update Fri Mar 17 11:54:43 2017 etienne.filliat
*/

#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"

char		*get_short_flag(char **av, int ac, int x)
{
  if (x >= ac || av[x] == NULL || av[x][0] == '-')
    {
      my_putstr(2, RED_TEXT("Bad use of flag: "));
      my_putstr(2, av[x - 1]);
      my_putstr(2, "\n");
      exit(RETURN_FAIL);
    }
  else
    return (av[x]);

}

int		search_flag(char *flag, char **av, int ac)
{
  int		x;

  x = 1;
  if (av[x] == NULL)
    return (-1);
  while (my_strcmp_debug(flag, av[x], my_strlen(flag)) != 0 && x < ac)
    {
      x++;
      if (av[x] == NULL)
	return (-1);
    }
  return (x);
}

int		my_getnbr_in_char(char *av)
{
  int		x;
  int		res;

  x = 0;
  res = 0;
  while (av[x] < '0' || av[x] > '9')
    x++;
  while (av[x] >= '0' && av[x] <= '9' && av[x] != '\0')
    {
      res = res * 10;
      res = res + (av[x] - 48);
      x++;
    }
  return (res);
}

char		my_getchar(char *av, char *flag)
{
  int		x;

  x = 0;
  while (av[x] == flag[x] && av[x] != '\0' && flag[x] != '\0')
    x++;
  return (av[x + 1]);
}

char		*my_getstr(char *av, char *flag)
{
  int		x;
  int		y;
  char		*tmp;

  x = 0;
  y = 0;
  if ((tmp = my_uber_malloc(sizeof(char) * my_strlen(av))) == NULL)
    return (NULL);
  while (av[x] == flag[x] && av[x] != '\0' && flag[x] != '\0')
    x++;
  x++;
  while (av[x] != '\0')
    {
      tmp[y] = av[x];
      x++;
      y++;
    }
  return (tmp);
}
