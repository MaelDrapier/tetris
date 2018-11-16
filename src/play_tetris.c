/*
** play_tetris.c for tetris in /home/mael/PSU_2016_tetris
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Tue Mar 14 16:08:22 2017 mael drapier
** Last update Wed Mar 22 14:29:23 2017 mael drapier
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include "tetris.h"

void	display_tetrimino(t_game *game, t_tetriminos *tetris)
{
  int	y;
  int	x;
  int	j;

  j = 0;
  y = (LINES / 2) - (game->height / 2) + game->y + 1;
  x = (COLS / 2) - (game->width / 2) + game->x + 1;
  attron(COLOR_PAIR(tetris[game->nb].color));
  while (tetris[game->nb].draw[game->turn][j] != NULL)
    {
      if (COLS < game->width + 1 || LINES < game->height + 1)
	mvprintw(LINES / 2, COLS / 2 - 10, "enlarge the terminal");
      else
	mvprintw(y, x, tetris[game->nb].draw[game->turn][j]);
      y = y + 1;
      j = j + 1;
    }
  attroff(COLOR_PAIR(tetris[game->nb].color));
}

void	display_game(t_game *game)
{
  int	j;
  int	x;
  int	y;

  j = 0;
  while (j < game->height)
    {
      y = ((LINES / 2) + j) - (game->height / 2);
      x = COLS / 2;
      if (COLS < game->width + 1 || LINES < game->height + 1)
	mvprintw(LINES / 2, x - 10, "enlarge the terminal");
      else
	mvprintw(y, x - game->width / 2, game->wndw[j]);
      j = j + 1;
    }
}

void	do_pause(char *buf, t_debug *key, t_game *game, t_tetriminos *tetris)
{
  int	y;
  int	x;

  buf[0] = 'a';
  while (my_strcmp(buf, key->pause, 0) != 0)
    {
      y = LINES / 2;
      x = COLS / 2;
      clear();
      display_game(game);
      display_tetrimino(game, tetris);
      display_others(game, key->info.next, tetris);
      attron(COLOR_PAIR(6));
      if (COLS < game->width + 1 || LINES < game->height + 1)
	mvprintw(y, x - 10, "enlarge the terminal");
      else
	mvprintw(y, x - 3, "=PAUSE=");
      attroff(COLOR_PAIR(6));
      refresh();
      read(0, buf, 20);
    }
}

int	game_loop(t_debug *key, t_tetriminos *tetris, t_game *game)
{
  char	*buf;

  if ((buf = my_uber_malloc(sizeof(char) * 20)) == NULL)
    exit(RETURN_FAIL);
  read(0, buf, 20);
  tetris[game->nb] = try_rotate(buf, key, game, tetris[game->nb]);
  move_tetris(game, tetris);
  display_game(game);
  display_tetrimino(game, tetris);
  display_others(game, key->info.next, tetris);
  refresh();
  game->delay = (int) 5000 - (game->level * 300);
  if (my_strcmp(buf, key->quit, 0) == 0)
    return (0);
  else if (my_strcmp(buf, key->drop, 0) == 0)
    game->delay = 200;
  else if (my_strcmp(buf, key->pause, 0) == 0)
    do_pause(buf, key, game, tetris);
  try_move(buf, key, game, tetris[game->nb]);
  remove_full(game);
  free (buf);
  if (lost(game) == 0)
    return (-1);
  else
    return (1);
}

void		play_tetris(t_tetriminos *tetris, t_debug *key, int nb_tetri)
{
  t_game	game;
  int		res;

  initscr();
  init_colors();
  keypad(stdscr, TRUE);
  raw();
  noecho();
  curs_set(FALSE);
  set_canonic(2);
  set_game(&game, key, tetris, nb_tetri);
  if ((game.wndw = create_wndw(game.wndw, key->info)) == NULL)
    exit(RETURN_FAIL);
  game.up_map = create_up_map(game.up_map, key->info);
  while ((res = game_loop(key, tetris, &game)) == 1)
    clear();
  if (res == -1)
    {
      attron(COLOR_PAIR(1));
      mvprintw((LINES / 2), ((COLS / 2) - 4), "Game Over");
      attroff(COLOR_PAIR(1));
      refresh();
      sleep(3);
    }
  endwin();
}
