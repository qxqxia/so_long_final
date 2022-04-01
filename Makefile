# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 10:52:43 by qxia              #+#    #+#              #
#    Updated: 2022/04/01 09:57:33 by qxia             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

DEBUG = -fsanitize=address -g3

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

SRC = src/images.c \
	  src/so_long.c \
	  src/check_arguments.c\
	  src/check_map.c \
	  movement/key_mouse_event.c \
	  movement/move_horizontal.c \
	  movement/move_vertical.c \
	  src/so_long_utils.c \
	  src/fini_game.c \
	  gnl/get_next_line.c \
	  gnl/get_next_line_utils.c \

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME)

debug : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME) $(DEBUG)

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re: fclean all

%.o:%.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

.PHONY: all clean fclean re
