/*
** project.h for project_header in /home/Neferett/bin/IMPORT/include
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Nov 21 01:13:04 2016 Bonaldi Jordan
** Last update	Sat Mar 25 17:01:21 2017 Jordan Bonaldi
*/

#ifndef H_CHECK
# define H_CHECK

# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include "op.h"
# include "lib.h"

typedef char reg;
typedef char binary;
typedef size_t	binary_size;
typedef t_string type_arg;

typedef struct		s_prog
{
  t_string				*l_name;
  t_string				**l_arg;
  type_arg				**types;
  t_string				*str;
  reg					 		line;
  binary					*bin;
  int   					size;
  int							argsnb;
}									t_prog;

typedef struct		s_asm
{
  int							count;
  t_string				*name;
  char		    		*prog_name;
  char	   		  	*prog_desc;
  t_prog					**prog;
}									t_asm;

void			handle_label(t_prog **, t_prog **, t_asm *);
boolean 	is_good_line(reg code);
void				my_memset(char *str, char c, int size);
void			pr(char *str, int size);
void			asm_handle(t_asm *asm, int *, t_asm *, binary *);
reg						get_size(t_prog *, int count);
void			write_header(t_asm *asm, int size, t_asm *);
t_string		*get_output(char *str);
void				check_errors(t_asm *asm);
reg						get_id(type_arg *cmd);
type_arg			*get_good_type(args_type_t **cmd, int i);
t_string		**stock_args(t_string *str, char **cmd, int *);
t_prog				*init_prog(t_string *l_name, t_string **l_arg,
    t_string **types, reg rg);
type_arg		**stock_types(args_type_t **cmd);
void		check_line(t_asm *, char **, char *);
void		my_exit(char *, char *, int);
t_asm		*asm_init(char *);
boolean			handle_basic_command(t_asm *, char *);
int			count_instruct(char *);
void		*xmalloc(size_t);
void		read_file(t_asm *);
char 		*delete_space(char *);
int			print_help();
char			*get_it(char *str, int size);

#endif
