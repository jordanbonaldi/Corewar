##
## Makefile for Makefile in /home/Neferett/Makefile
##
## Made by Bonaldi Jordan
## Login   <Neferett@epitech.net>
##
## Started on  Fri Oct 14 12:57:09 2016 Bonaldi Jordan
## Last update Sun Mar 26 17:05:38 2017 Lucas Benkemoun
##

SRC	=	main.c\
			op.c\
			events/check_validity.c\
			events/add_aff_sub_zjmp.c\
			events/forks.c\
			events/ld.c\
			events/live_and_or_xor.c\
			events/st.c\
			handler/handle_vm.c\
			handler/handle_dead.c\
			handler/handle_params.c\
			handler/handle_checker.c\
			handler/handle_instructions.c\
			handler/handle_reg_params.c\
			utils/get_size.c\
			utils/utils.c \
			utils/utils_events.c\
			utils/utils_mem.c\
			utils/utils_args.c\
			utils/init_header.c\
			utils/utils_list.c\
			utils/utils_help.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	corewar

CC	=	gcc

LIB	=	lib/others/my_strlen.c			\
		lib/others/my_strupcase.c		\
		lib/others/my_swap.c			\
		lib/others/my_str_islower.c		\
		lib/others/my_str_isupper.c		\
		lib/others/my_str_isalpha.c		\
		lib/others/my_str_isprintable.c		\
		lib/others/my_str_isnum.c		\
		lib/others/my_getnbr.c			\
		lib/others/my_getnbr_base.c		\
		lib/others/my_strdup.c			\
		lib/others/my_itoa.c			\
		lib/others/my_strlowcase.c		\
		lib/others/nb_of.c			\
		lib/others/my_strcmp.c			\
		lib/others/my_strncmp.c			\
		lib/others/my_strcat.c			\
		lib/others/my_strcpy.c			\
		lib/others/my_strncat.c			\
		lib/others/my_revstr.c			\
		lib/others/my_epur_str.c		\
		lib/others/get_next_line.c		\
		lib/others/get_next_line2.c		\
		lib/others/my_str_to_wordtab.c		\
                lib/others/my_putnbru_base.c            \
                lib/others/my_putnbruh_base.c           \
                lib/others/my_putnbrul_base.c           \
                lib/others/my_putu_nbr.c                \
                lib/others/my_putul_nbr.c               \
                lib/others/my_putuh_nbr.c               \
                lib/others/my_putl_nbr.c                \
                lib/others/my_puth_nbr.c                \
                lib/others/specific_print.c		\
		lib/others/mil_convert.c	        \
		lib/others/mil_convertu.c		\
                lib/others/msl.c                        \
                lib/others/my_advanced_sort_wordtab.c   \
                lib/others/my_capitalize.c              \
                lib/others/my_fact_rec.c                \
                lib/others/my_find_prime_sup.c          \
                lib/others/my_isneg.c                   \
                lib/others/my_is_prime.c                \
                lib/others/my_power_rec.c               \
                lib/others/my_putnbr_base.c             \
                lib/others/my_put_nbr.c                 \
                lib/others/my_putstr.c			\
                lib/others/my_show_wordtab.c            \
                lib/others/my_sort_int_tab.c            \
                lib/others/my_sort_wordtab.c            \
                lib/others/my_square_root.c             \
		lib/printf/my_printf.c			\
		lib/printf/methods/chars_methods.c	\
		lib/printf/methods/int_methods.c	\
		lib/printf/methods/methods.c		\
		lib/printf/methods/others.c		\
		lib/printf/utils/utils.c		\
		lib/printf/utils/utils_checker.c	\
		lib/printf/utils/utils_methods.c	\
		lib/printf/utils/params.c		\
		lib/printf/utils/init.c			\
		lib/printf/utils/utils_setter.c		\
		lib/string_lib/init_string.c		\
		lib/string_lib/methods/length.c		\
		lib/string_lib/methods/print.c		\
		lib/string_lib/methods/capitalize.c	\
		lib/string_lib/methods/num.c		\
		lib/string_lib/methods/cat_and_cut.c	\
		lib/string_lib/methods/recreate.c	\
		lib/string_lib/methods/equals.c		\

OBJSLIB =       $(LIB:.c=.o)

CFLAGS  += -Wextra -Wall -Werror

CFLAGS  += -ansi -pedantic

CFLAGS  += -Iinclude/lib/ -Iinclude/

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJSLIB) $(OBJ)
	ar rc lib/libmy.a $(OBJSLIB)
	$(CC) $(OBJ) -o $(NAME) -Llib/ -lmy

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJSLIB)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur

.PHONY: all clean fclean re
