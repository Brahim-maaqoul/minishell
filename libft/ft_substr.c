/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 02:44:49 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/09/11 18:32:46 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*pt;
	int     j;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strndup("", 1));
	pt = (char *) malloc(sizeof(char) * (len + 1));
	if (!pt)
		return (NULL);
	j = 0;
	while (s[start] && j < len)
	{
		pt[j] = s[start];
		j++;
		start++;
	}
	pt[j] = 0;
	return (pt);
}
