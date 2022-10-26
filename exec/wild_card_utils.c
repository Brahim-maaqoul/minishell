/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wild_card_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 00:17:43 by orekabe           #+#    #+#             */
/*   Updated: 2022/10/20 03:05:44 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	check_star(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '*')
			return (1);
		i++;
	}
	return (0);
}

int	star_chr(char *s)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while (s[i] && (s[i] != '*' || c))
	{
		if (c == s[i])
			c = 0;
		else if (s[i] == -2 || s[i] == -1)
			c = s[i];
		i++;
	}
	return (i);
}

int	check_valid(char *str, char *cmp)
{
	int		len;
	char	*tmp;

	while (*str)
	{
		if (*str != '*')
		{
			len = star_chr(str);
			tmp = wc_substr(str, len);
			cmp = ft_strstr(cmp, tmp);
			free(tmp);
			if (!cmp)
				return (0);
			str += len - 1;
		}
		str++;
	}
	return (1);
}

int	cmp_last(char *str, char *cmp)
{
	int		i;
	int		j;
	char	c;

	c = 0;
	i = ft_strlen(str) - 1;
	j = ft_strlen(cmp) - 1;
	while (i >= 0 && (str[i] != '*' || c))
	{
		if (c == str[i])
			c = 0;
		else if (str[i] == -2 || str[i] == -1)
			c = str[i];
		else
		{
			if (j < 0 || str[i] != cmp[j])
				return (0);
			j--;
		}
		i--;
	}
	return (1);
}

int	cmp_first(char *str, char *cmp)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	c = 0;
	while (str[i] && (str[i] != '*' || c))
	{
		if (c == str[i])
			c = 0;
		else if (str[i] == -2 || str[i] == -1)
			c = str[i];
		else
		{
			if (!cmp[j] || str[i] != cmp[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
