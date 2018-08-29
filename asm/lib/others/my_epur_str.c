/*
** my_epur_str.c for lib in /home/Neferett/PSU_2016_minishell1
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Wed Jan 18 20:24:26 2017 Bonaldi Jordan
** Last update Mon Feb 13 17:34:13 2017 Jordan Bonaldi
*/

# include "lib.h"

char		*my_epur_str(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    if (str[i] == '\t')
      str[i] = ' ';
  i = my_strlen(str);
  while (str[--i] && str[i] == ' ')
    str[i] = 0;
  return (str);
}
