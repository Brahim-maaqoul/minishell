# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 03:35:01 by orekabe           #+#    #+#              #
#    Updated: 2022/08/14 04:05:47 by orekabe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = CC

CFLAGS = -Wall -Wextra -Werror

RFLAGS = -lreadline

NAME = minishell

HEADERS = minishell.h libft/libft.h lexer/lexer.h

LIBFT_SRC = libft/ft_bzero.c libft/ft_calloc.c libft/ft_memcpy.c libft/ft_memmove.c \
	libft/ft_strdup.c libft/ft_strlen.c libft/ft_strncpy.c

LEXER_SRC = lexer/get_clean_cmd.c lexer/lexer.c

SRC = minishell.c $(LIBFT_SRC) $(LEXER_SRC)

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(RFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	
re: fclean all