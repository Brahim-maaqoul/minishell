/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 04:52:01 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/01 22:16:20 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

t_exec	*fill_env(t_exec **exec, t_env *env, char *str)
{
	int		b;
	t_exec	*tmp;

	b = 0;
	tmp = *exec;
	env = take_splited(str, tmp);
	if (error_name(env))
		b = 1;
	if (!update_val(tmp, str, env->name, env->value) && !b)
	{
		if (!env->value && !check_equal(str))
			env->value = ft_strndup("", 1);
		ft_execadd_back(exec, ft_execnew(env->name, env->value));
	}
	return (*exec);
}

void	ft_export(t_exec **exec, char *cmd)
{
	t_exec	*tmp1;
	t_env	*env;
	char	**splited;
	int		j;

	j = 1;
	env = NULL;
	tmp1 = NULL;
	splited = ft_split(cmd, ' ');
	while (splited[j])
	{
		tmp1 = fill_env(exec, env, splited[j]);
		if (!splited[j + 1])
			return ;
		j++;
	}
	if (!fork())
	{
		tmp1 = *exec;
		sort_name(tmp1, *exec);
		print_export(*exec);
		exit(0);
	}
	waitpid(-1, 0, 0);
}
