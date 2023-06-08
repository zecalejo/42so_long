# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 20:52:24 by jnuncio-          #+#    #+#              #
#    Updated: 2023/06/08 20:57:37 by jnuncio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BIN	= bin
INCLFT = libft/include
LIBFT = libft/
LIBFT_BIN = libft/libft.a
INCMLX = /usr/include
LIBMLX = /usr/lib
MLX_LINUX = mlx_linux/
MLX_BIN = mlx_linux/libmlx.a
UNAME := $(shell uname)
CFLAGS = -Wall -Wextra -Werror -I$(INCMLX) -Imlx_linux -I$(INCLFT) -Iinclude -g
LFLAGS = -L$(MLX_LINUX) -lmlx_Linux -L$(LIBMLX) -lmlx -L$(LIBFT) -lft -fsanitize=address
RM = rm -rf
SRC = $(addprefix src/, main.c\
	window.c\
	image.c\
	map.c\
	checker.c\
	draw.c\
	sprite.c\
	events.c\
	utils.c)
OBJ = $(SRC:src/%c=bin/%o)

ifeq ($(UNAME), Darwin)
	CC = gcc
	LFLAGS += -framework OpenGL -frameqork AppKit
else ifeq ($(UNAME), FreeBSD)
	CC = clang
else
	CC = gcc
	LFLAGS += -lXext -lX11 -lm -lz
endif

all: $(MLX_LINUX) $(LIBFT) $(NAME) 

$(NAME): $(BIN) $(OBJ)
	$(CC) $(OBJ) $(LFLAGS) -o $(NAME)

$(BIN):
	@mkdir -p $(BIN)

$(LIBFT): $(LIBFT_BIN)
	@make all -C libft --no-print-directory

$(MLX_LINUX): $(MLX_BIN)
	@make -C mlx_linux > /dev/null 2>&1

$(BIN)/%o: src/%c
	$(CC) -c $< $(CFLAGS) -o $@

clean:
	$(RM) $(OBJ) $(BIN)

fclean: clean
	$(RM) $(NAME)

cleanlib:
	@make clean -C libft

fcleanlib:
	@make fclean -C libft
	@make clean -C mlx_linux > /dev/null 2>&1
	
ffclean: fclean fcleanlib

re: ffclean all

.PHONY: all clean fclean cleanlib fcleanlib ffclean re $(LIBFT_BIN) $(MLX_BIN)