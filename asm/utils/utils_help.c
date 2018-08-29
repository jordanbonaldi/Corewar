/*
** utils_help.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	Neferett@epitech.net
**
** Started on	Sat Mar 11 12:28:55 2017 Jordan Bonaldi
** Last update	Sun Mar 12 13:23:16 2017 Jordan Bonaldi
*/

# include "project.h"

int		print_help(char *name)
{
  my_printf("USAGE\n\t%s file_name[.s]\n\nDESCRIPTION\n\tfile_name\t"
    "file in assembly language to be converted "
    "into file_name.cor, an \n\t\t\texecutable in the Virtual Machine\n",
    name);
  return (1);
}
