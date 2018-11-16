/*
** init_game.c for tetris in /home/mael/PSU_2016_tetris
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Tue Mar 14 17:00:51 2017 mael drapier
** Last update Wed Mar 22 14:32:31 2017 mael drapier
*/

#include <stdlib.h>
#include <time.h>
#include "tetris.h"

void	set_game(t_game *game, t_debug *key,
		 t_tetriminos *tetris, int nb_tetri)
{
  srand(time(NULL));
  game->nb_tetri = nb_tetri;
  key->info.row = key->info.row + 8;
  game->width = (key->info.col * 2) + 1;
  game->height = key->info.row + 2;
  game->inc = 0;
  game->delay = 5000;
  game->locked = 0;
  game->score = 0;
  game->level = key->info.level;
  if (game->level > 16)
    game->level = 16;
  game->turn = 0;
  game->nb = 0;
  game->next = 0;
  game->y = 7 - tetris[game->nb].height;
  if (game->y < 0)
    game->y = 0;
  game->x = (game->width / 2) - (tetris[game->nb].width / 2);
  if (game->x % 2 != 0)
    game->x = game->x - 1;
}

char	**create_empty_lines(char **wndw, t_info info)
{
  int	i;
  int	j;
  int	width;

  i = 1;
  j = 1;
  width = (info.col * 2) + 1;
  while (j <= info.row)
    {
      if ((wndw[j] = my_uber_malloc(sizeof(char) * (width + 1))) == NULL)
	exit(RETURN_FAIL);
      wndw[j][0] = '|';
      while (i < width - 1)
	{
	  wndw[j][i] = ' ';
	  i = i + 1;
	}
      wndw[j][i] = '|';
      i = 1;
      j = j + 1;
    }
  return (wndw);
}

char	*create_full_line(char *line, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      line[i] = '=';
      i = i + 1;
    }
  line[i] = '\0';
  return (line);
}

char	**create_wndw(char **wndw, t_info info)
{
  int	width;

  width = (info.col * 2) + 1;
  if ((wndw = malloc(sizeof(char *) * (info.row + 3))) == NULL)
    exit(RETURN_FAIL);
  if ((wndw[0] = malloc(sizeof(char) * (width + 1))) == NULL)
    exit(RETURN_FAIL);
  wndw[0] = create_full_line(wndw[0], width);
  wndw = create_empty_lines(wndw, info);
  if ((wndw[info.row + 1] = malloc(sizeof(char) * (width + 1))) == NULL)
    exit(RETURN_FAIL);
  wndw[info.row + 1] = create_full_line(wndw[info.row + 1], width);
  wndw[8] = create_full_line(wndw[8], width);
  wndw[info.row + 2] = NULL;
  return (wndw);
}

char	**create_up_map(char **up_map, t_info info)
{
  int	width;
  int	j;
  int	i;

  width = (info.col * 2) + 1;
  j = 0;
  i = 0;
  if ((up_map = malloc(sizeof(char *) * 10)) == NULL)
    exit(RETURN_FAIL);
  while (j < 8)
    {
      up_map[j] = malloc(sizeof(char) * (width + 1));
      while (i < width)
	{
	  up_map[j][i] = ' ';
	  i = i + 1;
	}
      up_map[j][i] = '\0';
      i = 0;
      j = j + 1;
    }
  up_map[j] = malloc(sizeof(char) * (width + 1));
  up_map[j] = create_full_line(up_map[j], width);
  up_map[j + 1] = NULL;
  return (up_map);
}
