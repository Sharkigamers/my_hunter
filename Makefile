##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for comiling all
##

SRC	=	src/my_hunter.c	\
		src/window.c	\
		src/sound.c	\
		src/annex_my_hunter.c	\
		src/ini_sprite.c	\
		src/event.c	\
		src/bird.c	\
		src/scope.c	\
		src/bar.c	\
		src/hit_box_menu.c	\
		src/annex_menu.c	\

OBJ     =	$(SRC:.c=.o)

LIB     =	-L./lib/my -lmy

CSFML	=	-lcsfml-audio -lcsfml-window -lcsfml-system -lcsfml-graphics

CPPFLAGS	=	-I./include/ -Wall -Wextra

NAME	=	my_hunter

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib/my && make
	cd ../../
	gcc -o $(NAME) $(SRC) $(LIB) $(CSFML) $(CPPFLAGS)

clean:
	rm -f $(OBJ)
	cd src/ && rm -f $(OBJ)
	cd lib/my && make clean

fclean: clean
	rm -f $(NAME)
	cd src/ && rm -f $(OBJ)
	cd lib/my && make fclean

re:	fclean all

.PHONY: all clean fclean uclean re
