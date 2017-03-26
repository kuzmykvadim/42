# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/11 21:02:46 by vkuzmyk           #+#    #+#              #
#    Updated: 2017/03/26 11:57:47 by vkuzmyk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c put_img.c colors.c key_hooks.c key_h_init.c \
	  burn_ship.c newton.c tricorn.c mandelbrot.c julia.c menu.c

OBJ = $(SRC:.c=.o)

NAME = fractal

FLAGS = -Wall -Wextra -Werror 

CC = gcc

all: lib $(OBJ)
	$(CC) $(FLAGS) $(SRC) -lmlx -framework OpenGL -framework AppKit libft/libft.a -o $(NAME) 

$(NAME): all

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS) 

re: relib fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

lib: 
	make -C libft

relib:
	make -C libft re
