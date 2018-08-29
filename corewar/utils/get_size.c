/*
** get_size.c for corewar in /home/benki/Epitech/CPE_2016_corewar/corewar
**
** Made by Lucas Benkemoun
** Login   <lucas.benkemoun@epitech.eu>
**
** Started on  Wed Mar 22 11:49:08 2017 Lucas Benkemoun
** Last update	Sun Mar 26 16:33:04 2017 Jordan Bonaldi
*/

#include "project.h"

static void		add_to_size3(unsigned char c, int *size)
{
  if ((c >> 0) & 1)
    *size += 16777216;
  if ((c >> 1) & 1)
    *size += 33554432;
  if ((c >> 2) & 1)
    *size += 67108864;
  if ((c >> 3) & 1)
    *size += 134217728;
  if ((c >> 4) & 1)
    *size += 268435456;
  if ((c >> 5) & 1)
    *size += 536870912;
  if ((c >> 6) & 1)
    *size += 1073741824;
  if ((c >> 7) & 1)
    *size += 2147483648;
}

static void		add_to_size2(unsigned char c, int *size)
{
  if ((c >> 0) & 1)
    *size += 65536;
  if ((c >> 1) & 1)
    *size += 131072;
  if ((c >> 2) & 1)
    *size += 262144;
  if ((c >> 3) & 1)
    *size += 524288;
  if ((c >> 4) & 1)
    *size += 1048576;
  if ((c >> 5) & 1)
    *size += 2097152;
  if ((c >> 6) & 1)
    *size += 4194304;
  if ((c >> 7) & 1)
    *size += 8388608;
}

static void		add_to_size(unsigned char c, int *size)
{
  if ((c >> 0) & 1)
    *size += 256;
  if ((c >> 1) & 1)
    *size += 512;
  if ((c >> 2) & 1)
    *size += 1024;
  if ((c >> 3) & 1)
    *size += 2048;
  if ((c >> 4) & 1)
    *size += 4096;
  if ((c >> 5) & 1)
    *size += 8192;
  if ((c >> 6) & 1)
    *size += 16384;
  if ((c >> 7) & 1)
    *size += 32768;
}

int		convert_size(unsigned char c[4])
{
  int		size;

  size = c[3];
  add_to_size(c[2], &size);
  add_to_size2(c[1], &size);
  add_to_size3(c[0], &size);
  return (size);
}
