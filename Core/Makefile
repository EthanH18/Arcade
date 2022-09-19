##
## EPITECH PROJECT, 2022
## arcade
## File description:
## Makefile
##

NAME	=	arcade

SRC_CORE	=	Core.cpp	\
				Main.cpp

CFLAGS	=	-std=c++20 -Wall -Wextra -Werror -fPIC

LIBS	=	-ldl -lstdc++fs 

CC			=	g++

OBJ_CORE	=	$(SRC_CORE:.cpp=.o)

INC			=	../include

all: $(OBJ_CORE)
	$(CC) $(CFLAGS) $(OBJ_CORE) -o $(NAME) $(LIBS)
	mv $(NAME)	../

clean:
	$(RM) $(OBJ_CORE)

fclean:	clean
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re