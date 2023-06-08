# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/16 15:39:50 by jnuncio-          #+#    #+#              #
#    Updated: 2023/06/08 20:27:30 by jnuncio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
BIN = bin
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
AR = ar -rcs
RM = rm -rf
SRC = ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_strlen.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_itoa.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c\
	get_next_line_utils_bonus.c\
	get_next_line_bonus.c
OBJ = $(SRC:%c=bin/%o)

all: $(NAME)

$(NAME): $(BIN) $(OBJ)
	@$(AR) $(NAME) $(OBJ)

$(BIN):
	@mkdir -p $(BIN)

$(BIN)/%o: %c
	@$(CC) -c $< $(CFLAGS) -o $@

clean:
	@$(RM) $(OBJ) $(BIN)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
