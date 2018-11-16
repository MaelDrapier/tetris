/*
** verfif_params.c for tetris in /home/spiki/delivery/B2/PSU/PSU_2016_tetris/src/
**
** Made by etienne.filliat
** Login   <etienne.filliat@epitech.eu>
**
** Started on  Fri Mar 17 11:13:36 2017 etienne.filliat
** Last update Fri Mar 17 13:26:03 2017 etienne.filliat
*/

#include <stdlib.h>
#include "tetris.h"

int		verif_short(char *str)
{
  if (my_strcmp(str, SF_H, 0) == 0 || my_strcmp(str, SF_L, 0) == 0
      || my_strcmp(str, SF_KL, 0) == 0 || my_strcmp(str, SF_KR, 0) == 0
      || my_strcmp(str, SF_KT, 0) == 0 || my_strcmp(str, SF_KD, 0) == 0
      || my_strcmp(str, SF_KQ, 0) == 0 || my_strcmp(str, SF_KP, 0) == 0
      || my_strcmp(str, SF_W, 0) == 0 || my_strcmp(str, SF_D, 0) == 0)
    return (0);
  else
    return (1);
}

int		verif_long(char *str)
{
  if (my_strcmp_debug(str, LF_H, my_strlen(LF_H)) == 0 ||
      my_strcmp_debug(str, LF_L, my_strlen(LF_L)) == 0 ||
      my_strcmp_debug(str, LF_KL, my_strlen(LF_KL)) == 0 ||
      my_strcmp_debug(str, LF_KR, my_strlen(LF_KR)) == 0 ||
      my_strcmp_debug(str, LF_KT, my_strlen(LF_KT)) == 0 ||
      my_strcmp_debug(str, LF_KD, my_strlen(LF_KD)) == 0 ||
      my_strcmp_debug(str, LF_KQ, my_strlen(LF_KQ)) == 0 ||
      my_strcmp_debug(str, LF_KP, my_strlen(LF_KP)) == 0 ||
      my_strcmp_debug(str, LF_W, my_strlen(LF_W)) == 0 ||
      my_strcmp_debug(str, LF_D, my_strlen(LF_D)) == 0 ||
      my_strcmp_debug(str, LF_MS, my_strlen(LF_MS)) == 0)
    return (0);
  else
    return (1);
}

void		disp_err(char *flag)
{
  my_putstr(1, RED_TEXT("Bad flag"));
  my_putstr(1, ": ");
  my_putstr(1, flag);
  my_putchar('\n');
  exit(84);
}

void		verif_params(char **av, int ac)
{
  int		x;

  x = 1;
  while (x < ac)
    {
      if (av[x][0] == '-' && av[x][1] != '-')
	{
	  if (verif_short(av[x]) == 1)
	    disp_err(av[x]);
	  x = x + 2;
	}
      else if (av[x][0] == '-' && av[x][1] == '-')
	{
	  if (verif_long(av[x]) == 1)
	    disp_err(av[x]);
	  x++;
	}
      else
	disp_err(av[x]);
    }
}
