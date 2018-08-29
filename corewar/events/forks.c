/*
** forks.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Thu Mar 30 12:31:25 2017 Jordan Bonaldi
** Last update	Sun Apr 02 21:06:42 2017 Jordan Bonaldi
*/

# include "project.h"

void				c_fork(t_vm *vm, t_prog *prog)
{
  add_prog_to_list_prog(vm, prog, false);
  prog->pc = prog->addr;
}

void				lfork(t_vm *vm, t_prog *prog)
{
  add_prog_to_list_prog(vm, prog, true);
  prog->pc = prog->addr;
}
