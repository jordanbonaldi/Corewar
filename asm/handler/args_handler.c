/*
** args_handler.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Sat Mar 18 14:08:35 2017 Jordan Bonaldi
** Last update	Sat Mar 25 17:03:15 2017 Jordan Bonaldi
*/

# include "project.h"

void				check_reg_and_int(args_type_t type,
              int nb, t_asm *asm, int i)
{
  if (type == T_REG && (nb > REG_NUMBER || nb < 0))
    my_exit(asm->prog[asm->count]->l_arg[i]->str, "Unknown register", 0);
}

void				check_errors(t_asm *asm)
{
  int				i;

  i = -1;
  while (asm->prog[asm->count]->l_arg[++i])
    {
      if (asm->prog[asm->count]->types[i]->
            toInt(asm->prog[asm->count]->types[i]) == T_REG)
        check_reg_and_int(T_REG, asm->prog[asm->count]->l_arg[i]->
              toInt(asm->prog[asm->count]->l_arg[i]), asm, i);
      else if (asm->prog[asm->count]->types[i]->
            toInt(asm->prog[asm->count]->types[i]) == T_DIR)
        check_reg_and_int(T_DIR, asm->prog[asm->count]->l_arg[i]->
              toInt(asm->prog[asm->count]->l_arg[i]), asm, i);
      if (!(op_tab[asm->prog[asm->count]->line - 1].type[i] &
          ((asm->prog[asm->count]->types[i]->
            toInt(asm->prog[asm->count]->types[i]) & 8) > 0 ? T_DIR :
            asm->prog[asm->count]->types[i]->
              toInt(asm->prog[asm->count]->types[i]))))
        my_exit(asm->prog[asm->count]->str->str, "Invalid argument", 0);
      if ((asm->prog[asm->count]->types[i]->
        toInt(asm->prog[asm->count]->types[i]) & 8) > 0)
        asm->prog[asm->count]->types[i] = init_string(my_itoa(8));
    }
}

type_arg		**stock_types(args_type_t **cmd)
{
  int							i;
  type_arg				**args;

  i = -1;
  args = xmalloc(sizeof(type_arg *) * 5);
  while (cmd[++i])
    args[i] = get_good_type(cmd, i);
  args[i] = NULL;
  return (args);
}

t_string		**stock_args(t_string *str, char **cmd, int *argsnb)
{
  int							j;
  int							i;
  t_string				**args;

  i = -1;
  args = xmalloc(sizeof(t_string *) * 5);
  while (cmd[++i])
  {
    args[i] = init_string(cmd[i] + (*cmd[i] == 'r' ||
                    *cmd[i] == DIRECT_CHAR));
    if (args[i]->end == LABEL_CHAR)
      args[i]->str[args[i]->size - 1] = 0;
  }
  --i;
  if (i > MAX_ARGS_NUMBER)
    my_exit(cmd[i], "Too many arguments", 0);
  j = -1;
  while (op_tab[++j].mnemonique)
    if (str->equalsIgnoreCase(str, op_tab[j].mnemonique) &&
        i > op_tab[j].nbr_args)
      my_exit(cmd[i], "Too many arguments", 0);
  *argsnb = i;
  args[++i] = NULL;
  return (args);
}
