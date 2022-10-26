/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 00:06:20 by orekabe           #+#    #+#             */
/*   Updated: 2022/10/20 20:00:02 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_built(t_var *var)
{
	char	str[1024];

	if (!var->built)
	{
		ft_builtadd_back(&var->built, ft_builtnew(ft_strdup("PATH"),
				ft_strdup(_PATH_STDPATH)));
		ft_builtadd_back(&var->built, ft_builtnew(ft_strdup("PWD"),
				ft_strdup(getcwd(str, sizeof(str)))));
		ft_builtadd_back(&var->built, ft_builtnew(ft_strdup("SHLVL"),
				ft_itoa(1)));
	}
}

void	init_vars(t_var *var, int ac, char **av)
{
	char	*first;
	char	*second;
	char	*mid;

	(void)ac;
	(void)av;
	var->cmd = NULL;
	var->n_cmd = NULL;
	var->list = NULL;
	var->tree = NULL;
	first = "mini'";
	second = "'hill: ";
	mid = NULL;
	if (!g_glob.ex_st)
		mid = "\001\e\033[0;32m\002c\001\e\033[0m\002";
	else
		mid = "\001\e\033[0;31m\002c\001\e\033[0m\002";
	g_glob.name = ft_strjoin(first, mid);
	first = g_glob.name;
	g_glob.name = ft_strjoin(first, second);
	free(first);
	get_built(var);
}

void	init_rl_vars(void)
{
	rl_catch_signals = 0;
	g_glob.ex_st = 0;
	g_glob.cp = 0;
}

void	minishell(t_var	*var)
{
	if (var->cmd[0] && g_glob.gl)
	{
		add_history(var->cmd);
		signal(SIGINT, handler_pars);
		rl_event_hook = event;
		var->list = lexer(var->cmd, var->n_cmd, var->list);
	}
	if (g_glob.gl && var->list)
	{
		var->tree = parser(var->list);
		signal(SIGINT, SIG_IGN);
		if (g_glob.gl)
			exec_tree(var->tree, &var->built);
		free_tree(var->tree);
	}
}

int	main(int ac, char **av, char **env)
{
	t_var	var;

	init_rl_vars();
	var.built = ft_env(var.built, env);
	while (1)
	{
		g_glob.gl = 1;
		signal(SIGINT, handler_pars);
		rl_event_hook = event;
		signal(SIGQUIT, SIG_IGN);
		init_vars(&var, ac, av);
		var.cmd = readline(g_glob.name);
		ctrl_d(var.cmd);
		minishell(&var);
		free(var.cmd);
		free(g_glob.name);
	}
}
