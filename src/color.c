/*
** color.c for tetris in /home/mael/TETRIS_TMP
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Wed Mar 15 18:26:39 2017 mael drapier
** Last update Wed Mar 22 14:54:51 2017 mael drapier
*/

#include <ncurses.h>

void	init_colors()
{
  start_color();
  init_color(COLOR_BLACK, 0, 0, 0);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);
  init_pair(8, COLOR_YELLOW, COLOR_BLUE);  
}
