/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 03:27:49 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/18 03:08:50 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

void	update_equal(t_env *env, char *str, int len)
{
	env->name = ft_substr(str, 0, get_equal(str));
	env->value = ft_substr(str, get_equal(str) + 1, len);
}

void	check_env(t_env *env, t_built *tmp, char *str)
{
	int		len;
	char	*val;
	char	*plusval;

	len = ft_strlen(str) - get_equal(str);
	if (!get_equal(str))
	{
		env->name = ft_substr(str, 0, len);
		env->value = NULL;
	}
	if (get_plus(str))
	{
		env->name = ft_substr(str, 0, get_equal(str) - 1);
		val = get_env(tmp, env->name);
		plusval = ft_substr(str, get_equal(str) + 1, len);
		if (val)
		{
			env->value = ft_strjoin(val, plusval);
			free(plusval);
			free (val);
		}
	}
	else if (get_equal(str))
		update_equal(env, str, len);
}
