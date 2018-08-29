/*
** ld.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Thu Mar 30 12:29:45 2017 Jordan Bonaldi
** Last update	Sun Apr 02 21:44:00 2017 Jordan Bonaldi
*/

# include "project.h"

void				ld(t_vm *vm, t_prog *prog)
{
  int				i[3];

  i[0] = 4;
  i[1] = -1;
  if (!is_register_pos(prog, 1))
    return;
  if (*prog->p->t == T_DIR)
    put_reg(prog, 1, prog->p->p[0]);
  else
    {
      i[2] = get_memzone(prog->pc + prog->p->p[0] % IDX_MOD);
      while (i[2] < 0)
        i[2] += MEM_SIZE;
      i[1] = ((vm->mem[get_memzone(i[2] + --i[0])]));
      while (--i[0] > -1)
        i[1] |= ((vm->mem[get_memzone(i[2] + i[0])]) << (24 - 8 * i[0]));
    }
  modify_carry(prog, 1);
  if (i[1] > 0)
    put_reg(prog, 1, i[1]);
  prog->pc = prog->addr;
}

void				ldi(t_vm *vm, t_prog *prog)
{
  int				i[6];

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
        i[4] += i[1] < 0 && i[2] < 0 ? i[3] :
                                        i[2] < 0 && i[3] < 0 ? i[1] : i[2];
    }
  i[5] = get_memzone(prog->pc + i[4]);
  if (i[5] < 0 && (i[5] += MEM_SIZE)) {}
  prog->p->r[prog->p->p[2] - 1] = handle_dir_param(vm, get_memzone(i[5]));
  prog->pc = prog->addr;
}

void				lld(t_vm *vm, t_prog *prog)
{
  int				i[3];

  i[0] = 4;
  i[1] = -1;
  if (!is_register_pos(prog, 1))
    return;
  if (*prog->p->t == T_DIR)
    put_reg(prog, 1, prog->p->p[0]);
  else
    {
      i[2] = get_memzone(prog->pc + prog->p->p[0]);
      while (i[2] < 0)
        i[2] += MEM_SIZE;
      i[1] = ((vm->mem[get_memzone(i[2] + --i[0])]));
      while (--i[0] > -1)
        i[1] |= ((vm->mem[get_memzone(i[2] + i[0])]) << (24 - 8 * i[0]));
    }
  modify_carry(prog, 1);
  if (i[1] > 0)
    put_reg(prog, 1, i[1]);
  prog->pc = prog->addr;
}

void				lldi(t_vm *vm, t_prog *prog)
{
  int				i[6];

  if (!is_register_pos(prog, 2))
    return;
  i[0] = -1;
  while (++i[0] < 2)
    {
      i[1] = prog->p->t[i[0]] == T_REG && is_register_pos(prog, i[0]) ?
            prog->p->r[prog->p->p[i[0]] - 1] : -1;
      i[2] = prog->p->t[i[0]] == T_DIR ? prog->p->p[i[0]] : -1;
      i[3] = prog->p->t[i[0]] == T_IND ? handle_dir_param(vm,
          prog->pc + prog->p->p[i[0]]) : -1;
      if (i[1] < 0 && i[2] < 0 && i[3] < 0)
        return;
      if (!i[0])
        i[4] = i[1] < 0 && i[2] < 0 ? i[3] :
                                        i[2] < 0 && i[3] < 0 ? i[1] : i[2];
      else
        i[4] += i[1] < 0 && i[2] < 0 ? i[3] :
                                        i[2] < 0 && i[3] < 0 ? i[1] : i[2];
    }
  i[5] = get_memzone(prog->pc + i[4]);
  if (i[5] < 0 && (i[5] += MEM_SIZE)) {}
  prog->p->r[prog->p->p[2] - 1] = handle_dir_param(vm, get_memzone(i[5]));
  prog->pc = prog->addr;
}
