/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 02:37:13 by orekabe           #+#    #+#             */
/*   Updated: 2022/08/14 02:39:53 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include "../minishell.h"

int		ft_strlen(char *str);
void	ft_bzero(void *s, int n);
void	*ft_calloc(int count, int size);
char	*ft_strncpy(char *src, char *dst, int size);
char	*ft_strdup(char *s);
void	*ft_memcpy(void *dst, const void *src, int n);
void	*ft_memmove(void *dst, const void *src, int len);

#endif