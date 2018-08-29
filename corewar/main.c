/*
** main.c for corewar in /home/lucas99.06/Epitech/Semester2/CPE_2016_corewar/corewar
**
** Made by Lucas Benkemoun
** Login   <benke_l@epitech.net>
**
** Started on  Sun Mar 26 16:50:10 2017 Lucas Benkemoun
** Last update	Sun Apr 02 22:36:59 2017 Jordan Bonaldi
*/

#include "project.h"

int			print_start_champ(t_vm *vm)
{
  t_prog	*tmp;
  int		i;

  i = 0;
  tmp = vm->prog;
  while (tmp)
    {
      my_printf("===============\n");
      my_printf("Name: %s\n", tmp->header->prog_name);
      my_printf("Size: %d\n", tmp->header->prog_size);
      my_printf("Desc: %s\n", tmp->header->comment);
      my_printf("Player id: %d\n", tmp->id);
      my_printf("===============\n");
      tmp = tmp->next;
      i++;
    }
  return (i);
}

int		main(int ac, char **av)
{
  boolean	dump;
  t_vm	*vm;

  if ((ac == 1) || (ac == 2 && !my_strcmp(av[1], "-h")) || (ac <= 2))
    return (print_help(av[0]));
  vm = xmalloc(sizeof(t_vm));
  vm->die = CYCLE_TO_DIE;
  vm->prog = NULL;
  vm->last = 0;
  vm->dump = -1;
  check_arguments(ac, av, vm);
  put_champ_mem(vm, print_start_champ(vm));
  dump = vm->dump > 0 ? true : false;
  start_vm(vm);
  if (vm->last)
    my_printf("The player %d(%s) has won\n", vm->last, get_last_name(vm));
  if (dump)
    print_memory(vm);
  return (0);
}
