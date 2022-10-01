/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 02:33:24 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/01 22:21:17 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	update_pwd(t_exec *exec, char *name, char *value)
{
	if (!name || !value)
		return ;
	while (exec)
	{
		if (!ft_strcmp(exec->name, name))
		{
			exec->value = ft_strndup(value, ft_strlen(value));
			return ;
		}
		exec = exec->next;
	}
}

void	cd_util1(t_exec *exec)
{
	char	*path;
	char	str[1024];

	path = get_env(exec, "HOME");
	if (!path)
	{
		put_err("cd: HOME not set\n");
		return ;
	}
	if (chdir(path) == -1)
	{
		put_err("cd: ");
		put_err(path);
		put_err(": No such file or directory\n");
		return ;
	}
	update_pwd(exec, "OLDPWD", get_env(exec, "PWD"));
	update_pwd(exec, "PWD", getcwd(str, sizeof(str)));
}

void	cd_util2(t_exec *exec)
{
	char	*path;
	char	str[1024];

	path = getcwd(str, sizeof(str));
	if (!path)
	{
		put_err("cd: error retrieving current directory: getcwd: ");
		put_err("cannot access parent directories: No such file or directory\n");
		update_pwd(exec, "PWD", path);
		return ;
	}
	chdir(path);
	update_pwd(exec, "OLDPWD", get_env(exec, "PWD"));
	update_pwd(exec, "PWD", getcwd(str, sizeof(str)));
}

void	cd_util3(t_exec *exec)
{
	char	*old;
	char	str[1024];

	old = get_env(exec, "OLDPWD");
	if (!old)
	{
		put_err("cd: OLDPWD not set\n");
		return ;
	}
	if (chdir(old) == -1)
	{
		put_err("cd: ");
		put_err(old);
		put_err(": No such file or directory\n");
		return ;
	}
	else
		printf("%s\n", old);
	update_pwd(exec, "OLDPWD", get_env(exec, "PWD"));
	update_pwd(exec, "PWD", getcwd(str, sizeof(str)));
}

void	ft_cd(t_exec *exec, char *cmd)
{
	char	**splited;
	char	str[1024];

	splited = ft_split(cmd, ' ');
	if (!splited[1] || !ft_strcmp(splited[1], "~"))
		cd_util1(exec);
	else if (!ft_strcmp(splited[1], "."))
		cd_util2(exec);
	else if (!ft_strcmp(splited[1], "-"))
		cd_util3(exec);
	else
	{
		if (chdir(splited[1]) == -1)
		{
			put_err("cd: ");
			put_err(splited[1]);
			put_err(": No such file or directory\n");
		}
		update_pwd(exec, "OLDPWD", get_env(exec, "PWD"));
		update_pwd(exec, "PWD", getcwd(str, sizeof(str)));
	}
}
