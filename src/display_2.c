/*
** display_2.c for tetris in /home/spiki/delivery/B2/PSU/PSU_2016_tetris/tmp_mael/src/
**
** Made by etienne.filliat
** Login   <etienne.filliat@epitech.eu>
**
** Started on  Wed Mar  1 12:22:02 2017 etienne.filliat
** Last update Mon Mar 13 13:34:45 2017 mael drapier
*/

int	my_strcmp_debug(char *s1, char *s2, int end)
{
  int	i;

  i = 0;
  while ((s1[i] != '\0' || s2[i] != '\0') && i < end)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i = i + 1;
    }
  return (0);
}

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}
