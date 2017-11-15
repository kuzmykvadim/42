# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/11 21:02:46 by vkuzmyk           #+#    #+#              #
#    Updated: 2017/06/03 23:41:17 by vkuzmyk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
	  put_img.c \
	  ft_init.c  \
	  ft_parsing.c \
	  ft_help.c \
	  ft_init_obj.c \
	  ft_ray_trace.c \
	  ft_light.c \
	  ft_key_hook.c \
	  ft_sphere.c \
	  ft_cone.c \
	  ft_cylinder.c \
	  ft_plane.c \
	  ft_matrix.c \
	  ft_rotation.c \


OBJ = $(SRC:.c=.o)

NAME = RTv1

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
