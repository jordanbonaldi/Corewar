/*
** utils_types.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Sat Mar 18 20:46:19 2017 Jordan Bonaldi
** Last update	Sat Mar 25 15:31:41 2017 Jordan Bonaldi
*/

# include "project.h"

boolean 	is_good_line(reg code)
{
  return (code != T_REG && code != get_id(init_string("zjmp")) &&
          code != get_id(init_string("fork")) &&
            code != get_id(init_string("lfork")));
}

hex						get_hex(type_arg *cmd)
{
  int					i;

  i = -1;
  while (op_tab[++i].mnemonique)
    if (cmd->equalsIgnoreCase(cmd, op_tab[i].mnemonique))
      return (op_tab[i].hex);
  my_exit(cmd->str, "Unknown command", 0);
  return (0);
}

reg						get_size(t_prog *prog, int count)
{
  return ((prog->line == get_id(init_string("zjmp")) ||
          prog->line == get_hex(init_string("fork"))
          || prog->line == get_hex(init_string("lfork"))) ||
          (prog->line == get_hex(init_string("ldi")) && count < 2 &&
          !prog->types[count]->equalsIgnoreCase(prog->types[count],
              my_itoa(T_REG))) ||
          (prog->line == get_hex(init_string("sti")) && count > 0 &&
          !prog->types[count]->equalsIgnoreCase(prog->types[count],
						my_itoa(T_REG))) ||
	  (prog->types[count]->equalsIgnoreCase(prog->types[count],
					       my_itoa(T_LAB)) ||
	  prog->types[count]->equalsIgnoreCase(prog->types[count],
					       my_itoa(T_IND))) ? IND_SIZE :
          (prog->line == get_hex(init_string("ld")) && !count &&
          prog->types[count]->equalsIgnoreCase(prog->types[count],
            my_itoa(T_LAB))) ||
          (prog->types[count]->equalsIgnoreCase(prog->types[count],
            my_itoa(T_DIR))) ?
          DIR_SIZE : REG_SIZE);
}

reg						get_id(type_arg *cmd)
{
  int					i;

  i = -1;
  while (op_tab[++i].mnemonique)
    if (cmd->equalsIgnoreCase(cmd, op_tab[i].mnemonique))
      return (op_tab[i].code);
  my_exit(cmd->str, "Unknown command", 0);
  return (0);
}

type_arg			*get_good_type(args_type_t **cmd, int i)
{
  reg					rg;

  rg = *cmd[i] == 'r' ? T_REG :
       *cmd[i] == DIRECT_CHAR && cmd[i][1] == LABEL_CHAR ? T_LAB :
       *cmd[i] == DIRECT_CHAR ? T_DIR : T_IND;
  return (init_string(my_itoa(rg)));
}
