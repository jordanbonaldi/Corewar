/*
** add_aff_sub_zjmp.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Tue Mar 28 21:22:28 2017 Jordan Bonaldi
** Last update	Sun Apr 02 21:48:36 2017 Jordan Bonaldi
*/

# include "project.h"

void				add(t_vm *vm, t_prog *prog)
{
  (void)vm;
  if (!is_register(prog, 3))
    return;
  put_reg(prog, 2, prog->p->r[get_pos_from_char(prog, 0)]
        + prog->p->r[get_pos_from_char(prog, 1)]);
  modify_carry(prog, 2);
  prog->pc = prog->addr;
}

void				aff(t_vm *vm, t_prog *prog)
{
  (void)vm;
  if (!is_register_pos(prog, 0))
    return;
  my_printf("Aff: %c\n", prog->p->r[get_pos_from_char(prog, 0)] % 256);
  prog->pc = prog->addr;
}

void				sub(t_vm *vm, t_prog *prog)
{
  (void)vm;
  if (!is_register(prog, 3))
    return;
  put_reg(prog, 2, prog->p->r[get_pos_from_char(prog, 0)] -
        prog->p->r[get_pos_from_char(prog, 1)]);
  modify_carry(prog, 2);
  prog->pc = prog->addr;
}

void				zjmp(t_vm *vm, t_prog *prog)
{
  (void)vm;
  prog->addr = prog->carry ?
    get_memzone((prog->pc + (*prog->p->p % IDX_MOD))) :
    get_memzone(prog->pc + 3);
  prog->pc = prog->addr;
}
