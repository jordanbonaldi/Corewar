/*
** handle_checker.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Sat Apr 01 22:02:25 2017 Jordan Bonaldi
** Last update	Sun Apr 02 22:12:20 2017 Jordan Bonaldi
*/

# include "project.h"

boolean		is_valid(t_prog *prog)
{
    return (prog->instr == get_id(init_string("live")) - 1 ||
            prog->instr == get_id(init_string("zjmp")) - 1 ||
            prog->instr == get_id(init_string("fork")) - 1 ||
            prog->instr == get_id(init_string("lfork")) - 1);
}

boolean			is_valid2(t_prog *prog)
{
    return (prog->instr == get_id(init_string("zjmp")) - 1 ||
            prog->instr == get_id(init_string("ldi")) - 1 ||
            prog->instr == get_id(init_string("sti")) - 1 ||
            prog->instr == get_id(init_string("fork")) - 1 ||
            prog->instr == get_id(init_string("lldi")) - 1 ||
            prog->instr == get_id(init_string("lfork")) - 1);
}

boolean			is_ok(t_prog	*prog)
{
  int				i;

  i = -1;
  while (++i < op_tab[prog->instr].nbr_args)
    {
      if (!prog->p->t[i])
        return (false);
      else if (!(op_tab[prog->instr].type[i] & prog->p->type[i]))
        return (false);
    }
  return (true);
}
