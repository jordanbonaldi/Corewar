/*
** reader.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	Neferett@epitech.net
**
** Started on	Sat Mar 11 12:38:22 2017 Jordan Bonaldi
** Last update	Tue Mar 21 09:57:25 2017 Jordan Bonaldi
*/

# include "project.h"

void			read_file(t_asm *asm)
{
  char		*buff;
  char		**cmd;
  int 		fd;

  if ((fd = open(asm->name->str, O_RDONLY)) < 0)
    exit(84);
  while ((buff = get_next_line(fd)))
    {
      if (!*buff || *delete_space(buff) == COMMENT_CHAR)
        continue;
      if (!my_strncmp(buff, NAME_CMD_STRING, NAME_CMD_STRING_LENGTH) ||
          !my_strncmp(buff, COMMENT_CMD_STRING, COMMENT_CMD_STRING_LENGTH))
        {
          handle_basic_command(asm, buff);
          continue;
        }
      cmd = my_str_to_wordtab(my_epur_str(buff));
      check_line(asm, cmd, my_epur_str(buff));
      asm->count++;
    }
  if (close(fd) < 0)
    exit(84);
}
