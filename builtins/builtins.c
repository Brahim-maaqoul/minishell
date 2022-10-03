/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:07:38 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/03 03:52:17 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	builtins(t_built **built, char *cmd)
{
	if (!ft_strncmp(cmd, "env", 3))
		print_env(*built);
	else if (!ft_strncmp(cmd, "export", 6))
		ft_export(built, cmd);
	else if (!ft_strncmp(cmd, "unset", 5))
		ft_unset(built, cmd);
	else if (!ft_strncmp(cmd, "pwd", 3))
		ft_pwd();
	else if (!ft_strncmp(cmd, "cd", 2))
		ft_cd(*built, cmd);
	else if (!ft_strncmp(cmd, "echo", 4))
		ft_echo(cmd);
	else if (!ft_strncmp(cmd, "exit", 4))
		ft_exit(cmd);
}
