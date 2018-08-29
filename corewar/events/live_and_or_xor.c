/*
** live_and_or_xor.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Thu Mar 30 12:28:55 2017 Jordan Bonaldi
** Last update	Sun Apr 02 23:12:49 2017 Jordan Bonaldi
*/

# include "project.h"

void				live(t_vm *vm, t_prog *prog)
{
  prog->nblives = 0;
  vm->livenb++;
  vm->last = prog->id;
  my_printf("The player %d(%s) is alive\n", prog->id, prog->header->prog_name);
  prog->pc = prog->addr;
}

void				and(t_vm *vm, t_prog *prog)
{
  int				i[5];

  if (!is_register_pos(prog, 2))
    return;
  i[0] = -1;
  while (++i[0] < 2)
    {
      i[1] = prog->p->t[i[0]] == T_REG && is_register_pos(prog, i[0]) ?
            prog->p->r[prog->p->p[i[0]] - 1] : -1;
      i[2] = prog->p->t[i[0]] == T_DIR ? prog->p->p[i[0]] : -1;
      i[3] = prog->p->t[i[0]] == T_IND ? handle_dir_param(vm,
          prog->pc + prog->p->p[i[0]] % IDX_MOD) : -1;
      if (i[1] < 0 && i[2] < 0 && i[3] < 0)
        return;
      if (!i[0])
        i[4] = i[1] < 0 && i[2] < 0 ? i[3] :
                                        i[2] < 0 && i[3] < 0 ? i[1] : i[2];
      else
        i[4] &= i[1] < 0 && i[2] < 0 ? i[3] :
                                        i[2] < 0 && i[3] < 0 ? i[1] : i[2];
    }
  prog->carry = !prog->p->r[prog->p->p[2] - 1];
  prog->pc = prog->addr;
}

void				or(t_vm *vm, t_prog *prog)
{
  int				i[5];

  if (!is_register_pos(prog, 2))
    return;
  i[0] = -1;
  while (++i[0] < 2)
    {
      i[1] = prog->p->t[i[0]] == T_REG && is_register_pos(prog, i[0]) ?
            prog->p->r[prog->p->p[i[0]] - 1] : -1;
      i[2] = prog->p->t[i[0]] == T_DIR ? prog->p->p[i[0]] : -1;
      i[3] = prog->p->t[i[0]] == T_IND ? handle_dir_param(vm,
          prog->pc + prog->p->p[i[0]] % IDX_MOD) : -1;
      if (i[1] < 0 && i[2] < 0 && i[3] < 0)
        return;
      if (!i[0])
        i[4] = i[1] < 0 && i[2] < 0 ? i[3] :
                                        i[2] < 0 && i[3] < 0 ? i[1] : i[2];
      else
        i[4] |= i[1] < 0 && i[2] < 0 ? i[3] :
                                        i[2] < 0 && i[3] < 0 ? i[1] : i[2];
    }
  prog->carry = !prog->p->r[prog->p->p[2] - 1];
  prog->pc = prog->addr;
}

void				xor(t_vm *vm, t_prog *prog)
{
  int				i[5];

  if (!is_register_pos(prog, 2))
    return;
  i[0] = -1;
  while (++i[0] < 2)
    {
      i[1] = prog->p->t[i[0]] == T_REG && is_register_pos(prog, i[0]) ?
            prog->p->r[prog->p->p[i[0]] - 1] : -1;
      i[2] = prog->p->t[i[0]] == T_DIR ? prog->p->p[i[0]] : -1;
      i[3] = prog->p->t[i[0]] == T_IND ? handle_dir_param(vm,
          prog->pc + prog->p->p[i[0]] % IDX_MOD) : -1;
      if (i[1] < 0 && i[2] < 0 && i[3] < 0)
        return;
      if (!i[0])
        i[4] = i[1] < 0 && i[2] < 0 ? i[3] :
                                        i[2] < 0 && i[3] < 0 ? i[1] : i[2];
      else
        i[4] ^= i[1] < 0 && i[2] < 0 ? i[3] :
                                        i[2] < 0 && i[3] < 0 ? i[1] : i[2];
    }
  prog->carry = !prog->p->r[prog->p->p[2] - 1];
  prog->pc = prog->addr;
}
