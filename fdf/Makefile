# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/11 21:02:46 by vkuzmyk           #+#    #+#              #
#    Updated: 2017/03/06 11:02:05 by vkuzmyk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c parsing.c \
	  put_img.c ft_env.c \
	  isometric.c \
	  key_hooks.c \
	  rotation.c \
	  menu.c \
	  call_isom.c

OBJ = $(SRC:.c=.o)

NAME = fdf

FLAGS = -Wall -Wextra -Werror 

CC = gcc

all: lib $(OBJ)
	$(CC) $(FLAGS) $(SRC) -lmlx -framework OpenGL -framework AppKit libft/libft.a -o  $(NAME) 

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
