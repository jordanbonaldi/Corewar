/*
** utils_mem.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Mon Mar 27 15:17:39 2017 Jordan Bonaldi
** Last update	Sun Apr 02 21:49:28 2017 Jordan Bonaldi
*/

# include "project.h"

int					get_good_opt(t_prog *prog, int nb, int pos)
{
  return ((prog->p->type[pos] == T_DIR && !prog->p->v1(prog)) ?
          (nb *= 2) : (nb /= 2));
}

boolean			set_new_mem_place(t_prog *prog)
{
  int			i;

  i = -1;
  while (++i < op_tab[prog->instr].nbr_args && !is_ok(prog))
    if ((prog->p->type[i] == T_IND - 1 ||
      (prog->p->type[i] == T_DIR && prog->p->v1(prog))) ||
      (prog->p->type[i] == T_DIR && !prog->p->v1(prog)))
        prog->pc += get_good_opt(prog, prog->p->type[i], i);
    else if (prog->p->type[i] == T_REG)
      prog->pc += prog->p->type[i];
  if (!is_ok(prog) && (prog->pc += 2))
    return (true);
  return (false);
}

void		print_memory(t_vm *vm)
{
	int		i;
  int		line;

	i = -1;
	line = 0;
	while (++i < MEM_SIZE)
	{
		if (i % 32 == 0)
		{
		  my_printf("\n%.4x : ", line);
			line += 32;
		}
		my_printf("%s%.2x%s ", (unsigned char)vm->mem[i] == 0 ? C_W :
      C_R, (unsigned char)vm->mem[i], C_W);
	}
	my_printf("\n");
}

void			put_champ_mem(t_vm *vm, int nb)
{
  t_prog	*prog;
  int			k;
  int			j;
  int			i;
  int			size;

  i = -1;
  j = 0;
  k = MEM_SIZE / nb;
  prog = vm->prog;
  while (++i < nb)
    {
      size = -1;
      prog->pc = j;
      while (++size < prog->header->prog_size && j + size < MEM_SIZE)
        vm->mem[(j + size) % MEM_SIZE] = prog->prog[size];
      j += prog->header->prog_size - 1;
      while (++j < k && j < MEM_SIZE)
        vm->mem[j % MEM_SIZE] = 0;
      k += MEM_SIZE / nb;
      prog = prog->next;
    }
}
