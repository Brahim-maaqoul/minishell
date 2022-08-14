/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 00:06:20 by orekabe           #+#    #+#             */
/*   Updated: 2022/08/14 03:55:03 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print(t_tree *root)
{
	if (!root)
		return ;
	// sleep(3);
	printf("%s	%s\n", root->token, root->cmd);
	print(root->left);
	print(root->right);
}

int	main()
{
	// t_tree	*node1;
	// t_tree	*node2;
	// t_tree	*node3;
	// t_tree	*node4;
	// t_tree	*node5;
	// t_tree	*node6;

	// node1 = ft_treenew("CMD", "ls");
	// node2 = ft_treenew("OPT", "-la");
	// node3 = ft_treenew("PIPE", "|");
	// node4 = ft_treenew("CMD", "cat");
	// node5 = ft_treenew("CMD", "a.txt");
	// node6 = ft_treenew("CMD", "b.txt");

	// ft_addleaf(node1, node2);
	// ft_addleaf(node1, node4);
	// ft_addleaf(node2, node5);
	// ft_addleaf(node2, node6);
	// ft_addroot(node3, node1);
	// // ft_addroot(node3, node1);

	// print(node3);

	char *cmd = readline("minishell :");
	char *n_cmd = NULL;
	n_cmd = lexer(cmd, n_cmd);
	printf("%s\n", n_cmd);
}