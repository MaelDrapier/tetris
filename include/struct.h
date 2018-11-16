/*
** struct.h for tetris in /home/mael/PSU_2016_tetris
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Mon Feb 27 12:04:19 2017 mael drapier
** Last update Mon Mar 20 16:13:32 2017 mael drapier
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef	struct		s_tetriminos
{
  char			***draw;
  char			*name;
  int			width;
  int			height;
  int			color;
}			t_tetriminos;

typedef	struct		s_info
{
  int		debug;
  int		next;
  int		level;
  int		row;
  int		col;
}			t_info;

typedef	struct		s_debug
{
  int		helper;
  char		*left;
  char		*right;
  char		*turn;
  char		*drop;
  char		*quit;
  char		*pause;
  t_info	info;
}			t_debug;

typedef	struct		s_game
{
  char			**wndw;
  char			**up_map;
  int			width;
  int			height;
  int			x;
  int			y;
  int			nb;
  int			next;
  int			delay;
  int			level;
  int			score;
  int			locked;
  int			inc;
  int			nb_tetri;
  int			turn;
}			t_game;

#endif /* !STRUCT_H_ */
