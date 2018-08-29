/*
** utils_list.c for
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Mon Mar 27 12:24:38 2017 Jordan Bonaldi
** Last update	Sun Apr 02 20:53:04 2017 Jordan Bonaldi
*/

# include "project.h"

static t_params	*init_params()
{
  t_params	*params;

  params = xmalloc(sizeof(t_params));
  params->get_instr = &get_instruction;
  params->set_type = &set_type;
  params->set_instr = &set_instruction;
  params->get_first = &get_first_param;
  params->v1 = &is_valid2;
  params->v = &is_valid;
  params->get_params = &get_p;
  params->set_params = &set_p;
  params->set_mem = &set_new_mem_place;
  params->p = xmalloc(MAX_ARGS_NUMBER);
  return (params);
}

static int				get_id_champ(t_prog *prog)
{
  t_prog	*tmp;
  int			i;

  tmp = prog;
  i = 1;
  while (tmp && i++)
    tmp = tmp->next;
  return (i);
}

void			add_prog_to_list_prog(t_vm *vm, t_prog *prog, boolean f)
{
  t_prog	*e;
  t_prog	*tmp;

  tmp = vm->prog;
  e = xmalloc(sizeof(t_prog));
  1 ? e->id = prog->id, e->id_n = get_id_champ(vm->prog),
    e->nblives = prog->nblives, e->instr = -1, e->exec = 0, e->dead = false,
    e->instr = -1, e->load = prog->load, e->carry = prog->carry,
    e->pc = prog->pc + get_memzone((short)prog->p->p[0] %
        (f ? (IDX_MOD) : prog->p->p[0] + 1)), e->header = prog->header,
    e->p = init_params(), e->p->r[0] = prog->p->r[0],
    e->p->r[1] = prog->p->r[1], e->p->r[2] = prog->p->r[2], e->next = NULL : 0;
  if (!vm->prog)
  {
    vm->prog = e;
    return;
  }
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = e;
}

void			add_prog_to_list(t_vm *vm, int nb, int load, char *path)
{
  int	    fd;
  t_prog	*e;
  t_prog	*tmp;

  tmp = vm->prog;
  e = xmalloc(sizeof(t_prog));
  1 ? e->id = nb < 0 ? get_id_champ(vm->prog) : nb, e->id_n = -1,
    e->load = load, e->nblives = 0, e->instr = 0, e->exec = 0, e->pc = 0,
    e->addr = 0, e->dead = false, e->p = init_params(), e->instr = -1 : 0;
  if (!(e->header = init_header(path, &fd)))
    exit(84);
  e->prog = xmalloc(e->header->prog_size + 1);
  if (read(fd, e->prog, e->header->prog_size) != e->header->prog_size)
    exit(!my_printf("Invalid size or instructions !\n") ? 84 : 84);
  e->next = NULL;
  if (!vm->prog && (vm->prog = e))
    return;
  while (tmp->next)
    {
      if (tmp->id == nb)
        exit(!my_printf("Prog %d already exists !\n", nb) ? 84 : 84);
      tmp = tmp->next;
    }
  tmp->next = e;
}
