/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 22:22:16 by orekabe           #+#    #+#             */
/*   Updated: 2022/10/20 01:16:53 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	check_sq(char *arg)
{
	int		i;
	char	c;

	i = 1;
	c = arg[0];
	while (arg[i] && arg[i] != c)
		i++;
	return (i);
}

char	*flag_sp(char *exp)
{
	int	i;

	i = 0;
	if (!exp)
		return (NULL);
	while (exp[i])
	{
		if (exp[i] == '$' && (exp[i + 1] == -2 || exp[i + 1] == -1))
			exp[i] = -4;
		if (exp[i] == -2 || exp[i] == -1)
			i += check_sq(exp + i);
		if (exp[i] == ' ')
			exp[i] = -3;
		i++;
	}
	return (exp);
}

void	rm_q(char *n_cmd)
{
	int		i;

	i = 0;
	while (n_cmd[i])
	{
		if (n_cmd[i] == -1 || n_cmd[i] == -2 || n_cmd[i] == -4)
			ft_memmove(n_cmd + i, n_cmd + i + 1, ft_strlen(n_cmd) - i);
		else
			i++;
	}
}

int	ft_tabsize(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

char	**ft_tabjoin(char **tab1, char **tab2)
{
	int		size;
	int		i;
	int		j;
	char	**tab;

	size = ft_tabsize(tab1) + ft_tabsize(tab2);
	tab = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (tab1 && tab1[i])
	{
		tab[i] = tab1[i];
		i++;
	}
	j = 0;
	while (tab2 && tab2[j])
	{
		tab[i] = tab2[j];
		i++;
		j++;
	}
	tab[i] = NULL;
	free(tab1);
	free(tab2);
	return (tab);
}
