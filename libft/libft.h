/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 02:37:13 by orekabe           #+#    #+#             */
/*   Updated: 2022/10/20 17:18:10 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <paths.h>
# include <signal.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <dirent.h>

typedef struct s_glob
{
	int		ex_st;
	int		cp;
	int		gl;
	char	*name;
}				t_glob;

typedef struct s_list
{
	void			*content;
	int				token;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

t_glob	g_glob;

int		ft_strlen(char *str);
void	ft_bzero(void *s, int n);
void	*ft_calloc(int count, int size);
char	*ft_strndup(char *s, int size);
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_strcmp(char	*s1, char	*s2);
char	*ft_strncpy(char *src, char *dst, int size);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memcpy(void *dst, const void *src, int n);
void	*ft_memmove(void *dst, const void *src, int len);
t_list	*ft_lstnew(void *content, int token);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list *lst);
int		ft_lstsize(t_list *lst);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int n);
int		ft_isalpha(int ch);
char	*ft_itoa(int n);
int		ft_atoi(char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strdup(char *s);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strtrim(char *s1, char *set);

#endif