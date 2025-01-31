# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/29 18:49:17 by kbossio           #+#    #+#              #
#    Updated: 2025/01/31 01:40:50 by kbossio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc -Wall -Wextra -Werror
INCLUDES = -Ilibft -I.
MLX_FLAGS = -lmlx -lX11 -lXext -lbsd
SRC = so_long.c so_long_utils.c parsing.c render.c
OBJS = $(SRC:.c=.o)

LIB = libft.a

%.o: %.c
	$(CC) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) MAKE_LIB
	$(CC) $(OBJS) -Llibft -lft $(MLX_FLAGS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C libft
	
fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	
re: fclean all

MAKE_LIB:
	make -C libft

.PHONY: all clean fclean re