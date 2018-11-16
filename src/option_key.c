/*
** option_key.c for tetris in /home/spiki/delivery/B2/PSU/PSU_2016_tetris/tmp_mael/src/
**
** Made by etienne.filliat
** Login   <etienne.filliat@epitech.eu>
**
** Started on  Wed Mar  1 13:19:19 2017 etienne.filliat
** Last update Tue Mar 14 15:27:23 2017 etienne.filliat
*/

#include <term.h>
#include <stdlib.h>
#include "tetris.h"

void	options_left(char **av, t_debug *key, int ac)
{
  int	x;
  int	y;
  char	*def;

  if ((x = search_flag(SF_KL, av, ac)) != -1)
    key->left = get_short_flag(av, ac, x + 1);
  else if ((y = search_flag(LF_KL, av, ac)) != -1)
    key->left = my_getstr(av[y], LF_KL);
  else
    {
      if ((def = tigetstr("kcub1")) == 0)
	exit(RETURN_FAIL);
      if ((key->left = my_uber_malloc(sizeof(char) * my_strlen(def))) == NULL)
	exit(RETURN_FAIL);
      key->left = my_strcpy(key->left, def);
    }
}

void	options_right(char **av, t_debug *key, int ac)
{
  int	x;
  int	y;
  char	*def;

  if ((x = search_flag(SF_KR, av, ac)) != -1)
    key->right = get_short_flag(av, ac, x + 1);
  else if ((y = search_flag(LF_KR, av, ac)) != -1)
    key->right = my_getstr(av[y], LF_KR);
  else
    {
      if ((def = tigetstr("kcuf1")) == 0)
	exit(RETURN_FAIL);
      if ((key->right = my_uber_malloc(sizeof(char) * my_strlen(def))) == NULL)
	exit(RETURN_FAIL);
      key->right = my_strcpy(key->right, def);
    }
}

void	options_turn(char **av, t_debug *key, int ac)
{
  int	x;
  int	y;
  char	*def;

  if ((x = search_flag(SF_KT, av, ac)) != -1)
    key->turn = get_short_flag(av, ac, x + 1);
  else if ((y = search_flag(LF_KT, av, ac)) != -1)
    key->turn = my_getstr(av[y], LF_KT);
  else
    {
      if ((def = tigetstr("kcuu1")) == 0)
	exit(RETURN_FAIL);
      if ((key->turn = my_uber_malloc(sizeof(char) * my_strlen(def))) == NULL)
	exit(RETURN_FAIL);
      key->turn = my_strcpy(key->turn, def);
    }
}

void	options_drop(char **av, t_debug *key, int ac)
{
  int	x;
  int	y;
  char	*def;

  if ((x = search_flag(SF_KD, av, ac)) != -1)
    key->drop = get_short_flag(av, ac, x + 1);
  else if ((y = search_flag(LF_KD, av, ac)) != -1)
    key->drop = my_getstr(av[y], LF_KD);
  else
    {
      if ((def = tigetstr("kcud1")) == 0)
	exit(RETURN_FAIL);
      if ((key->drop = my_uber_malloc(sizeof(char) * my_strlen(def))) == NULL)
	exit(RETURN_FAIL);
      key->drop = my_strcpy(key->drop, def);
    }
}

void	options_quit(char **av, t_debug *key, int ac)
{
  int	x;
  int	y;

  if ((x = search_flag(SF_KQ, av, ac)) != -1)
    key->quit = get_short_flag(av, ac, x + 1);
  else if ((y = search_flag(LF_KQ, av, ac)) != -1)
    key->quit = my_getstr(av[y], LF_KQ);
  else
    key->quit = "q";
}
