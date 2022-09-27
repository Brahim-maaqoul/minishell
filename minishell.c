/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 00:06:20 by orekabe           #+#    #+#             */
/*   Updated: 2022/09/26 20:23:26 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tree(t_tree *tree, int lvl)
{
	int	i;

	i = 0;
	if (!tree)
		return ;
	while (i++ < lvl)
		printf("\t");
	printf("%d\n", tree->list->token);
	print_tree(tree->left, lvl - 1);
	print_tree(tree->right, lvl + 1);
}

void	free_tree(t_tree *root)
{
	if (root)
	{
		if (root->left)
		{
			free_tree(root->left);
			root->left = NULL;
		}
		if (root->right)
		{
			free_tree(root->right);
			root->right = NULL;
		}
		if (root->list)
		{
			ft_lstclear(root->list);
			root->list = NULL;
		}
		free(root);
	}
}

int	main(void)
{
	char	*cmd;
	char	*n_cmd;
	t_list	*list;
	t_tree	*tree;

	while (1)
	{
		list = NULL;
		tree = NULL;
		n_cmd = NULL;
		cmd = readline("minishell :");
		if (cmd[0])
		{
			add_history(cmd);
			list = lexer(cmd, n_cmd, list);
		}
		if (list)
		{
			tree = parser(list);
			print_tree(tree, 3);
			free_tree(tree);
		}
		free(cmd);
	}
}
