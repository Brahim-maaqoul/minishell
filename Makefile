CC = cc

LDFLAGS= -L/Users/bmaaqoul/.brew/opt/readline/lib
CPPFLAGS= -I/Users/bmaaqoul/.brew/opt/readline/include

CFLAGS = $(CPPFLAGS) -Wall -Werror -Wextra -g

INC = -I./include

HEADERS = include/minishell.h include/libft.h include/lexer.h

ODIR = obj

LIBFT_SRC = libft/ft_bzero libft/ft_calloc libft/ft_memcpy libft/ft_memmove \
    libft/ft_strndup libft/ft_strlen libft/ft_strncpy libft/ft_lstnew libft/ft_lstclear \
	ft_lstadd_back

LEXER_SRC = lexer/get_clean_cmd lexer/lexer

FILES = minishel $(LIBFT_SRC) $(LEXER_SRC)

OBJ = $(addprefix $(ODIR)/, $(FILES:=.o))

NAME = minishell

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -lreadline $(LDFLAGS) $^ -o $@

$(ODIR)/%.o: %.c $(HEADERS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all