##
## Makefile for tetris in /home/spiki/PSU_2016_tetris
##
## Made by etienne.filliat
## Login   <etienne.filliat@epitech.eu>
##
## Started on  Thu Feb 16 17:05:11 2017 etienne.filliat
## Last update Wed Dec 20 21:59:44 2017 mael drapier
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-W -Wall -Wextra -Werror
CFLAGS	+=	-I include/

LDFLAGS	=	-lncurses

NAME	=	tetris

SRCS	=	src/options.c \
		src/options_2.c \
		src/option_key.c \
		src/display.c \
		src/display_2.c \
		src/tetriminos.c \
		src/tetriminos2.c \
		src/check_tetriminos.c \
		src/useful.c \
		src/set_debug.c \
		src/show_debug.c \
		src/set_malloc.c \
		src/play_tetris.c \
		src/init_game.c \
		src/core_game.c \
		src/core_move.c \
		src/core_remove.c \
		src/modif_tetriminos.c \
		src/rotate_tetriminos.c \
		src/core_rotate.c \
		src/core_end.c \
		src/core_print.c \
		src/verif_params.c \
		src/color.c \
		src/get_next_line.c \
		src/main.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
