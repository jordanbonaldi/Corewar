/*
** utils_struct.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	Neferett@epitech.net
**
** Started on	Sat Mar 11 20:49:01 2017 Jordan Bonaldi
** Last update	Sat Mar 25 16:13:43 2017 Jordan Bonaldi
*/

# include "project.h"

t_prog				*init_prog(t_string *l_name, t_string **l_arg,
    t_string **types, reg rg)
{
  t_prog			*prog;

  prog = xmalloc(sizeof(t_prog));
  prog->l_name = l_name;
  prog->l_arg = l_arg;
  prog->types = types;
  prog->line = rg;
  return (prog);
}

t_asm		*asm_init(char *name)
{
  t_asm *asm;

  asm = xmalloc(sizeof(t_asm));
  asm->name = init_string(name);
  asm->prog = xmalloc(sizeof(t_prog *) *
      (count_instruct(asm->name->str) * 2));
  asm->count = 0;
  return (asm);
}
