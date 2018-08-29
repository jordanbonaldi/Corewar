/*
** handle_vm.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Tue Mar 28 16:21:32 2017 Jordan Bonaldi
** Last update	Sun Apr 02 22:45:29 2017 Jordan Bonaldi
*/

# include "project.h"

static boolean		get_loop_condition(t_vm *vm, int i[3])
{
  return (vm->dump < 0 ? !all_dead(vm) && i[0] < MAXTTC :
      vm->dump > 0 && !all_dead(vm));
}

static boolean			try_execute_param(t_prog *prog, t_vm *vm)
{
  --prog->exec;
  if (!prog->exec && !prog->p->set_params(prog->p, prog, vm))
    {
      op_tab[prog->instr].instr(vm, prog);
      prog->pc = prog->addr;
      return ((prog->instr = -1) < 0);
    }
  else if (!prog->exec)
    return ((prog->instr = -1) < 0);
  return (false);
}

void			start_vm(t_vm *vm)
{
  t_prog	*tmp;
  int			i[3];

  1 ? i[1] = 0, vm->livenb = 0, i[0] = 0 : 0;
  while (get_loop_condition(vm, i))
    {
      i[0]++;
      tmp = vm->prog;
      while (tmp)
        {
          if (!(tmp = handle_dead(tmp)))
            break;
          if (++tmp->nblives && !(i[2] = try_execute_param(tmp, vm)) &&
              tmp->instr < 0 && is_register_pos_mem(vm->mem,
                      get_memzone(tmp->pc)))
            1 ? tmp->instr = vm->mem[get_memzone(tmp->pc)] - 1,
                  tmp->exec = op_tab[tmp->instr].nbr_cycles - 1 : 0;
          !i[2] && tmp->instr < 0 ? tmp->addr = ++tmp->pc : 0;
          tmp = tmp->next;
        }
        vm->dump > 0 ? vm->dump-- : 0;
        1 ? (++i[1] > vm->die) ? i[1] = 1, kill_champ(vm),
          (vm->livenb > NBR_LIVE ? vm->die -= CYCLE_DELTA : 0),
            vm->livenb = 0 : 0 : 0;
    }
}
