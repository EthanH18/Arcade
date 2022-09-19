##
## EPITECH PROJECT, 2022
## Arcade
## File description:
## Makefile
##

SRC_SNAKE	=	Nibbler/Nibbler.cpp

CPPFLAGS	= -fPIC -std=c++20

LDFLAGS		=	-shared

OBJ_SNAKE	=	$(SRC_SNAKE:.cpp=.o)

INC			=	../include

LIB_DIR		=	../lib/

LIB_SNAKE	=	arcade_nibbler.so

all: $(LIB_SNAKE)

$(LIB_SNAKE): $(OBJ_SNAKE)
	$(CC) $(CFLAGS) $(OBJ_SNAKE) -o $(LIB_SNAKE) $(LDFLAGS)
	mv $(LIB_SNAKE) $(LIB_DIR)


clean:
	$(RM) $(OBJ_SNAKE) 

fclean:	clean
	$(RM) $(LIB_DIR)$(LIB_SNAKE) 

re: fclean all

.PHONY: all clean fclean re