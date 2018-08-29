/*
** main.c for main in /home/Neferett/bin/IMPORT
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Nov 14 14:04:13 2016 Bonaldi Jordan
** Last update	Fri Mar 31 16:14:52 2017 Jordan Bonaldi
*/

#include "project.h"

static int	if_alpha(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
      (c >= '0' && c <= '9') || c == '_')
    return (1);
  else
    return (0);
}

static int     check_magic_number(unsigned char *hd)
{
  if (!hd[0] && hd[1] && hd[1] == 234 &&
       hd[2] && hd[2] == 131 && hd[3] && hd[3] == 243)
    return (0);
  else
    return (1);
}

static void	init_header2(unsigned char *buffer, header_t *champ)
{
  int		i;
  int		j;
  unsigned char	c[4];

  i = 3;
  while (if_alpha(buffer[++i]))
    champ->prog_name[i - 4] = buffer[i];
  champ->prog_name[i - 4] = 0;
  j = 135;
  while (++j < 140)
    c[j - 136] = buffer[j];
  champ->prog_size = convert_size(c);
  i = 139;
  while (buffer[++i])
    champ->comment[i - 140] = buffer[i];
  champ->comment[i - 140] = 0;
}

header_t	*init_header(char *path, int *fd)
{
  unsigned char	*buffer;
  int		ret;
  header_t	*champ;

  buffer = xmalloc(2192);
  champ = xmalloc(sizeof(header_t));
  if ((*fd = open(path, O_RDONLY)) < 0)
    return (NULL);
  if ((ret = read(*fd, buffer, 2192)) != 2192)
    return (NULL);
  if (check_magic_number(buffer))
    return (NULL);
  init_header2(buffer, champ);
  return (champ);
}
