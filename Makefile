# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 03:35:01 by orekabe           #+#    #+#              #
#    Updated: 2022/10/02 00:03:06 by bmaaqoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = CC

CFLAGS = -Wall -Wextra -Werror

RFLAGS = -lreadline

NAME = minishell

HEADERS = minishell.h libft/libft.h lexer/lexer.h execution/execution.h

LIBFT_SRC = libft/ft_bzero.c libft/ft_calloc.c libft/ft_memcpy.c libft/ft_memmove.c \
	libft/ft_strndup.c libft/ft_strlen.c libft/ft_strncpy.c libft/ft_strncmp.c \
	libft/ft_lstnew.c libft/ft_lstadd_back.c libft/ft_lstclear.c libft/ft_substr.c \
	libft/ft_strjoin.c libft/ft_split.c libft/ft_strcmp.c libft/ft_isalpha.c \
	libft/ft_isdigit.c libft/ft_itoa.c libft/ft_atoi.c libft/ft_putstr_fd.c \
	libft/ft_putnbr_fd.c libft/ft_putchar_fd.c libft/ft_strdup.c

LEXER_SRC = lexer/get_clean_cmd.c lexer/lexer.c

SYN_ANL = syntax_analyser/syntax_analyser.c syntax_analyser/put_err.c syntax_analyser/check_flags.c \
	syntax_analyser/check_par.c syntax_analyser/check_valid_p.c

EXC_SRC = execution/ft_env.c execution/ft_execadd_back.c execution/ft_execnew.c execution/export/ft_export.c \
	execution/print_env.c execution/export/print_export.c execution/builtins.c execution/export/export_utils.c \
	execution/ft_unset.c execution/ft_pwd.c execution/export/export_utils1.c execution/ft_cd.c \
	execution/del_list.c execution/ft_echo.c execution/exit/ft_exit.c execution/export/check_env.c execution/exit/exit_utils.c \

SRC = minishell.c $(LIBFT_SRC) $(LEXER_SRC) $(SYN_ANL) $(EXC_SRC)

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(RFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	
re: fclean all