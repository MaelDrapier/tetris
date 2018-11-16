/*
** set_malloc.c for tetris in /home/spiki/delivery/B2/PSU/PSU_2016_tetris/tmp_etienne/src/
**
** Made by etienne.filliat
** Login   <etienne.filliat@epitech.eu>
**
** Started on  Thu Mar  2 15:21:59 2017 etienne.filliat
** Last update Thu Mar  2 17:46:10 2017 etienne.filliat
*/

#include <stdlib.h>
#include "tetris.h"

void		*my_uber_malloc(int size)
{
  char		*mal;

  if ((mal = malloc(size + 1)) == NULL)
    return (NULL);
  return ((void *) my_mem(mal, '\0', size + 1));

}

void		*my_mem(void *str, char c, int size)
{
  int		x;
  char		*out;

  x = 0;
  out = str;
  while (x < size)
    {
      out[x] = c;
      x++;
    }
  return ((void *) out);
}
