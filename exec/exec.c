/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 02:15:54 by orekabe           #+#    #+#             */
/*   Updated: 2022/10/19 04:13:27 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	subshell(t_tree *node, t_built **built)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		exec_tree(node->left, built);
		exit(g_glob.ex_st);
	}
	waitpid(pid, (int *)&g_glob.ex_st, 0);
	g_glob.ex_st = WEXITSTATUS(g_glob.ex_st);
}

void	check_exec(t_tree *node, t_built **built)
{
	if (!node)
	{
		g_glob.ex_st = 0;
		return ;
	}
	if (node->list->token == 1 || node->list->token == 2)
		and_or(node, built);
	if (node->list->token == 3)
		pippe(node, built);
	if (node->list->token >= 4 && node->list->token <= 7)
		redirec(node, built);
	if (node->list->token == 11)
		subshell(node, built);
	if (node->list->token == 10)
		builtins(built, node);
}

void	exec_tree(t_tree *root, t_built **built)
{
	check_exec(root, built);
}
