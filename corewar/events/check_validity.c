/*
** check_validity.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Tue Mar 28 21:28:31 2017 Jordan Bonaldi
** Last update	Sat Apr 01 22:51:25 2017 Jordan Bonaldi
*/

# include "project.h"

boolean		is_register(t_prog *prog, int nb_of_reg)
{
  int			i;

  i = -1;
  while (++i < nb_of_reg)
    if (!(prog->p->p[i] > 0 && prog->p->p[i] < REG_NUMBER + 1))
      return (false);
  return (true);
}

boolean		is_register_pos(t_prog *prog, int pos)
{
  if (!(prog->p->p[pos] > 0 && prog->p->p[pos] < REG_NUMBER + 1))
      return (false);
  return (true);
}

boolean		is_register_pos_mem(unsigned char mem[MEM_SIZE], int pos)
{
  if (!(mem[pos] > 0 && mem[pos] < REG_NUMBER + 1))
      return (false);
  return (true);
}
