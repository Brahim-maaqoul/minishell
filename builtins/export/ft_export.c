/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 04:52:01 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/18 03:08:19 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

t_built	*fill_env(t_built **built, t_env *env, char *str)
{
	int		b;
	int		i;
	t_built	*tmp;

	b = 0;
	i = 1;
	tmp = *built;
	env = take_splited(str, tmp);
	if (error_name(env))
	{
		b = 1;
		g_glob.cp = 1;
	}
	if (!update_val(tmp, str, env->name, env->value) && !b)
	{
		if (!env->value && !check_equal(str))
			env->value = ft_strndup("", 1);
		ft_builtadd_back(built, ft_builtnew(env->name, env->value));
	}
	if (!g_glob.cp)
		g_glob.ex_st = 0;
	free (env);
	return (*built);
}

void	ft_export(t_built **built, char **cmd)
{
	t_built	*tmp1;
	t_env	*env;
	int		j;

	j = 1;
	env = NULL;
	tmp1 = NULL;
	g_glob.cp = 0;
	while (cmd[j])
	{
		tmp1 = fill_env(built, env, cmd[j]);
		if (!cmd[j + 1])
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
	g_glob.ex_st = 0;
}
