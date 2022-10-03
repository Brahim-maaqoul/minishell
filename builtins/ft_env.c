/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 02:31:14 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/03 03:52:17 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	add_shlvl(t_built *built)
{
	t_built	*tmp;
	char	*s;

	tmp = built;
	while (tmp)
	{
		if (!ft_strncmp(tmp->name, "SHLVL", 5))
		{
			s = tmp->value;
			free(s);
			tmp->value = ft_itoa(ft_atoi(tmp->value) + 1);
			break ;
		}
		tmp = tmp->next;
	}
}

t_built	*ft_env(t_built *built, char **env)
{
	int		i;
	char	*name;
	char	*value;
	int		len;

	i = 0;
	if (!env && !*env)
		return (NULL);
	while (env[i])
	{
		len = ft_strlen(env[i]) - get_equal(env[i]);
		if (get_equal(env[i]))
		{
			name = ft_substr(env[i], 0, get_equal(env[i]));
			value = ft_substr(env[i], get_equal(env[i]) + 1, len);
			ft_builtadd_back(&built, ft_builtnew(name, value));
		}
		i++;
	}
	add_shlvl(built);
	return (built);
}
