/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 02:31:14 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/20 05:32:12 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	check_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	check_shlvl(char *value)
{
	if (ft_atoi(value) < 0)
	{
		free (value);
		value = ft_strdup("0");
	}
	else if (ft_atoi(value) == 1000)
	{
		free (value);
		value = ft_strdup("");
	}
	else if (ft_atoi(value) > 1000)
	{
		ft_putstr_fd("minishell: warning: shell level (", 2);
		ft_putstr_fd(value, 2);
		ft_putstr_fd(") too high, resetting to 1\n", 2);
		free (value);
		value = ft_strdup("1");
	}
}

void	add_shlvl(char *env, char *name, char *value)
{
	char	*str;

	if (!ft_strcmp(name, "SHLVL"))
	{
		str = ft_substr(env, 0, get_equal(env) + 1);
		if (check_alpha(value))
		{
			free (str);
			free (value);
			value = ft_strdup("1");
			return ;
		}
		free (value);
		value = ft_itoa(ft_atoi(value) + 1);
		check_shlvl(value);
		free (str);
	}
}

t_built	*ft_env(t_built *built, char **env)
{
	int		i;
	char	*name;
	char	*value;
	int		len;

	i = 0;
	if (!env || !*env)
		return (NULL);
	while (env[i])
	{
		len = ft_strlen(env[i]) - get_equal(env[i]);
		if (get_equal(env[i]))
		{
			value = ft_substr(env[i], get_equal(env[i]) + 1, len);
			name = ft_substr(env[i], 0, get_equal(env[i]));
			add_shlvl(env[i], name, value);
			ft_builtadd_back(&built, ft_builtnew(name, value));
		}
		i++;
	}
	return (built);
}
