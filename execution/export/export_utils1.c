/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:14:39 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/01 22:08:04 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int	update_val(t_exec *tmp, char *str, char *name, char *value)
{
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
		{
			if (value)
				tmp->value = value;
			else if (!value && !check_equal(str))
				tmp->value = ft_strndup("", 1);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

char	*get_env(t_exec *exec, char *name)
{
	while (exec)
	{
		if (!ft_strcmp(exec->name, name))
			return (exec->value);
		exec = exec->next;
	}
	return (NULL);
}

t_env	*take_splited(char *str, t_exec *tmp)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	check_env(env, tmp, str);
	return (env);
}

int	check_name(char *str)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	if (!str || !str[0] || str[0] == '=')
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (ft_isalpha(str[i]))
			a = 1;
		else
		{
			if (a && str[i] == '+' && str[i + 1] == '=')
				return (1);
			if (ft_isdigit(str[i]) && !a)
				return (0);
			else if (!ft_isdigit(str[i]) && str[i] != '_')
				return (0);
		}
		i++;
	}
	return (1);
}

int	error_name(t_env *env)
{
	if (!check_name(env->name))
	{
		put_err("minishell: export: `");
		put_err(env->name);
		put_err("': not a valid identifier\n");
		return (1);
	}
	return (0);
}
