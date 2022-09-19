##
## EPITECH PROJECT, 2022
## arcade
## File description:
## Makefile
##

NAME	=	arcade

all:	Core Lib Game

Core:
	$(MAKE) -C Core

Game:
	$(MAKE) -C Game

Lib:
	$(MAKE) -C Lib

clean:
	$(MAKE) -C Core clean
	$(MAKE) -C Game clean
	$(MAKE) -C Lib clean

fclean: clean
	$(MAKE) -C Core fclean
	$(MAKE) -C Game fclean
	$(MAKE) -C Lib fclean

re:	fclean all

.PHONY: all Core Game Lib clean fclean re
