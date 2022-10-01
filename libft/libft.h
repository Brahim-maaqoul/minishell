/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 02:37:13 by orekabe           #+#    #+#             */
/*   Updated: 2022/10/01 23:45:11 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	int				token;
	char			*name;
	char			*value;
	struct s_list	*next;
}				t_list;

int		ft_strlen(char *str);
void	ft_bzero(void *s, int n);
void	*ft_calloc(int count, int size);
char	*ft_strndup(char *s, int size);
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_strcmp(char	*s1, char	*s2);
char	*ft_strncpy(char *src, char *dst, int size);
void	*ft_memcpy(void *dst, const void *src, int n);
void	*ft_memmove(void *dst, const void *src, int len);
t_list	*ft_lstnew(void *content, int token);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
int	ft_isdigit(int n);
int	ft_isalpha(int ch);
char	*ft_itoa(int n);
int	ft_atoi(char	*str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strdup(char *s);

#endif