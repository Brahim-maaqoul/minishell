/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 00:06:20 by orekabe           #+#    #+#             */
/*   Updated: 2022/10/03 03:52:17 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*cmd;
	char	*n_cmd;
	t_built	*tmp;
	t_list	*lst;
	t_built 	*built;
	char	str[1024];
	cmd = NULL;
	av = NULL;
	built = NULL;
	if (ac == 1)
	{
		rl_catch_signals = 0;
		n_cmd = NULL;
		built = ft_env(built, env);
		tmp = built;
		if (!built)
		{
			ft_builtadd_back(&built, ft_builtnew(ft_strdup("PATH"), ft_strdup(_PATH_STDPATH)));
			ft_builtadd_back(&built, ft_builtnew(ft_strdup("PWD"), ft_strdup(getcwd(str, sizeof(str)))));
			ft_builtadd_back(&built, ft_builtnew(ft_strdup("SHLVL"), ft_itoa(1)));
		}
		while (1)
		{
			signal(SIGINT, handler);
			signal(SIGQUIT, SIG_IGN);
			lst = NULL;
			cmd = readline("minishell :");
			if (!cmd)
				exit (1);
			lst = lexer(cmd, n_cmd, lst);
			if (lst)
				builtins(&built, cmd);
			add_history(cmd);
			free (cmd);
		}
	}
}
