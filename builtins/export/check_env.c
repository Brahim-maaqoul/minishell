/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 03:27:49 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/03 03:47:53 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

void	check_env(t_env *env, t_built *tmp, char *str)
{
	int		len;
	char	*val;

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
		env->value = ft_substr(str, get_equal(str) + 1, len);
		if (val)
			env->value = ft_strjoin(val, env->value);
	}
	else if (get_equal(str))
	{
		env->name = ft_substr(str, 0, get_equal(str));
		env->value = ft_substr(str, get_equal(str) + 1, len);
	}
}
