/*
** op.h for  korewar
**
** Made by Astek
** Login   <astek@epitech.net>
**
** Started on  Mon Mar 30 11:14:31 2009 Astek
** Last update	Sun Apr 02 23:43:20 2017 Jordan Bonaldi
*/

#ifndef _OP_H_
# define _OP_H_

# define MEM_SIZE                (6*1024)
# define IDX_MOD                 512
# define MAX_ARGS_NUMBER         4
# define COMMENT_CHAR            '#'
# define LABEL_CHAR              ':'
# define DIRECT_CHAR             '%'
# define SEPARATOR_CHAR          ','
# define LABEL_CHARS             "abcdefghijklmnopqrstuvwxyz_0123456789-"
# define NAME_CMD_STRING         				".name"
# define NAME_CMD_STRING_LENGTH         5
# define COMMENT_CMD_STRING      				".comment"
# define COMMENT_CMD_STRING_LENGTH      8
# define REG_NUMBER      16
# define T_REG           1
# define T_DIR           2
# define T_IND           4
# define T_LAB           8
# define REG_SIZE        1
# define IND_SIZE        2
# define DIR_SIZE        4
# define PROG_NAME_LENGTH        132
# define COMMENT_LENGTH          2052
# define COREWAR_EXEC_MAGIC      0xea83f3
# define CYCLE_TO_DIE    1536
# define CYCLE_DELTA     5
# define NBR_LIVE        40

typedef struct op_s     op_t;
typedef char    args_type_t;
typedef int	hex;
typedef struct header_s header_t;

struct  op_s
{
   char         *mnemonique;
   char         nbr_args;
   args_type_t  type[MAX_ARGS_NUMBER];
   char         code;
   int          nbr_cycles;
   char         *comment;
   hex					hex;
};

struct header_s
{
   int  magic;
   char prog_name[PROG_NAME_LENGTH + 1];
   int  prog_size;
   char comment[COMMENT_LENGTH + 1];
};

extern  op_t    op_tab[];

#endif
