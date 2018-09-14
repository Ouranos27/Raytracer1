##
## Makefile for Makefile in /home/ouranos27/my_desktop/C_Graphical_Prog/bswolf3d
## 
## Made by philippe kam
## Login   <philippe.kam@epitech.eu>
## 
## Started on  Wed Dec 21 19:57:42 2016 philippe kam
## Last update Fri Feb 24 10:34:11 2017 philippe kam
##

CC	=	gcc -g -g3

CFLAGS	+=	-Wall -Wextra -lc_graph_prog_full -lm -I./include

SRC	=	my_put_pixel.c		\
		window.c		\
		drawers.c		\
		moves.c			\
		src/plane.c		\
		src/calc_dir_vector.c	\
		src/sphere.c		\
		src/cylinder.c		\
		src/cone.c		\
		src/light.c		\
		src/utils.c		\
		src/translate.c		\
		src/rotate.c		\
		src/moebius.c		\
		finders.c		\
		my_put_obj.c

OBJ	=	$(SRC:.c=.o)

NAME    =       raytracer1

all:            $(NAME)

$(NAME):        $(OBJ)
		@$(CC) -g $(SRC) -o $(NAME) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:         clean
		rm -f $(NAME)

re:             fclean all

.PHONY:         re fclean all clean
