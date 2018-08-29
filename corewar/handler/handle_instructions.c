/*
** handle_file.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Tue Mar 28 19:51:38 2017 Jordan Bonaldi
** Last update	Sat Apr 01 23:15:23 2017 Jordan Bonaldi
*/

# include "project.h"

char				*get_instruction(t_vm *vm, int addr)
{
  char			*types;

  types = xmalloc(MAX_ARGS_NUMBER * sizeof(char));
  types[0] = (unsigned char)(vm->mem[addr]);
  types[0] >>= 6;
  types[1] = (unsigned char)(vm->mem[addr] & 0x30);
  types[1] >>= 4;
  types[2] = (unsigned char)(vm->mem[addr] & 0xC);
  types[2] >>= 2;
  types[3] = 0;
  return (types);
}

int					*set_type(t_params *params)
{
  int				*type;
  int				i;

  i = -1;
  type = xmalloc(sizeof(int) * MAX_ARGS_NUMBER);
  while (params->t[++i])
    type[i] = params->t[i] == 3 ? params->t[i] + 1 : params->t[i];
  return (type);
}

void				set_instruction(t_params *params, t_vm *vm, int addr)
{
  params->t = params->get_instr(vm, addr);
  params->type = params->set_type(params);
  params->p = xmalloc(MAX_ARGS_NUMBER);
}
