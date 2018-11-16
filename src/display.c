/*
** display.c for tetris in /home/mael/PSU_2016_tetris
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Mon Feb 27 11:10:08 2017 mael drapier
** Last update Tue Mar 14 14:25:58 2017 etienne.filliat
*/

#include <unistd.h>
#include <stdlib.h>
#include "tetris.h"

void	my_putstr(int fd, char *str)
{
  write(fd, str, my_strlen(str));
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putnbr(int nb)
{
  char	digit;

  if (nb < 0)
    {
      my_putstr(1, "-");
      nb = nb * -1;
    }
  digit = nb % 10 + 48;
  nb = nb / 10;
  if (nb != 0)
    my_putnbr(nb);
  my_putchar(digit);
}

int	my_strcmp(char *s1, char *s2, int start)
{
  int	i;

  i = 0;
  while (s1[i + start] != '\0' || s2[i] != '\0')
    {
      if (s1[i + start] != s2[i])
	return (s1[i + start] - s2[i]);
      i = i + 1;
    }
  return (0);
}

void	my_showtab(char **tab)
{
  int	j;

  j = 0;
  while (tab[j] != NULL)
    {
      my_putstr(1, tab[j]);
      my_putstr(1, "\n");
      j = j + 1;
    }
}
