/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 02:54:37 by orekabe           #+#    #+#             */
/*   Updated: 2022/08/14 02:54:52 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	int		i;
	char	*ptr;

	i = ft_strlen(s) + 1;
	ptr = (char *)malloc(i * sizeof(char));
	if (!(ptr))
		return (NULL);
	ptr[i] = '\0';
	while (--i >= 0)
		ptr[i] = s[i];
	return (ptr);
}
