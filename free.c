/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:51:28 by orekabe           #+#    #+#             */
/*   Updated: 2022/10/14 04:43:16 by orekabe          ###   ########.fr       */
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

void	free_table(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
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
		if (root->args)
			free_table(root->args);
		free(root);
	}
}
