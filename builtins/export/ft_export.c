/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 04:52:01 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/03 03:52:17 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

t_built	*fill_env(t_built **built, t_env *env, char *str)
{
	int		b;
	t_built	*tmp;

	b = 0;
	tmp = *built;
	env = take_splited(str, tmp);
	if (error_name(env))
		b = 1;
	if (!update_val(tmp, str, env->name, env->value) && !b)
	{
		if (!env->value && !check_equal(str))
			env->value = ft_strndup("", 1);
		ft_builtadd_back(built, ft_builtnew(env->name, env->value));
	}
	return (*built);
}

void	ft_export(t_built **built, char *cmd)
{
	t_built	*tmp1;
	t_env	*env;
	char	**splited;
	int		j;

	j = 1;
	env = NULL;
	tmp1 = NULL;
	splited = ft_split(cmd, ' ');
	while (splited[j])
	{
		tmp1 = fill_env(built, env, splited[j]);
		if (!splited[j + 1])
			return ;
		j++;
	}
	if (!fork())
	{
		tmp1 = *built;
		sort_name(tmp1, *built);
		print_export(*built);
		exit(0);
	}
	waitpid(-1, 0, 0);
}
