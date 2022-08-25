/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 02:37:13 by orekabe           #+#    #+#             */
<<<<<<< HEAD:include/libft.h
/*   Updated: 2022/08/16 03:53:28 by orekabe          ###   ########.fr       */
=======
/*   Updated: 2022/08/16 03:34:23 by bmaaqoul         ###   ########.fr       */
>>>>>>> d0869b48ab9aa372797e4953fd9d89be54ab45ac:include/libft.h
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "minishell.h"

typedef struct s_list
{
	void			*content;
	int				token;
	struct s_list	*next;
}				t_list;

int		ft_strlen(char *str);
void	ft_bzero(void *s, int n);
void	*ft_calloc(int count, int size);
char	*ft_strncpy(char *src, char *dst, int size);
char	*ft_strndup(char *s, int size);
void	*ft_memcpy(void *dst, const void *src, int n);
void	*ft_memmove(void *dst, const void *src, int len);
<<<<<<< HEAD:include/libft.h
// t_list	*ft_lstnew(void *content);
// void	ft_lstadd_back(t_list **lst, t_list *new);
// void	ft_lstclear(t_list **lst, void (*del)(void *));
=======
t_list	*ft_lstnew(void *content, int token);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
int		ft_strncmp(char *s1, char *s2, int n);
>>>>>>> d0869b48ab9aa372797e4953fd9d89be54ab45ac:include/libft.h
#endif