/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 00:06:20 by orekabe           #+#    #+#             */
/*   Updated: 2022/10/01 23:45:35 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*cmd;
	char	*n_cmd;
	t_exec	*tmp;
	t_list	*lst;
	t_exec 	*exec;
	char	str[1024];
	cmd = NULL;
	av = NULL;
	exec = NULL;
	if (ac == 1)
	{
		n_cmd = NULL;
		exec = ft_env(exec, env);
		tmp = exec;
		if (!exec)
		{
			ft_execadd_back(&exec, ft_execnew(ft_strdup("PATH"), ft_strdup(_PATH_STDPATH)));
			ft_execadd_back(&exec, ft_execnew(ft_strdup("PWD"), ft_strdup(getcwd(str, sizeof(str)))));
			ft_execadd_back(&exec, ft_execnew(ft_strdup("SHLVL"), ft_itoa(1)));
		}
		while (1)
		{
			lst = NULL;
			cmd = readline("minishell :");
			if (!cmd)
				exit (1);
			lst = lexer(cmd, n_cmd, lst);
			if (lst)
				builtins(&exec, cmd);
			add_history(cmd);
			free (cmd);
		}
	}
}
