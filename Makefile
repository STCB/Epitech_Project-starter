##
## EPITECH PROJECT, 2021
## projet archi (Workspace)
## File description:
## Makefile
##

SRC			=			builder.c	\
						createmakefiles.c	\
						createcfiles.c

NAME		=			BOB

all:
						gcc $(SRC) -o $(NAME)

clean:
						rm $(NAME)

fclean:					clean
						rm -rf tests/
						mkdir tests

re:						fclean all

reexec:					re
						./$(NAME)

val:
						clear
						$(fclean)
						gcc $(SRC) -g3 -o $(NAME)
						valgrind ./$(NAME)

reval:					fclean val