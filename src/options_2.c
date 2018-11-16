/*
** option_2.c for tetris in /home/spiki/delivery/B2/PSU/PSU_2016_tetris/tmp_mael/src/
**
** Made by etienne.filliat
** Login   <etienne.filliat@epitech.eu>
**
** Started on  Wed Mar  1 12:55:18 2017 etienne.filliat
** Last update Fri Mar 17 11:49:53 2017 etienne.filliat
*/

#include "tetris.h"

void	option_debug(char **av, t_debug *key, int ac)
{
  if (search_flag(SF_D, av, ac) != -1 || search_flag(LF_D, av, ac) != -1)
    {
      if (key->info.debug != 1)
	key->info.debug = 1;
    }
  else
    key->info.debug = 0;
}

void	option_level(char **av, t_debug *key, int ac)
{
  int	x;
  int	y;

  if ((x = search_flag(SF_L, av, ac)) != -1)
    key->info.level = my_getnbr(get_short_flag(av, ac, x + 1));
  else if ((y = search_flag(LF_L, av, ac)) != -1)
    key->info.level = my_getnbr_in_char(av[y]);
  else
    key->info.level = 1;
}

void	option_next(char **av, t_debug *key, int ac)
{
  if (search_flag(SF_W, av, ac) != -1 || search_flag(LF_W, av, ac) != -1)
    {
      if (key->info.next != 1)
	key->info.next = 1;
    }
  else
    key->info.next = 0;
}

void	options_pause(char **av, t_debug *key, int ac)
{
  int	x;
  int	y;

  if ((x = search_flag(SF_KP, av, ac)) != -1)
    key->pause = get_short_flag(av, ac, x + 1);
  else if ((y = search_flag(LF_KP, av, ac)) != -1)
    key->pause = my_getstr(av[y], LF_KP);
  else
    key->pause = " ";
}

void	option_size(char **av, t_debug *key, int ac)
{
  int	x;
  int	y;
  char	*p;

  y = 0;
  key->info.col = 10;
  key->info.row = 20;
  if ((x = search_flag(LF_MS, av, ac)) != -1)
    {
      p = av[x];
      while ((av[x][y] < '0' || av[x][y] > '9') && av[x][y] != '\0')
	y++;
      if (av[x][y] != '\0')
	key->info.row = my_getnbr(p + y);
      while (av[x][y] != ',' && av[x][y] != '\0')
	y++;
      if (av[x][y] != '\0')
	key->info.col = my_getnbr(p + (y + 1));
    }
}
