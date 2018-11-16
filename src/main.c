/*
** main.c for tetris in /home/mael/PSU_2016_tetris
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Mon Feb 27 10:15:18 2017 mael drapier
** Last update Sun Mar 19 20:49:54 2017 mael drapier
*/

#include <term.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "tetris.h"

void		param_init(t_debug *key, char **av, int ac)
{
  key->info.debug = 0;
  option_help(av, key, ac);
  if (key->helper == 0)
    {
      option_debug(av, key, ac);
      option_level(av, key, ac);
      option_next(av, key, ac);
      options_left(av, key, ac);
      options_right(av, key, ac);
      options_turn(av, key, ac);
      options_drop(av, key, ac);
      options_quit(av, key, ac);
      options_pause(av, key, ac);
      option_size(av, key, ac);
    }
}

void			set_canonic(int i)
{
  static struct termios	oldT;
  static struct termios	newT;

  if (i == 1)
    {
      ioctl(0, TCGETS, &oldT);
      ioctl(0, TCGETS, &newT);
      newT.c_lflag &= ~ECHO;
      newT.c_lflag &= ~ICANON;
      newT.c_cc[VMIN] = 1;
      newT.c_cc[VTIME] = 0;
      ioctl(0, TCSETS, &newT);
    }
  else if (i == 2)
    {
      newT.c_cc[VMIN] = 0;
      newT.c_cc[VTIME] = 0;
      ioctl(0, TCSETS, &newT);
    }
  else
    ioctl(0, TCSETS, &oldT);
}

int		launch_game(t_debug *key)
{
  int		nb_tetri;
  t_tetriminos	*tetris;
  char		*buf;

  nb_tetri = nb_of_tetriminos();
  if ((tetris = my_uber_malloc(sizeof(t_tetriminos) * (nb_tetri))) == NULL)
    return (RETURN_FAIL);
  if ((buf = malloc(sizeof(char) * 10)) == NULL)
    return (RETURN_FAIL);
  tetris = get_tetriminos(tetris);
  tetris = my_sort_tetris(tetris, nb_tetri);
  tetris = check_tetriminos(tetris, nb_tetri);
  set_canonic(1);
  if (key->helper == 0 && key->info.debug == 1)
    {
      show_debug(key, tetris, nb_tetri);
      read(0, buf, 20);
      free(buf);
    }
  set_canonic(0);
  if (key->helper == 1)
    return (RETURN_SUCCESS);
  tetris = enlarge_tetriminos(tetris, nb_tetri);
  play_tetris(tetris, key, nb_tetri);
  return (RETURN_SUCCESS);
}

int		main(int ac, char **av)
{
  int		err;
  t_debug	key;

  verif_params(av, ac);
  setupterm(NULL, 0, &err);
  param_init(&key, av, ac);
  if (launch_game(&key) == RETURN_FAIL)
    return (RETURN_FAIL);
  return (RETURN_SUCCESS);
}
