/*
** op.c for  korewar
**
** Made by Astek
** Login   <astek@epitech.net>
**
** Started on  Mon Mar 30 11:14:31 2009 Astek
** Last update	Thu Mar 30 12:37:40 2017 Jordan Bonaldi
*/

# include "project.h"

op_t    op_tab[] =
  {
    {"live", 1, {T_DIR}, 1, 10, "alive", 0x01, &live},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 0x02, &ld},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 0x03, &st},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 0x04, &add},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 0x05, &sub},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
     "et (and  r1, r2, r3   r1&r2 -> r3", 0x06, &and},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
     "ou  (or   r1, r2, r3   r1 | r2 -> r3", 0x07, &or},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
     "ou (xor  r1, r2, r3   r1^r2 -> r3", 0x08, &xor},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0x09, &zjmp},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
     "load index", 0x0a, &ldi},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
     "store index", 0x0b, &sti},
    {"fork", 1, {T_DIR}, 12, 800, "fork", 0x0c, &c_fork},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 0x0d, &lld},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
     "long load index", 0x0e, &lldi},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0x0f, &lfork},
    {"aff", 1, {T_REG}, 16, 2, "aff", 0x10, &aff},
    {0, 0, {0}, 0, 0, 0, 0, 0}
  };
