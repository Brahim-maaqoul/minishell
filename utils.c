/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 01:10:19 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/07/18 15:13:40 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*t;
	int		k;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	k = ft_strlen(s1) + ft_strlen(s2);
	t = (char *) malloc(sizeof(char) * (k + 1));
	if (!t)
		return (NULL);
	while (s1[i])
	{
		t[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		t[i++] = s2[j];
		j++;
	}
	t[i] = '\0';
	return (t);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pt;
	size_t	j;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
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

char	*ft_strdup(const char *src)
{
	char	*str;
	int		i;

	i = 0;
	while (src[i])
		i++;
	str = (char *) malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
