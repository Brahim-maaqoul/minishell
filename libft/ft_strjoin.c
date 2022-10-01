/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 02:44:33 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/09/16 03:50:50 by bmaaqoul         ###   ########.fr       */
=======
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:31:35 by orekabe           #+#    #+#             */
/*   Updated: 2022/09/09 16:28:26 by orekabe          ###   ########.fr       */
>>>>>>> 2469868c048956f9f6f18e66937d07df6ba93cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
<<<<<<< HEAD
	char	*t;
	int		k;
=======
	char	*ptr;
>>>>>>> 2469868c048956f9f6f18e66937d07df6ba93cf2
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
<<<<<<< HEAD
	k = ft_strlen(s1) + ft_strlen(s2);
	t = (char *) malloc(sizeof(char) * (k + 1));
	if (!t)
		return (NULL);
	while (s1[i])
	{
		t[i] = s1[i];
=======
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!(ptr))
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
>>>>>>> 2469868c048956f9f6f18e66937d07df6ba93cf2
		i++;
	}
	while (s2[j])
	{
<<<<<<< HEAD
		t[i++] = s2[j];
		j++;
	}
	t[i] = '\0';
	return (t);
=======
		ptr[i] = s2[j];
		j++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
>>>>>>> 2469868c048956f9f6f18e66937d07df6ba93cf2
}
