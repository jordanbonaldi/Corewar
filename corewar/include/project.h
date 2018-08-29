/*
** project.h for project_header in /home/Neferett/bin/IMPORT/include
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Nov 21 01:13:04 2016 Bonaldi Jordan
** Last update	Sun Apr 02 22:15:15 2017 Jordan Bonaldi
*/

#ifndef H_CHECK
# define H_CHECK

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "lib.h"
# include "op.h"

typedef struct s_vm t_vm;
typedef struct s_prog t_prog;

typedef struct		s_params
{
  char						*(*get_instr)(t_vm *, int);
  char						*(*get_params)(t_prog *, t_vm *);
  char						(*get_first)(t_prog *, t_vm *);
  int						  *(*set_type)(struct s_params *);
  boolean					(*set_params)(struct s_params *,
      t_prog *, t_vm *);
  void						(*set_instr)(struct s_params *, t_vm *, int);
  boolean					(*set_mem)(t_prog *prog);
  boolean					(*v1)(t_prog *);
  boolean	  			(*v)(t_prog *);
  char						*p;
  char						*t;
  int							*type;
  int							r[REG_NUMBER];
}									t_params;

struct		s_prog
{
  header_t				*header;
  char						*prog;
  int							id;
  int							id_n;
  int							instr;
  int							load;
  int							ocp;
  int							pc;
  int							exec;
  int							nblives;
  int							carry;
  int							addr;
  boolean					dead;
  t_params				*p;
  struct s_prog *	next;
};

struct		s_vm
{
  int							dump;
  int							pos;
  int							last;
  int							die;
  unsigned char		mem[MEM_SIZE];
  unsigned char		memc[MEM_SIZE];
  int							champnb;
  int							livenb;
  t_prog					*prog;
};

struct  op_s
{
   char         *mnemonique;
   char         nbr_args;
   args_type_t  type[MAX_ARGS_NUMBER];
   char         code;
   int          nbr_cycles;
   char         *comment;
   hex					hex;
   void			    (*instr)(t_vm *, t_prog *);
};

typedef struct op_s     op_t;

extern  op_t    op_tab[];

void			kill_champ(t_vm *vm);
void				aff(t_vm *vm, t_prog *prog);
void				add(t_vm *vm, t_prog *prog);
void				sub(t_vm *vm, t_prog *prog);
void				zjmp(t_vm *vm, t_prog *prog);
void				or(t_vm *vm, t_prog *prog);
void				xor(t_vm *vm, t_prog *prog);
void				sti(t_vm *vm, t_prog *prog);
void				st(t_vm *vm, t_prog *prog);
void				ld(t_vm *vm, t_prog *prog);
void				lld(t_vm *vm, t_prog *prog);
void				ldi(t_vm *vm, t_prog *prog);
void				lldi(t_vm *vm, t_prog *prog);
void				lfork(t_vm *vm, t_prog *prog);
void				c_fork(t_vm *vm, t_prog *prog);
void				and(t_vm *vm, t_prog *prog);
void			  live(t_vm *vm, t_prog *prog);
int		handle_dir_param(t_vm *vm, int memzone);
int		handle_reg_param(t_vm *vm, int memzone);
int		handle_ind_param(t_vm *vm, int memzone);
boolean			set_new_mem_place(t_prog *prog);
char			*get_p(t_prog *prog, t_vm *vm);
boolean			set_p(t_params *params, t_prog *prog, t_vm *vm);
void				set_instruction(t_params *params, t_vm *vm, int addr);
char				*get_instruction(t_vm *vm, int addr);
int					*set_type(t_params *params);
char			get_first_param(t_prog *prog, t_vm *vm);
t_prog			*handle_dead(t_prog *prog);
void		put_reg(t_prog *prog, int in, int to_reg);
void		modify_carry(t_prog *prog, int pos);
int			get_pos_from_char(t_prog *prog, int pos);
void		print_memory(t_vm *vm);
char			*get_last_name(t_vm *vm);
boolean			is_ok(t_prog	*prog);
boolean		is_valid(t_prog *prog);
boolean		all_dead(t_vm *vm);
void  			reverse_list(t_vm *vm);
boolean			is_valid2(t_prog *prog);
void			add_prog_to_list_prog(t_vm *vm, t_prog *prog, boolean);
int			check_pc(t_prog *prog);
int				mem_load(t_vm *vm, int size, int addr);
void			put_champ_mem(t_vm *, int);
void			add_prog_to_list(t_vm *, int nb, int load, char *path);
void			check_arguments(int ac, char **argv, t_vm *vm);
int	  	  reverse_byte(int nb);
void			*xmalloc(size_t);
int				print_help(char *);
boolean		is_big_endian();
header_t	*init_header(char *, int *);
int       convert_size(unsigned char c[4]);
boolean		is_register(t_prog *prog, int nb_of_reg);
boolean		is_register_pos(t_prog *prog, int pos);
boolean		is_register_pos_mem(unsigned char mem[MEM_SIZE], int pos);
int						get_id(t_string *cmd);
void			start_vm(t_vm *vm);
void				my_memset(char *str, char c, int size);

#endif
