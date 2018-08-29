/*
** handle_reg_params.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Sun Apr 02 11:44:58 2017 Jordan Bonaldi
** Last update	Sun Apr 02 11:45:19 2017 Jordan Bonaldi
*/

# include "project.h"

int		handle_dir_param(t_vm *vm, int memzone)
{
  int					i;
  int					ret;

  i = 4;
  if (memzone < 0)
    handle_dir_param(vm, memzone + MEM_SIZE);
  ret = ((vm->mem[get_memzone(memzone + --i)]));
  while (--i > -1)
    ret |= ((vm->mem[get_memzone(memzone + i)]) << (24 - 8 * i));
  return (ret);
}

int		handle_reg_param(t_vm *vm, int memzone)
{
  if (memzone < 0)
    handle_reg_param(vm, memzone + MEM_SIZE);
  return (vm->mem[get_memzone(memzone)]);
}

int		handle_ind_param(t_vm *vm, int memzone)
{
  int					i;
  int					ret;

  i = 2;
  if (memzone < 0)
    handle_dir_param(vm, memzone + MEM_SIZE);
  ret = ((vm->mem[get_memzone(memzone + --i)]));
  while (--i > -1)
    ret |= ((vm->mem[get_memzone(memzone + i)]) << (24 - 8 * i));
  return (ret);
}
