/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 03:40:52 by orekabe           #+#    #+#             */
/*   Updated: 2022/10/18 23:06:52 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	fork_child(int fd1, int fd2, int d)
{
	dup2(fd1, d);
	close(fd1);
	close(fd2);
}

void	pippe(t_tree *node, t_built **builts)
{
	int	fds[2];
	int	pid;

	if (pipe(fds) < 0)
		return ;
	pid = fork();
	if (pid == 0)
	{
		fork_child(fds[1], fds[0], 1);
		exec_tree(node->left, builts);
		exit (g_glob.ex_st);
	}
	pid = fork();
	if (pid == 0)
	{
		fork_child(fds[0], fds[1], 0);
		exec_tree(node->right, builts);
		exit (g_glob.ex_st);
	}
	close(fds[0]);
	close(fds[1]);
	waitpid(pid, (int *)&g_glob.ex_st, 0);
	wait(0);
	g_glob.ex_st = WEXITSTATUS(g_glob.ex_st);
	return ;
}
