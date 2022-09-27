/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 02:37:13 by orekabe           #+#    #+#             */
/*   Updated: 2022/09/24 01:16:48 by orekabe          ###   ########.fr       */
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
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

int		ft_strlen(char *str);
void	ft_bzero(void *s, int n);
void	*ft_calloc(int count, int size);
char	*ft_strndup(char *s, int size);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strncpy(char *src, char *dst, int size);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memcpy(void *dst, const void *src, int n);
void	*ft_memmove(void *dst, const void *src, int len);
t_list	*ft_lstnew(void *content, int token);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list *lst);

#endif