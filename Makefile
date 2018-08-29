##
## Makefile for Makefile in /home/Neferett/Makefile
##
## Made by Bonaldi Jordan
## Login   <Neferett@epitech.net>
##
## Started on  Fri Oct 14 12:57:09 2016 Bonaldi Jordan
## Last update Mon Feb 13 17:31:41 2017 Jordan Bonaldi
##

all:
		make -C asm/
		make -C corewar/

clean:
		make -C asm/ clean
		make -C corewar/ clean

fclean:
	  make -C asm/ fclean
		make -C corewar/ fclean

re:	fclean all

auteur:
	echo $(USER) > auteur

.PHONY: all clean fclean re
