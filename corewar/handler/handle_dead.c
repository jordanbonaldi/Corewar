/*
** handle_dead.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Sun Apr 02 22:11:46 2017 Jordan Bonaldi
** Last update	Sun Apr 02 22:16:11 2017 Jordan Bonaldi
*/

# include "project.h"

void			kill_champ(t_vm *vm)
{
  t_prog	*tmp;

  tmp = vm->prog;
  while (tmp)
    {
      if (!tmp->dead && tmp->nblives + 100 >= vm->die)
        tmp->dead = true;
      tmp = tmp->next;
    }
}

boolean		all_dead(t_vm *vm)
{
  t_prog				*tmp;

  tmp = vm->prog;
  while (tmp)
    {
      if (!tmp->dead)
        return (false);
      tmp = tmp->next;
    }
  return (true);
}

t_prog			*handle_dead(t_prog *prog)
{
  if (prog->dead)
    while (prog && prog->dead)
      prog = prog->next;
  return (prog);
}
