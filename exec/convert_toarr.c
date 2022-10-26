/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_toarr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:34:04 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/18 22:59:38 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	**convert_toarr_util(t_built *built, char **env)
{
	char	*name;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (built)
	{
		if (!ft_strcmp(built->name, "SHLVL"))
			j = 1;
		name = ft_strjoin(built->name, "=");
		env[i++] = ft_strjoin(name, built->value);
		free (name);
		if (!built->next && j == 0)
		{
			ft_builtadd_back(&built, ft_builtnew(ft_strdup("SHLVL"),
					ft_strdup("0")));
			name = ft_strjoin(built->name, "=");
			env[i++] = ft_strjoin(name, built->value);
			free (name);
		}
		built = built->next;
	}
	env[i] = NULL;
	return (env);
}

char	**convert_toarr(t_built *built)
{
	int		len;
	char	**env;

	len = ft_builtsize(built);
	env = malloc(sizeof(char **) * len + 1);
	if (!env)
		return (NULL);
	env = convert_toarr_util(built, env);
	return (env);
}
