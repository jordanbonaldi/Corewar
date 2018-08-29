/*
** asm_handler.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Sun Mar 19 14:30:33 2017 Jordan Bonaldi
** Last update	Fri Mar 31 11:48:07 2017 Jordan Bonaldi
*/

# include "project.h"

static void		try_fl(t_prog *prog, char *bin)
{
  int					i;

  i = -1;
  bin[1] = 0;
  while (++i < MAX_ARGS_NUMBER)
    {
      if (!prog->types[i])
        prog->types[i] = init_string("0");
      if (prog->types[i]->equals(prog->types[i], my_itoa(T_IND)))
        bin[1] |= (T_IND - 1) << ((3 - i) * 2);
      else if (prog->types[i]->equals(prog->types[i], my_itoa(T_LAB)))
        bin[1] |= T_DIR << ((3 - i) * 2);
      else
        bin[1] |= prog->types[i]->toInt(prog->types[i]) << ((3 - i) * 2);
    }
}

void			asm_handle(t_asm *a, int *s, t_asm *ct, binary *bin)
{
  int			i[5];

  *i = -1;
  while (a->prog[++(*i)])
    {
      my_memset(bin, 0, 10);
      if (a->prog[*i]->line < 0 && (!(a->prog[*i]->size = *s) ? 1 : 1))
         ct->prog[ct->count++] = a->prog[*i];
      else if (!(i[2] = 0) && (i[1] = -1) && (*bin = a->prog[*i]->line))
        {
          if (is_good_line(a->prog[*i]->line) && ++i[2])
            try_fl(a->prog[*i], bin);
          while (++i[1] < MAX_ARGS_NUMBER && a->prog[*i]->types[i[1]] &&
                  a->prog[*i]->l_arg[i[1]])
            {
              i[3] = get_size(a->prog[*i], i[1]);
              i[4] = a->prog[*i]->l_arg[i[1]]->toInt(a->prog[*i]->l_arg[i[1]]);
              while (--i[3] >= 0)
		              bin[++i[2]] = ((char *)&i[4])[i[3]];
            }
          a->prog[*i]->size = i[2];
          a->prog[*i]->bin = get_it(bin, i[2] + 1);
          *s += ++i[2];
        }
    }
}
