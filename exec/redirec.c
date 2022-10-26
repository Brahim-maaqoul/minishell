/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:59:08 by orekabe           #+#    #+#             */
/*   Updated: 2022/10/20 18:36:44 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	dright_red(t_tree *node, t_built **built)
{
	int	fd;
	int	fb;

	get_args(node->right, built);
	fd = open(node->right->args[0], O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (fd < 0)
	{
		put_err("mini'c'hill: ");
		perror(node->right->args[0]);
		g_glob.ex_st = 1;
		return ;
	}
	fb = dup(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	exec_tree(node->left, built);
	dup2(fb, STDOUT_FILENO);
	close(fb);
}

void	heredoc(t_tree *node, t_built **built)
{
	int		fds[2];
	int		fb;
	char	*exp;

	if (node->exp_h)
		exp = expander(node->right->list->content, built);
	else
		exp = ft_strdup(node->right->list->content);
	if (pipe(fds) < 0)
		return ;
	if (!fork())
	{
		ft_putstr_fd(exp, fds[1]);
		exit (0);
	}
	wait(0);
	free(exp);
	fb = dup(STDIN_FILENO);
	dup2(fds[0], STDIN_FILENO);
	close(fds[0]);
	close(fds[1]);
	exec_tree(node->left, built);
	dup2(fb, STDIN_FILENO);
	close(fb);
}

void	right_red(t_tree *node, t_built **built)
{
	int	fd;
	int	fb;

	get_args(node->right, built);
	fd = open(node->right->args[0], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd < 0)
	{
		put_err("mini'c'hill: ");
		perror(node->right->args[0]);
		g_glob.ex_st = 1;
		return ;
	}
	fb = dup(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	exec_tree(node->left, built);
	dup2(fb, STDOUT_FILENO);
	close(fb);
}

int	left_red(t_tree *node, t_built **built)
{
	int	fd;
	int	fb;

	get_args(node->right, built);
	if (node->right->args[1])
	{
		put_err("mini'c'hill: ");
		put_err(node->right->list->content);
		put_err(": ambiguous redirect\n");
		g_glob.ex_st = 1;
		return (0);
	}
	fd = open(node->right->args[0], O_RDONLY);
	if (fd < 0)
	{
		put_err("mini'c'hill: ");
		perror(node->right->args[0]);
		g_glob.ex_st = 1;
		return (0);
	}
	fb = dup(STDIN_FILENO);
	dup2(fd, STDIN_FILENO);
	exec_tree(node->left, built);
	dup2(fb, STDIN_FILENO);
	return (close(fd), close(fb));
}

void	redirec(t_tree *node, t_built **built)
{
	if (node->list->token == 4)
		left_red(node, built);
	if (node->list->token == 5)
		right_red(node, built);
	if (node->list->token == 6)
		heredoc(node, built);
	if (node->list->token == 7)
		dright_red(node, built);
}
