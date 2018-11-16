/*
** map.c for tetris in /home/mael/TETRIS_TMP
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Mon Feb 27 13:41:57 2017 mael drapier
** Last update Thu Mar  2 17:44:12 2017 etienne.filliat
*/

#include <dirent.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "tetris.h"
#include "gnl.h"

int	find_start(char *filename)
{
  int	i;

  i = 0;
  while (filename[i] != '\0')
    i = i + 1;
  while (filename[i] != '.')
    {
      i = i - 1;
      if (i < 0)
	return (0);
    }
  return (i);
}

int		nb_of_tetriminos()
{
  DIR		*repo;
  struct dirent	*reading;
  int		nb_tetri;
  int		start;

  nb_tetri = 0;
  repo = opendir("tetriminos");
  while ((reading = readdir(repo)))
    {
      start = find_start(reading->d_name);
      if (my_strcmp(reading->d_name, ".tetrimino", start) == 0)
	nb_tetri = nb_tetri + 1;
    }
  closedir(repo);
  return (nb_tetri);
}

t_tetriminos	init_tetri(t_tetriminos tetri)
{
  tetri.width = 0;
  tetri.height = 0;
  tetri.color = 0;
  return (tetri);
}

t_tetriminos	read_tetrimino(int fd, t_tetriminos tetri, char *name)
{
  char		*s;
  char		**tab;
  int		i;

  i = 0;
  tetri = init_tetri(tetri);
  if ((tetri.name = my_uber_malloc(sizeof(char) * my_strlen(name))) == NULL)
    exit (84);
  while (i < find_start(name))
    {
      tetri.name[i] = name[i];
      i = i + 1;
    }
  tetri.name[i] = '\0';
  if ((s = get_next_line(fd)) == NULL)
    return (tetri);
  if ((tab = my_uber_malloc(sizeof(char *) * 4)) == NULL)
    return (tetri);
  if ((tab = my_str_to_wordtab(tab, s, 0, 0)) == NULL)
    return (tetri);
  tetri.width = my_getnbr(tab[0]);
  tetri.height = my_getnbr(tab[1]);
  tetri.color = my_getnbr(tab[2]);
  tetri = fill_tetri(tetri, fd);
  return (tetri);
}

t_tetriminos	*get_tetriminos(t_tetriminos *tetris)
{
  DIR		*repo;
  struct dirent	*reading;
  int		start;
  int		fd;
  int		i;

  i = 0;
  repo = opendir("tetriminos");
  while ((reading = readdir(repo)))
    {
      start = find_start(reading->d_name);
      if (my_strcmp(reading->d_name, ".tetrimino", start) == 0)
        {
	  chdir("tetriminos");
          fd = open(reading->d_name, O_RDONLY);
	  if (fd < 0)
	    return (tetris);
          tetris[i] = read_tetrimino(fd, tetris[i], reading->d_name);
	  close(fd);
	  i = i + 1;
        }
    }
  closedir(repo);
  return (tetris);
}
