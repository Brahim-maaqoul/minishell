/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:07:38 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/01 22:18:50 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	builtins(t_exec **exec, char *cmd)
{
	if (!ft_strncmp(cmd, "env", 3))
		print_env(*exec);
	else if (!ft_strncmp(cmd, "export", 6))
		ft_export(exec, cmd);
	else if (!ft_strncmp(cmd, "unset", 5))
		ft_unset(exec, cmd);
	else if (!ft_strncmp(cmd, "pwd", 3))
		ft_pwd();
	else if (!ft_strncmp(cmd, "cd", 2))
		ft_cd(*exec, cmd);
	else if (!ft_strncmp(cmd, "echo", 4))
		ft_echo(cmd);
	else if (!ft_strncmp(cmd, "exit", 4))
		ft_exit(cmd);
}
