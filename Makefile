# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 03:35:01 by orekabe           #+#    #+#              #
#    Updated: 2022/10/20 20:01:39 by orekabe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = CC

CFLAGS = -Wall -Wextra -Werror

INC = -I/goinfre/orekabe/homebrew/opt/readline/include

RFLAGS = -lreadline -L/goinfre/orekabe/homebrew/opt/readline/lib

NAME = minishell

HEADERS = minishell.h libft/libft.h syntax_analyser/syntax_analyser.h lexer/lexer.h parser/parser.h builtins/builtins.h exec/exec.h

LIBFT_SRC = libft/ft_bzero.c libft/ft_calloc.c libft/ft_memcpy.c libft/ft_memmove.c \
	libft/ft_strndup.c libft/ft_strlen.c libft/ft_strncpy.c libft/ft_strncmp.c \
	libft/ft_lstnew.c libft/ft_lstadd_back.c libft/ft_lstclear.c libft/ft_substr.c \
	libft/ft_strjoin.c libft/ft_split.c libft/ft_strcmp.c libft/ft_isalpha.c \
	libft/ft_isdigit.c libft/ft_itoa.c libft/ft_atoi.c libft/ft_putstr_fd.c \
	libft/ft_putnbr_fd.c libft/ft_putchar_fd.c libft/ft_strdup.c libft/ft_lstsize.c \
	libft/ft_strstr.c libft/ft_strtrim.c

LEXER_SRC = lexer/get_clean_cmd.c lexer/lexer.c lexer/lexer_utils.c

PARSER_SRC = parser/parser.c parser/ast.c parser/heredoc.c

SYN_ANL = syntax_analyser/syntax_analyser.c syntax_analyser/put_err.c \
			syntax_analyser/check_flags.c syntax_analyser/check_valid_p.c \
			syntax_analyser/check_par.c

BLT_SRC = builtins/ft_env.c builtins/ft_builtadd_back.c builtins/ft_builtnew.c builtins/export/ft_export.c \
	builtins/print_env.c builtins/export/print_export.c builtins/builtins.c builtins/export/export_utils.c \
	builtins/ft_unset.c builtins/ft_pwd.c builtins/export/export_utils1.c builtins/ft_cd.c \
	builtins/del_list.c builtins/ft_echo.c builtins/exit/ft_exit.c builtins/export/check_env.c builtins/exit/exit_utils.c \
	builtins/signals/ctrl_c.c builtins/ft_builtsize.c builtins/exit/exit_status.c builtins/check_dir.c 

EXEC_SRC = exec/exec.c exec/expand.c exec/expand_utils.c exec/exec_cmd.c exec/pipe.c \
	exec/redirec.c exec/convert_toarr.c exec/and_or.c exec/expand_utils1.c exec/exec_cmd_utils.c \
	exec/wild_card.c exec/wild_card_utils.c exec/wild_card_substr.c

SRC = minishell.c minishell_utils.c free.c $(LIBFT_SRC) $(LEXER_SRC) $(SYN_ANL) $(PARSER_SRC) $(BLT_SRC) $(EXEC_SRC)

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(RFLAGS)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	
re: fclean all