##
## EPITECH PROJECT, 2022
## Arcade
## File description:
## Makefile
##

SRC_SFML	=	Sfml.cpp

SRC_SDL		=	Sdl.cpp

SRC_NCURSES	=	Ncurses.cpp

CPPFLAGS	= -fPIC -std=c++20

LDFLAGS		=	-shared

OBJ_SFML	=	$(SRC_SFML:.cpp=.o)

OBJ_SDL		=	$(SRC_SDL:.cpp=.o)

OBJ_NCURSES	=	$(SRC_NCURSES:.cpp=.o)

INC			=	../include

LIB_DIR		=	../lib/

LIB_SFML		=	arcade_sfml.so

LIB_SDL		=	arcade_sdl2.so

LIB_NCURSES	=	arcade_ncurses.so

all: $(LIB_NCURSES) $(LIB_SDL) $(LIB_SFML)

$(LIB_SFML): $(OBJ_SFML)
	$(CC) $(CFLAGS) $(OBJ_SFML) -o $(LIB_SFML) $(LDFLAGS) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
	mv $(LIB_SFML) $(LIB_DIR)

$(LIB_SDL): $(OBJ_SDL)
	$(CC) $(CFLAGS) $(OBJ_SDL) -o $(LIB_SDL) $(LDFLAGS)  -lSDL2 -lSDL2_image -lSDL2_ttf `sdl2-config --cflags --libs`
	mv $(LIB_SDL) $(LIB_DIR)

$(LIB_NCURSES): $(OBJ_NCURSES)
	$(CC) $(CFLAGS) $(OBJ_NCURSES) -o $(LIB_NCURSES) $(LDFLAGS) -lncurses
	mv $(LIB_NCURSES) $(LIB_DIR)

clean:
	$(RM) $(OBJ_NCURSES) 
	$(RM) $(OBJ_SDL) 
	$(RM) $(OBJ_SFML)

fclean:	clean
	$(RM) $(LIB_DIR)$(LIB_NCURSES)
	$(RM) $(LIB_DIR)$(LIB_SDL)
	$(RM) $(LIB_DIR)$(LIB_SFML)

re: fclean all

.PHONY: all clean fclean re