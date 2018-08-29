/*
** write_header.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Sun Mar 19 11:24:50 2017 Jordan Bonaldi
** Last update	Sat Mar 25 17:03:31 2017 Jordan Bonaldi
*/

# include "project.h"

char			*get_it(char *str, int size)
{
  int			i;
  char		*lol;

  lol = xmalloc(size);
  i = -1;
  while (++i < size)
    lol[i] = (int)str[i];
  return (lol);
}

static void			write_magic_nb(int fd)
{
  int			c;

  c = COREWAR_EXEC_MAGIC;
  write(fd, "", 1);
  write(fd, my_revstr((char *)&c), sizeof(c) - 1);
}

void			write_header(t_asm *asm, int size, t_asm *cpy)
{
  int			fd;
  int			i;

  if ((fd = open(get_output(asm->name->str)->str, O_CREAT
        | O_WRONLY | O_TRUNC, 0644)) < 0)
    exit(84);
  write_magic_nb(fd);
  write(fd, asm->prog_name, PROG_NAME_LENGTH);
  i = 4;
  while (--i >= 0)
    write(fd, &((char *)&size)[i], 1);
  write(fd, asm->prog_desc, COMMENT_LENGTH);
  i = -1;
  while (cpy->prog[++i])
    write(fd, cpy->prog[i]->bin, cpy->prog[i]->size + 1);
}
