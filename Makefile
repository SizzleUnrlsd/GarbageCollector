##
## EPITECH PROJECT, 2023
## B-PSU-100-RUN-1-1-bsnavy-hugo.payet
## File description:
## Makefile
##

SRC	=	main.c

LIB	=	$(wildcard lib/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	garbage_collector

FLAGS 	=	-W -Wall -Wextra -Werror -g3

MEMORY_FLAGS	=	-Wpadded

all	:	$(OBJ)
	gcc -o $(NAME) $(FLAGS) $(SRC) $(LIB) $(MEMORY_FLAGS)

clean	:
	rm -f $(OBJ)
	rm -f a.out
	rm -f *.gcno
	rm -f *.gcda
	rm -f *.c~
	rm -f *.o

fclean	: clean
	rm -f $(NAME)

re	: fclean all
