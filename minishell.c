/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 00:06:20 by orekabe           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/10/01 23:45:35 by bmaaqoul         ###   ########.fr       */
=======
/*   Updated: 2022/09/26 20:23:26 by orekabe          ###   ########.fr       */
>>>>>>> 2469868c048956f9f6f18e66937d07df6ba93cf2
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< HEAD
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
=======
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
>>>>>>> 2469868c048956f9f6f18e66937d07df6ba93cf2
	}
}
