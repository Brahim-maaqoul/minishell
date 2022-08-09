/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:14:50 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/08/09 22:48:12 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <sys/stat.h>
#include <signal.h>

typedef enum    token
{
    PIPE = '|',
    left_red = '<',
    right_red = '>',
    space = ' ',
    word
}	tokens;

typedef struct s_list
{
    int pid;
    char    *line;
    char    *content;
    char    **path;
    char    **splited;
	char 	*name;
	char 	*value;
    tokens  flags;
    struct	s_list	*next;
}       t_list;

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *str, int c);
int	ft_atoi(const char	*str);
int	ft_isdigit(int n);
int ft_lstsize(t_list *lst);
void ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content, tokens flag);
void	ft_lstadd_back(t_list **lst, t_list *new);
int	check_pipe(t_list *list, int i);
int	check_leftred(t_list *list, int i);
int	check_rightred(t_list *list, int i);
int	check_space(t_list *list, int i);
void	check_word(t_list *list);
void    get_tokens(t_list *list);


# endif