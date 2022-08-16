/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 02:29:56 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/08/16 02:31:42 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int 			i;
	unsigned char	*pt1;
	unsigned char	*pt2;

	if (n == 0)
		return (0);
	pt1 = (unsigned char *) s1;
	pt2 = (unsigned char *) s2;
	i = 0;
	while (pt1[i] && pt2[i] && pt1[i] == pt2[i] && i < n - 1)
		i++;
	return (pt1[i] - pt2[i]);
}