# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 03:35:01 by orekabe           #+#    #+#              #
#    Updated: 2022/09/26 02:13:14 by orekabe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = CC

CFLAGS = -Wall -Wextra -Werror

RFLAGS = -lreadline

NAME = minishell

HEADERS = minishell.h libft/libft.h lexer/lexer.h parser/parser.h

LIBFT_SRC = libft/ft_bzero.c libft/ft_calloc.c libft/ft_memcpy.c libft/ft_memmove.c \
	libft/ft_strndup.c libft/ft_strlen.c libft/ft_strncpy.c libft/ft_strncmp.c \
	libft/ft_strjoin.c libft/ft_lstnew.c libft/ft_lstadd_back.c libft/ft_lstclear.c \

LEXER_SRC = lexer/get_clean_cmd.c lexer/lexer.c

PARSER_SRC = parser/parser.c parser/ast.c

SYN_ANL = syntax_analyser/syntax_analyser.c syntax_analyser/put_err.c \
			syntax_analyser/check_flags.c syntax_analyser/check_valid_p.c \
			syntax_analyser/check_par.c

SRC = minishell.c $(LIBFT_SRC) $(LEXER_SRC) $(SYN_ANL) $(PARSER_SRC)

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(RFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	
re: fclean all