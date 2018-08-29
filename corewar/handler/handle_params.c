/*
** handle_params.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Sat Apr 01 23:28:19 2017 Jordan Bonaldi
** Last update	Sun Apr 02 21:52:14 2017 Jordan Bonaldi
*/

# include "project.h"

char			*get_p(t_prog *prog, t_vm *vm)
{
  int			addr;
  int			i;
  char		*params;

  i = -1;
  addr = prog->addr = prog->pc + 2;
  params = xmalloc(MAX_ARGS_NUMBER);
  while (++i < op_tab[prog->instr].nbr_args)
    {
      if (prog->p->t[i] == T_DIR && prog->p->v1(prog) &&
          (addr += sizeof(int)))
        params[i] = handle_dir_param(vm, prog->addr);
      else if (prog->p->t[i] == T_REG && (addr += sizeof(char)))
        params[i] = (unsigned char)handle_reg_param(vm, prog->addr);
      else if ((addr += sizeof(short)))
        params[i] = handle_ind_param(vm, prog->addr);
      prog->addr = addr;
    }
  return (params);
}

char			get_first_param(t_prog *prog, t_vm *vm)
{
  int			i[3];

  prog->addr = i[1] = prog->pc + 1;
  if (prog->p->v1(prog))
    {
      i[0] = 2;
      while (i[1] < 0)
        i[1] += MEM_SIZE;
      i[2] = ((vm->mem[get_memzone(i[1] + --i[0])]));
      while (--i[0] > -1)
        i[2] |= ((vm->mem[get_memzone(i[1] + i[0])]) << (24 - 8 * i[0]));
      prog->addr += 2;
    }
  else
    {
      i[0] = 4;
      while (i[1] < 0)
        i[1] += MEM_SIZE;
      i[2] = ((vm->mem[get_memzone(i[1] + --i[0])]));
      while (--i[0] > -1)
        i[2] |= ((vm->mem[get_memzone(i[1] + i[0])]) << (24 - 8 * i[0]));
      prog->addr += 4;
    }
  return (i[2]);
}

boolean		set_p(t_params *params, t_prog *prog, t_vm *vm)
{
  if (prog->p->v(prog))
    {
      *params->p = params->get_first(prog, vm);
      return (false);
    }
  else
    {
      params->set_instr(prog->p, vm, get_memzone(prog->pc + 1));
      if (params->set_mem(prog))
        return (true);
    }
  params->p = params->get_params(prog, vm);
  return (false);
}
