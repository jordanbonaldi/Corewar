/*
** utils_file.c for CPE_2016_corewar
**
** Made by	Jordan Bonaldi
** Login	Neferett@epitech.net
**
** Started on	Sat Mar 11 12:36:22 2017 Jordan Bonaldi
** Last update	Fri Mar 31 11:01:47 2017 Jordan Bonaldi
*/

# include "project.h"

void				my_memset(char *str, char c, int size)
{
  int				i;

  i = -1;
  while (++i < size)
    str[i] = c;
}

t_string		*get_output(char *str)
{
  str = my_revstr(str);
  if (nb_of(str, '.'))
    {
      while (*str != '.' && ++str);
      ++str;
    }
  return (init_string(my_strcat(my_revstr(str), ".cor")));
}

char				*get_comment(char *line, boolean name)
{
  char			*ret;
  int				i;

  ret = xmalloc(name ? PROG_NAME_LENGTH : COMMENT_LENGTH);
  my_memset(ret, 0, name ? PROG_NAME_LENGTH : COMMENT_LENGTH);
  i = -1;
  if (nb_of(line, '"') != 2)
    exit(84);
  while (*line && *line != '"' && ++line);
  ++line;
  while (line[++i] && line[i] != '"' &&
      (i < (name ? PROG_NAME_LENGTH : COMMENT_LENGTH) + 1))
    ret[i] = (int)line[i];
  if (line[i] != '"')
    my_exit(line, "Too long", 1);
  if (line[++i])
    my_exit(line, "Invalid char", i + 1);
  return (ret);
}

boolean			handle_basic_command(t_asm *asm, char *line)
{
  if (!my_strncmp(line, NAME_CMD_STRING, NAME_CMD_STRING_LENGTH) &&
      asm->prog_name == NULL)
    asm->prog_name = get_comment(line + NAME_CMD_STRING_LENGTH, true);
  else if (!my_strncmp(line, COMMENT_CMD_STRING, COMMENT_CMD_STRING_LENGTH) &&
    asm->prog_desc == NULL)
    asm->prog_desc = get_comment(line + COMMENT_CMD_STRING_LENGTH, false);
  else
    my_exit(line, "Double definition", 1);
  return (false);
}

int			count_instruct(char *name)
{
  char	*buff;
  int	i;
  int	fd;

  i = 0;
  if ((fd = open(name, O_RDONLY)) < 0)
    exit(84);
  while ((buff = get_next_line(fd)))
    if (*buff && *delete_space(buff) != COMMENT_CHAR &&
        my_strncmp(buff, NAME_CMD_STRING, NAME_CMD_STRING_LENGTH) &&
        my_strncmp(buff, COMMENT_CMD_STRING, COMMENT_CMD_STRING_LENGTH))
      i++;
  return (i);
}
