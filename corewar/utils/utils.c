/*
** utils.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Sun Mar 26 15:27:09 2017 Jordan Bonaldi
** Last update	Sun Apr 02 14:01:08 2017 Jordan Bonaldi
*/

# include "project.h"

char			*get_last_name(t_vm *vm)
{
  t_prog	*prog;

  prog = vm->prog;
  while (prog)
    {
      if (prog->id == vm->last)
        return (prog->header->prog_name);
      prog = prog->next;
    }
  return (NULL);
}

int						get_id(t_string *cmd)
{
  int					i;

  i = -1;
  while (op_tab[++i].mnemonique)
    if (cmd->equalsIgnoreCase(cmd, op_tab[i].mnemonique))
      return (op_tab[i].code);
  return (0);
}

void				my_memset(char *str, char c, int size)
{
  int				i;

  i = -1;
  while (++i < size)
    str[i] = c;
}

void		*xmalloc(size_t size)
{
  void	*to_malloc;

  if (!(to_malloc = malloc(size)))
    exit(83);
  return (to_malloc);
}
