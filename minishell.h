/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:14:50 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/08/04 23:24:17 by bmaaqoul         ###   ########.fr       */
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
    space = ' '
    // word
}	tokens;

typedef struct s_mystruct
{
    int pid;
    char    *line;
    char *word;
    char    **path;
    char    **splited;
    tokens  flags;
    struct s_mystruct *left;
    struct s_mystruct *right;
}       t_mystruct;

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
int	ft_strncmp(const char *s1, const char *s2, size_t n);


# endif