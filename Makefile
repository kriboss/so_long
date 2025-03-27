# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/29 18:49:17 by kbossio           #+#    #+#              #
#    Updated: 2025/03/27 12:24:37 by kbossio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc -Wall -Wextra -Werror
INCLUDES = -Ilibft -I. -Iminilibx-linux
MLX_FLAGS = -lmlx -lX11 -lXext -lbsd
SRC = so_long.c so_long_utils.c parsing.c render.c movement.c
OBJS = $(SRC:.c=.o)

LIB = libft.a

%.o: %.c | make_mlx
	$(CC) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) | make_lib make_mlx
	$(CC) $(OBJS) -Llibft -lft -Lminilibx-linux $(MLX_FLAGS) -o $(NAME)

all: $(NAME)

bonus: all

clean:
	rm -f $(OBJS)
	make clean -C libft
	make clean -C minilibx-linux
	
fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	rm -rf minilibx-linux
	
re: fclean all

make_lib:
	make -C libft

make_mlx: minilibx-linux
	make -C minilibx-linux

minilibx-linux:
	@if [ ! -d "minilibx-linux" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git; \
	fi
.PHONY: all bonus clean fclean re make_mlx make_lib minilibx-linux
