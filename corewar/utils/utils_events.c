/*
** utils_events.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Sun Apr 02 14:01:18 2017 Jordan Bonaldi
** Last update	Sun Apr 02 14:26:30 2017 Jordan Bonaldi
*/

# include "project.h"

int			get_pos_from_char(t_prog *prog, int pos)
{
  return (prog->p->p[pos] - 1);
}

void		put_reg(t_prog *prog, int in, int to_reg)
{
  prog->p->r[get_pos_from_char(prog, in)] = to_reg;
}

void		modify_carry(t_prog *prog, int pos)
{
  if (prog->p->r[get_pos_from_char(prog, pos)] == 0)
    prog->carry = 1;
  else
    prog->carry = 0;
}
