# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/12 12:06:47 by vkuzmyk           #+#    #+#              #
#    Updated: 2016/12/28 16:53:09 by vkuzmyk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRC =	main.c ft_check.c ft_blockcheck.c ft_check4.c ft_shift.c \
		ft_coordinate.c ft_map_gen.c ft_place_cheker.c ft_fillmap.c \
		ft_re_map.c ft_tetra.c ft_count_block.c ft_logic.c ft_strsplit.c \
		ft_putstr.c ft_putchar.c ft_bzero.c ft_strlen.c ft_memset.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o:%.c
	gcc $(FLAGS) -c -o $@ $<

$(NAME) : $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
