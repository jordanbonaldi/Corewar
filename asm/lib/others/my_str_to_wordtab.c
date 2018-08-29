/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/Neferett/CPool_Day08/task04
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Wed Oct 12 10:53:16 2016 Bonaldi Jordan
** Last update	Tue Mar 21 09:57:53 2017 Jordan Bonaldi
*/

# include "lib.h"

int		forbidden(char c)
{
  return (c == ',' || c == ' ' || !c);
}

char	**tab_complete(char **, char *, int);

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  int	i;

  i = 0;
  if (!(tab = malloc(my_strlen(str) * 10)))
    return (NULL);
  tab = tab_complete(tab, str, i);
  return (tab);
}

char	**tab_complete(char **tab, char *str, int i)
{
  int	j;
  char	*arr;

  j = -1;
  if (!(arr = malloc(my_strlen(str) * 10)))
    return (NULL);
  while (*str && !(i = 0) && (!++(j) ? 1 : 1))
    {
      while (*str && forbidden(*str) && (str++)) {}
      while (*str && !forbidden(*str) && *str)
	if ((arr[i] = *str) && (++i) && !(arr[i] = 0) && (str++)) {}
      if (arr && (tab[j] = my_strdup(arr)))
	while (*++arr);
    }
  tab[++j] = NULL;
  return (tab);
}
