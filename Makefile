# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mphobos <mphobos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/03 20:00:42 by mphobos           #+#    #+#              #
#    Updated: 2019/10/07 18:03:00 by mphobos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = main.c map.c val.c check_line.c convert_to_values.c free.c fill_window.c \
	set_coordinates.c change_coor.c rotation.c fill_line.c
LFT = libft
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
MLXLIB = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
INCLUDE = libft/includes

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -L libft -lft $(MLXLIB)

clean:
	make -C libft clean

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

run:
	./fdf

re: fclean all
