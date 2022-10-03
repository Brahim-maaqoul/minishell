# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 03:35:01 by orekabe           #+#    #+#              #
#    Updated: 2022/10/03 03:47:53 by bmaaqoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = CC

CFLAGS = -Wall -Wextra -Werror

INC = -I/goinfre/bmaaqoul/.brew/opt/readline/include

RFLAGS = -lreadline -L/goinfre/bmaaqoul/.brew/opt/readline/lib

NAME = minishell

HEADERS = minishell.h libft/libft.h lexer/lexer.h builtins/builtins.h

LIBFT_SRC = libft/ft_bzero.c libft/ft_calloc.c libft/ft_memcpy.c libft/ft_memmove.c \
	libft/ft_strndup.c libft/ft_strlen.c libft/ft_strncpy.c libft/ft_strncmp.c \
	libft/ft_lstnew.c libft/ft_lstadd_back.c libft/ft_lstclear.c libft/ft_substr.c \
	libft/ft_strjoin.c libft/ft_split.c libft/ft_strcmp.c libft/ft_isalpha.c \
	libft/ft_isdigit.c libft/ft_itoa.c libft/ft_atoi.c libft/ft_putstr_fd.c \
	libft/ft_putnbr_fd.c libft/ft_putchar_fd.c libft/ft_strdup.c

LEXER_SRC = lexer/get_clean_cmd.c lexer/lexer.c

SYN_ANL = syntax_analyser/syntax_analyser.c syntax_analyser/put_err.c syntax_analyser/check_flags.c \
	syntax_analyser/check_par.c syntax_analyser/check_valid_p.c

EXC_SRC = builtins/ft_env.c builtins/ft_builtadd_back.c builtins/ft_builtnew.c builtins/export/ft_export.c \
	builtins/print_env.c builtins/export/print_export.c builtins/builtins.c builtins/export/export_utils.c \
	builtins/ft_unset.c builtins/ft_pwd.c builtins/export/export_utils1.c builtins/ft_cd.c \
	builtins/del_list.c builtins/ft_echo.c builtins/exit/ft_exit.c builtins/export/check_env.c builtins/exit/exit_utils.c \
	builtins/signals/ctrl_c.c

SRC = minishell.c $(LIBFT_SRC) $(LEXER_SRC) $(SYN_ANL) $(EXC_SRC)

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(RFLAGS) $^ -o $@

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	
re: fclean all