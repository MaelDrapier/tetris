/*
** options.c for tetris in /home/mael/PSU_2016_tetris
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Mon Feb 27 11:08:45 2017 mael drapier
** Last update Tue Mar 14 13:31:42 2017 etienne.filliat
*/

#include "tetris.h"

void	show_full_help()
{
  my_putstr(1, HELP_KD);
  my_putstr(1, DES_KD);
  my_putstr(1, HELP_KQ);
  my_putstr(1, DES_KQ);
  my_putstr(1, HELP_KP);
  my_putstr(1, DES_KP);
  my_putstr(1, HELP_MAP);
  my_putstr(1, DES_MAP);
  my_putstr(1, HELP_W);
  my_putstr(1, DES_W);
  my_putstr(1, HELP_D);
  my_putstr(1, DES_D);
}

void	option_help(char **av, t_debug *key, int ac)
{
  if (search_flag(SF_H, av, ac) != -1 || search_flag(LF_H, av, ac) != -1)
    {
      key->helper = 1;
      my_putstr(1, USAGE_1);
      my_putstr(1, av[0]);
      my_putstr(1, USAGE_2);
      my_putstr(1, USAGE_3);
      my_putstr(1, HELP_H);
      my_putstr(1, DES_H);
      my_putstr(1, HELP_L);
      my_putstr(1, DES_L);
      my_putstr(1, HELP_KL);
      my_putstr(1, DES_KL);
      my_putstr(1, HELP_KR);
      my_putstr(1, DES_KR);
      my_putstr(1, HELP_KT);
      my_putstr(1, DES_KT1);
      my_putstr(1, DES_KT2);
      show_full_help();
    }
  else
    key->helper = 0;
}
