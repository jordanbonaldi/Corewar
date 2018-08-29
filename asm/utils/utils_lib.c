/*
** utils_lib.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	Neferett@epitech.net
**
** Started on	Sat Mar 11 12:48:53 2017 Jordan Bonaldi
** Last update	Sat Mar 11 22:47:25 2017 Jordan Bonaldi
*/

# include "project.h"

void		my_exit(char *str, char *message, int spaces)
{
  my_printf("%sWARNING:%s %s:\n\t%s\n%s\t%*s\n", C_Y, RESET,
              message, str, C_R, spaces, "^");
  exit(84);
}

void		*xmalloc(size_t size)
{
  void	*to_malloc;

  if (!(to_malloc = malloc(size)))
    exit(84);
  return (to_malloc);
}

char 		*delete_space(char *str)
{
  return (*str == ' ' ? delete_space(++str) : str);
}

int			tab_len(char **tab)
{
  return (*tab ? tab_len(++tab) + 1 : 0);
}
