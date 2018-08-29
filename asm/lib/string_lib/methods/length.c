/*
** length.c for lib in /home/Neferett/LIB/lib/string_lib/methods
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Thu Jan 26 15:09:56 2017 Bonaldi Jordan
** Last update Sun Jan 29 21:29:05 2017 Jordan Bonaldi
*/

# include "lib.h"

int		get_length(t_string *str)
{
  return ((str->size = my_strlen(str->str)));
}
