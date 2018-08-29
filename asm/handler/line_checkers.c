/*
** line_checkers.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	Neferett@epitech.net
**
** Started on	Sat Mar 11 21:47:03 2017 Jordan Bonaldi
** Last update	Sun Apr 02 23:26:34 2017 Jordan Bonaldi
*/

# include "project.h"

static void		check_label(t_asm *asm, t_string *str)
{
  int					o;
  int					j;
  int					i;

  i = -1;
  o = -1;
  while (asm->prog[++o])
    if (asm->prog[o]->line < 0)
      if (str->equalsIgnoreCase(str, asm->prog[o]->l_name->str))
        my_exit(str->str, "Double definition of label", 1);
  while (str->str[++i] && str->str[i] != LABEL_CHAR)
    {
      j = -1;
      while (LABEL_CHARS[++j])
        if (str->str[i] == LABEL_CHARS[j])
          break;
      if (j == 38 || str->str[i] == '-')
        my_exit(str->str, "Forbidden char", i + 1);
    }
  if (str->str[++i])
    my_exit(str->str, "Forbidden char after :", i + 1);
}

void		check_line(t_asm *asm, char **cmd, char *line)
{
  t_string	*str;
  int				argsnb;

  argsnb = 0;
  str = init_string(*cmd);
  if (*cmd && str->contains(str, LABEL_CHAR))
    {
      check_label(asm, str);
      asm->prog[asm->count] = init_prog(str, stock_args(str, cmd, &argsnb),
                                NULL, -1);
      asm->prog[asm->count]->argsnb = argsnb;
      asm->prog[asm->count]->str = init_string(line);
      if (asm->prog[asm->count]->l_arg[1] && ++asm->count)
        check_line(asm, cmd + 1, line);
    }
  else if (*cmd && cmd[1])
    {
      asm->prog[asm->count] = init_prog(str, stock_args(str, cmd + 1, &argsnb),
                                  stock_types(cmd + 1), get_id(str));
      asm->prog[asm->count]->argsnb = argsnb;
      asm->prog[asm->count]->str = init_string(line);
      check_errors(asm);
    }
}
