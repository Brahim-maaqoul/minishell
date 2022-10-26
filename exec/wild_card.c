/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wild_card.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 05:22:49 by orekabe           #+#    #+#             */
/*   Updated: 2022/10/20 04:32:19 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	get_curr_size(void)
{
	DIR				*dir;
	struct dirent	*dp;
	int				i;

	i = 0;
	dir = opendir(".");
	if (dir == NULL)
	{
		perror("Cannot open .");
		return (0);
	}
	dp = readdir(dir);
	while (dp != NULL)
	{
		i++;
		dp = readdir(dir);
	}
	closedir(dir);
	return (i);
}

char	**get_curr(void)
{
	DIR				*dir;
	struct dirent	*dp;
	char			**ret;
	int				i;

	ret = (char **)malloc(sizeof(char *) * (get_curr_size() + 1));
	if (!ret)
		return (NULL);
	dir = opendir(".");
	if (dir == NULL)
	{
		perror("Cannot open .");
		return (0);
	}
	i = 0;
	dp = readdir(dir);
	while (dp != NULL)
	{
		ret[i] = ft_strdup(dp->d_name);
		i++;
		dp = readdir(dir);
	}
	ret[i] = NULL;
	closedir(dir);
	return (ret);
}

char	*joinchr(char *str)
{
	char	c[2];

	c[0] = -3;
	c[1] = '\0';
	return (ft_strjoin(str, c));
}

char	*exp_star(char *str, char **curr)
{
	char	*ret;
	char	*tmp;
	int		i;
	int		b;

	i = 0;
	b = 0;
	ret = ft_calloc(1, sizeof(char));
	while (curr[i])
	{
		if (check_valid(str, curr[i]) && cmp_last(str, curr[i])
			&& cmp_first(str, curr[i]))
		{
			b = 1;
			tmp = joinchr(ret);
			free(ret);
			ret = ft_strjoin(tmp, curr[i]);
			free(tmp);
		}
		i++;
	}
	if (!b)
		return (free(ret), ft_strdup(str));
	return (ret);
}

char	**wild_card(char **args)
{
	int		i;
	char	**curr;
	char	*ret;
	char	*exp;
	char	*tmp;

	curr = get_curr();
	i = -1;
	ret = ft_calloc(1, sizeof(char));
	while (args[++i])
	{
		if (check_star(args[i]))
			exp = exp_star(args[i], curr);
		else
			exp = ft_strdup(args[i]);
		tmp = joinchr(exp);
		free(exp);
		exp = ret;
		ret = ft_strjoin(ret, tmp);
		free(tmp);
		free(exp);
	}
	free_tab(curr);
	curr = ft_split(ret, -3);
	return (free_tab(args), free(ret), curr);
}
