/*
** show_debug.c for tetris in /home/mael/PSU_2016_tetris/tmp_etienne
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Wed Mar  1 13:44:33 2017 mael drapier
** Last update Fri Mar 17 13:15:23 2017 mael drapier
*/

#include <term.h>
#include <ncurses.h>
#include <stdlib.h>
#include <tetris.h>

void	show_tetri_stats(t_tetriminos tetri)
{
  my_putstr(1, " : Size ");
  my_putnbr(tetri.width);
  my_putstr(1, "*");
  my_putnbr(tetri.height);
  my_putstr(1, " : Color ");
  my_putnbr(tetri.color);
  my_putstr(1, " :\n");
  my_showtab(tetri.draw[0]);
}

void	debug_tetriminos(t_tetriminos *tetris, int nb_tetri)
{
  int	i;

  i = 0;
  my_putstr(1, "\nTetriminos : ");
  my_putnbr(nb_tetri);
  my_putstr(1, "\n");
  while (i < nb_tetri)
    {
      my_putstr(1, "Tetriminos : Name ");
      my_putstr(1, tetris[i].name);
      if (tetris[i].width == 0)
	my_putstr(1, ": Error\n");
      else
	show_tetri_stats(tetris[i]);
      i = i + 1;
    }
}

void	show_more_debug(t_debug *key)
{
  my_putstr(1, "\nNext : ");
  if (key->info.next == 0)
    my_putstr(1, "Yes\n");
  else
    my_putstr(1, "No\n");
  my_putstr(1, "Level : ");
  my_putnbr(key->info.level);
  my_putstr(1, "\nSize : ");
  my_putnbr(key->info.row);
  my_putstr(1, "*");
  my_putnbr(key->info.col);
}

void	show_debug(t_debug *key, t_tetriminos *tetris, int nb_tetri)
{
  my_putstr(1, "*** DEBUG MODE ***\nKey Left : ");
  print_unseen(1, key->left);
  my_putstr(1, "\nKey Right : ");
  print_unseen(1, key->right);
  my_putstr(1, "\nKey Turn : ");
  print_unseen(1, key->turn);
  my_putstr(1, "\nKey Drop : ");
  print_unseen(1, key->drop);
  my_putstr(1, "\nKey Quit : ");
  print_unseen(1, key->quit);
  my_putstr(1, "\nKey Pause : ");
  print_unseen(1, key->pause);
  show_more_debug(key);
  debug_tetriminos(tetris, nb_tetri);
  my_putstr(1, "Press any key to start Tetris");
}
