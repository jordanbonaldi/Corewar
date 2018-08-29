/*
** utils_lbl.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Sat Mar 25 15:32:37 2017 Jordan Bonaldi
** Last update	Sat Mar 25 16:27:10 2017 Jordan Bonaldi
*/

# include "project.h"

static boolean		is_label(t_string *type, t_string *args)
{
  return (type->equals(type, my_itoa(T_LAB)) || args->first == LABEL_CHAR);
}

static int				get_correspondant_lbl(t_prog **prog, t_string *args)
{
  int			i;

  i = -1;
  while (prog[++i] &&
      !(*prog[i]->l_arg)->equalsIgnoreCase((*prog[i]->l_arg), args->str + 1));
  return (i);
}

static void			test_label(t_asm *cpy, t_prog *prog)
{
  static int	k;
  int					l;
  int					i;
  int					nb;
  int					size;
  int					lbl;

  i = -1;
  l = is_good_line(prog->line);
  while (++i < MAX_ARGS_NUMBER && prog->types[i] && prog->l_arg[i])
    if (is_label(prog->types[i], prog->l_arg[i]))
      if ((lbl = get_correspondant_lbl(cpy->prog, prog->l_arg[i]))
            <= cpy->count && (nb = cpy->prog[lbl]->size - k) &&
          (size = get_size(prog, i)))
        while (--size >= 0)
          prog->bin[++l] = ((char *)&nb)[size];
      else
        my_exit(prog->str->str, "Unknown label name", i);
    else
      l += get_size(prog, i);
  k += prog->size + 1;
}

void			handle_label(t_prog **prog, t_prog **new, t_asm *cpy)
{
  int			j;
  int			i;

  i = -1;
  j = -1;
  while (prog[++i])
    if (prog[i]->line > 0)
      {
        test_label(cpy, prog[i]);
        new[++j] = prog[i];
      }
  new[++j] = NULL;
}
