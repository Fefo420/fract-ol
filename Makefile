# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/25 11:29:09 by fileonar          #+#    #+#              #
#    Updated: 2025/02/01 19:25:15 by fileonar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

MLXFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

MLX_DIR = ./minilibx-linux/
MLX_LIB = $(MLX_DIR)libmlx.a

NAME = fractol
HEADER = fractol.h
SRC = main.c events.c init.c math_utils.c render.c string_utils.c utils.c

OBJS = $(SRC:.c=.o)

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)

%.o : %.c $(HEADER)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME):  $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(MLXFLAGS) $(HEADER) $(CFLAGS)
	 

clean:
	@rm -rf $(OBJS)
	@make clean -C $(MLX_DIR)
	@echo "Cleaned bin"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned $(NAME)"

re: fclean all

.PHONY: all clean fclean re