/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:07:38 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/14 11:49:19 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../exec/exec.h"

void	builtins(t_built **built, t_tree *node)
{
	get_args(node, built);
	if (!ft_strcmp(node->args[0], "env"))
		print_env(*built);
	else if (!ft_strcmp(node->args[0], "export"))
		ft_export(built, node->args);
	else if (!ft_strcmp(node->args[0], "unset"))
		ft_unset(built, node->args);
	else if (!ft_strcmp(node->args[0], "pwd"))
		ft_pwd();
	else if (!ft_strcmp(node->args[0], "cd"))
		ft_cd(*built, node->args);
	else if (!ft_strcmp(node->args[0], "echo"))
		ft_echo(node->args);
	else if (!ft_strcmp(node->args[0], "exit"))
		ft_exit(node->args);
	else
		exec_cmd(node, built);
}
