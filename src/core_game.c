/*
** core_game.c for tetris in /home/mael/PSU_2016_tetris
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Tue Mar 14 22:56:36 2017 mael drapier
** Last update Wed Mar 22 14:32:27 2017 mael drapier
*/

#include <stdlib.h>
#include <ncurses.h>
#include "tetris.h"

int	get_random(int	max_tetri, t_tetriminos *tetris)
{
  int	nb;

  nb = rand() % max_tetri;
  while (tetris[nb].width == 0)
    nb = rand() % max_tetri;
  return (nb);
}

void	inc_tetri(t_game *game, t_tetriminos *tetris)
{
  game->inc++;
  if (game->inc > game->delay)
    {
      clear();
      game->inc = 0;
      if (game->locked != 1)
	game->y++;
      if (game->locked == 1)
	game->locked = 2;
    }
  game->delay = (int) 5000 - (game->level * 300);
  if (game->y > game->height - tetris[game->nb].height - 2)
    game->y = 0;
}

int	check_lock(t_game *game, t_tetriminos tetri)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (tetri.draw[game->turn][j] != NULL)
    {
      while (tetri.draw[game->turn][j][i] != '\0')
	{
	  if (tetri.draw[game->turn][j][i] == '*')
	    {
	      if (game->wndw[game->y + j + 2][game->x + i + 1] == '=')
		{
		  if (game->y + j + 2 != 8)
		    return (1);
		}
	      if (game->wndw[game->y + j + 2][game->x + i + 1] == '*')
		return (1);
	    }
	  i = i + 1;
	}
      i = 0;
      j = j + 1;
    }
  return (0);
}

void	print_tetri(t_game *game, t_tetriminos tetri)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (tetri.draw[game->turn][j] != NULL)
    {
      while (tetri.draw[game->turn][j][i] != '\0')
	{
	  if (tetri.draw[game->turn][j][i] == '*')
	    game->wndw[game->y + j + 1][game->x + i + 1] = '*';
	  i = i + 1;
	}
      i = 0;
      j = j + 1;
    }
}

void	move_tetris(t_game *game, t_tetriminos *tetris)
{
  inc_tetri(game, tetris);
  if (check_lock(game, tetris[game->nb]) == 1 && game->locked == 0)
    game->locked = 1;
  if (check_lock(game, tetris[game->nb]) == 0)
    game->locked = 0;
  if (game->locked == 2)
    {
      game->locked = 0;
      print_tetri(game, tetris[game->nb]);
      game->nb = game->next;
      game->next = get_random(game->nb_tetri, tetris);
      game->turn = 0;
      tetris[game->nb].width = calc_size(tetris[game->nb].draw[0], 1);
      tetris[game->nb].height = calc_size(tetris[game->nb].draw[0], 2);
      game->y = 7 - tetris[game->nb].height;
      if (game->y < 0)
        game->y = 0;
      game->x = (game->width / 2) - (tetris[game->nb].width / 2);
      if (game->x % 2 != 0)
	game->x = game->x - 1;
    }
}
