/*
** core_print.c for tetris in /home/mael/PSU_2016_tetris
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Thu Mar 16 18:06:12 2017 mael drapier
** Last update Wed Mar 22 17:03:32 2017 mael drapier
*/

#include <ncurses.h>
#include "tetris.h"

void	display_title(t_game *game)
{
  int	x;
  int	y;

  y = LINES / 2 - (game->height / 2) + 2;
  x = (COLS / 2) - 18;
  attron(COLOR_PAIR(6));
  mvprintw(y, x, "    ##### ##### ##### ####    #    ####");
  mvprintw(y + 1, x, "     #   #       #   #   #   #   #");
  mvprintw(y + 2, x, "    #   ###     #   ####    #    ####");
  mvprintw(y + 3, x, "   #   #       #   #   #   #        #");
  mvprintw(y + 4, x, "  #   #####   #   #   #   #    ####");
  attroff(COLOR_PAIR(6));
}

void	show_more(t_game *game, int y, int x)
{
  y = y + 7;
  mvprintw(y, x, "----------");
  y = y + 1;
  mvprintw(y, x, "Score: %d", game->score);
  mvprintw(y + 2, x, "Level: %d", game->level);
  y = y + 3;
  mvprintw(y, x, "----------");
}

void	show_infos(t_game *game, int nb, char **draw, int color)
{
  int	y;
  int	x;
  int	j;

  j = 0;
  y = LINES / 2 - (game->height / 2) + 11;
  x = (COLS / 2) + (game->width / 2) + 2;
  if (nb == 0)
    {
      mvprintw(y, x, "Next:");
      y = y + 2;
      attron(COLOR_PAIR(color));
      while (draw[j] != NULL)
	{
	  mvprintw(y + j, x, "%s", draw[j]);
	  j = j + 1;
	}
      attroff(COLOR_PAIR(color));
    }
  show_more(game, y, x);
}

void	display_others(t_game *game, int nb, t_tetriminos *tetris)
{
  int	x;
  int	y;
  int	j;

  y = (LINES / 2) - (game->height / 2);
  x = (COLS / 2) - (game->width / 2);
  j = 0;
  while (game->up_map[j] != NULL)
    {
      if (COLS < game->width + 1 || LINES < game->height + 1)
	mvprintw(LINES / 2, COLS / 2 - 10, "enlarge the terminal");
      else
	mvprintw(y, x, game->up_map[j]);
      y = y + 1;
      j = j + 1;
    }
  show_infos(game, nb, tetris[game->next].draw[0], tetris[game->next].color);
  display_title(game);
}
