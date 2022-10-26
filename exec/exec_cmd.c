/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:26:03 by orekabe           #+#    #+#             */
/*   Updated: 2022/10/20 16:36:47 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	chech_path(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

void	run_cmd(t_tree *node, char *cmd, t_built *built)
{
	if (fork() == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execve(cmd, node->args, convert_toarr(built));
	}
	else
	{
		waitpid(-1, &g_glob.ex_st, 0);
		g_glob.ex_st = exit_status(g_glob.ex_st);
	}
}

int	get_path(t_tree *node, char **s_path, char *path, t_built *built)
{
	char	*cmd;
	int		i;

	i = -1;
	while (s_path[++i])
	{
		path = ft_strjoin(s_path[i], "/");
		cmd = ft_strjoin(path, node->args[0]);
		free(path);
		if (access(cmd, X_OK) == 0)
		{
			run_cmd(node, cmd, built);
			free(cmd);
			free_tab(s_path);
			return (1);
		}
		free(cmd);
	}
	free_tab(s_path);
	return (0);
}

int	execcc(t_tree *node, char **s_path, char *path, t_built *built)
{
	int		i;

	i = 0;
	(void)built;
	if (chech_path(node->args[0]))
	{
		if (fork() == 0)
		{
			signal(SIGINT, SIG_DFL);
			signal(SIGQUIT, SIG_DFL);
			execve(node->args[0], node->args, convert_toarr(built));
			put_err("mini'c'hill: ");
			put_err(node->args[0]);
			perror(" ");
			exit(1);
		}
		else
		{
			waitpid(-1, &g_glob.ex_st, 0);
			g_glob.ex_st = exit_status(g_glob.ex_st);
		}
		free_tab(s_path);
		return (1);
	}
	return (get_path(node, s_path, path, built));
}

void	exec_cmd(t_tree *node, t_built **built)
{
	char	*path;
	char	**s_path;
	int		i;

	i = 0;
	if (!node->args[0] || !node->args[0][0])
		return ;
	path = get_env(*built, "PATH");
	if (!path)
	{
		cmd_nf(node->args[0]);
		return ;
	}
	s_path = ft_split(path, ':');
	free(path);
	if (execcc(node, s_path, path, *built))
		return ;
	else
		cmd_nf(node->args[0]);
	return ;
}
