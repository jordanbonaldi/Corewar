/*
** st.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Thu Mar 30 12:30:50 2017 Jordan Bonaldi
** Last update	Sun Apr 02 22:28:16 2017 Jordan Bonaldi
*/

# include "project.h"

void				st(t_vm *vm, t_prog *prog)
{
  int				i[2];

  i[0] = 4;
  if (!is_register_pos(prog, 0))
    return;
  if (prog->p->t[1] == 1 && is_register_pos(prog, 1))
    {
      prog->p->r[get_pos_from_char(prog, 1)] =
          prog->p->r[get_pos_from_char(prog, 0)];
      return;
    }
  i[1] = get_memzone(prog->pc + (prog->p->p[1] % IDX_MOD));
  while (i[1] < 0)
    i[1] += MEM_SIZE;
  vm->mem[get_memzone(i[1] + --i[0])] =
        prog->p->r[get_pos_from_char(prog, 0)];
  while (--i[0] > -1)
    vm->mem[get_memzone(i[1] + i[0])] =
        prog->p->r[get_pos_from_char(prog, 0)] >> (24 - 8 * i[0]);
  prog->pc = prog->addr;
}

void				sti(t_vm *vm, t_prog *prog)
{
  int				i[6];

  if ((i[0] = -1) && !is_register_pos(prog, 0))
    return;
  while (++i[0] < 2)
    {
      i[1] = prog->p->t[i[0]] == T_REG && is_register_pos(prog, i[0]) ?
            prog->p->r[prog->p->p[i[0]] - 1] : -1;
      i[2] = prog->p->t[i[0]] == T_DIR ? prog->p->p[i[0]] : -1;
      i[3] = prog->p->t[i[0]] == T_IND ? handle_dir_param(vm,
          prog->pc + prog->p->p[i[0]]) : -1;
      if (i[1] < 0 && i[2] < 0 && i[3] < 0)
        return;
      if (!i[0] && (i[4] = i[1] < 0 && i[2] < 0 ? i[3] :
            i[2] < 0 && i[3] < 0 ? i[1] : i[2])) {}
      else if (i[4] += i[1] < 0 && i[2] < 0 ? i[3] :
            i[2] < 0 && i[3] < 0 ? i[1] : i[2]) {}
    }
  if ((i[5] = get_memzone(prog->pc + i[4])) && (prog->pc = prog->addr)) {}
  if (!(i[0] = 4) && i[5] < 0 && (i[5] += MEM_SIZE)) {}
  vm->mem[get_memzone(i[5] + --i[0])] =
        prog->p->r[get_pos_from_char(prog, 0)];
  while (--i[0] > -1)
    vm->mem[get_memzone(i[5] + i[0])] =
        prog->p->r[get_pos_from_char(prog, 0)] >> (24 - 8 * i[0]);
}
