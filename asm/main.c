/*
** main.c for main in /home/Neferett/bin/IMPORT
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Nov 14 14:04:13 2016 Bonaldi Jordan
** Last update	Fri Mar 31 11:03:45 2017 Jordan Bonaldi
*/

#include "project.h"

int	main(int argc, char **argv)
{
  int			size;
  t_asm 	*asm;
  t_asm		*cpy;
  t_asm		*ct_lbl;
  binary	*bin;

  if (argc == 1 || (argc == 2 && !my_strcmp(argv[1], "-h")))
    return (print_help(argv[0]));
  asm = asm_init(argv[1]);
  cpy = asm_init(argv[1]);
  ct_lbl = asm_init(argv[1]);
  bin = xmalloc(20);
  size = 0;
  read_file(asm);
  if (!asm->prog_name || !asm->prog_desc)
    my_exit("", "Nothing in file", 1);
  asm->prog[asm->count] = NULL;
  asm_handle(asm, &size, ct_lbl, bin);
  ct_lbl->prog[ct_lbl->count] = NULL;
  handle_label(asm->prog, cpy->prog, ct_lbl);
  write_header(asm, size, cpy);
  return (0);
}
