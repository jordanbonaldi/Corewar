/*
** utils_args.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Sun Mar 26 20:00:21 2017 Jordan Bonaldi
** Last update	Wed Mar 29 21:47:27 2017 Jordan Bonaldi
*/

# include "project.h"

void			check_arguments(int ac, char **argv, t_vm *vm)
{
  int			nb;
  int			load;
  int			i;

  i = 0;
  nb = -1;
  load = -1;
  vm->dump = -1;
  while (++i < ac)
    {
      if (*argv[i] == '-' && !my_strcmp(argv[i], "-dump"))
        vm->dump = my_getnbr(argv[i + 1]);
      else if (*argv[i] == '-' && !my_strcmp(argv[i], "-n"))
        nb = my_getnbr(argv[i + 1]);
      else if (*argv[i] == '-' && !my_strcmp(argv[i], "-a"))
        load = my_getnbr(argv[i + 1]);
      else if (!my_strncmp(my_revstr(argv[i]), "roc.", 4))
        1 ? (add_prog_to_list(vm, nb, load, my_revstr(argv[i])),
              (nb = -1), (load = -1)) : 0;
    }
}
