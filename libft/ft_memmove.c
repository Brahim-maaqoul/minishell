/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 02:56:00 by orekabe           #+#    #+#             */
/*   Updated: 2022/08/14 02:56:15 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, int len)
{
	char	*ptr1;
	char	*ptr2;

	if (!dst && !src)
		return (0);
	ptr1 = (char *)dst;
	ptr2 = (char *)src;
	if (src > dst)
		ft_memcpy(dst, src, len);
	else
		while (len--)
			ptr1[len] = ptr2[len];
	return (ptr1);
}
