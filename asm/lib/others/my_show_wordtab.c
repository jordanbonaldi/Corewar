/*
** my_show_wordtab.c for my_showwordtab.c in /home/Neferett/CPool_Day08
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Wed Oct 12 10:23:49 2016 Bonaldi Jordan
** Last update Mon Jan 30 16:39:52 2017 Lucas Benkemoun
*/

#include "lib.h"

int	my_show_wordtab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i])
    {
      my_putstr(tab[i]);
      my_putchar('\n');
    }
  return (0);
}
