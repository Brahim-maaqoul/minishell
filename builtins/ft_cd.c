/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 02:33:24 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/18 03:07:36 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	update_pwd(t_built *built, char *name, char *value)
{
	if (!name || !value)
		return ;
	while (built)
	{
		if (!ft_strcmp(built->name, name))
		{
			free (built->value);
			built->value = ft_strdup(value);
			return ;
		}
		built = built->next;
	}
}

void	cd_util1(t_built *built)
{
	char	*path;
	char	str[1024];

	path = get_env(built, "HOME");
	if (!path)
	{
		put_err("cd: HOME not set\n");
		free(path);
		g_glob.ex_st = 1;
		return ;
	}
	if (chdir(path) == -1)
	{
		check_dir(path);
		free (path);
		return ;
	}
	free (path);
	path = get_env(built, "PWD");
	update_pwd(built, "OLDPWD", path);
	update_pwd(built, "PWD", getcwd(str, sizeof(str)));
	free (path);
	g_glob.ex_st = 0;
}

void	cd_util2(t_built *built)
{
	char	*path;
	char	str[1024];

	path = getcwd(str, sizeof(str));
	if (!path)
	{
		put_err("cd: error retrieving current directory: getcwd: ");
		put_err("cannot access parent directories: No such file or directory\n");
		update_pwd(built, "PWD", path);
		g_glob.ex_st = 1;
		free (path);
		return ;
	}
	chdir(path);
	path = get_env(built, "PWD");
	update_pwd(built, "OLDPWD", path);
	update_pwd(built, "PWD", getcwd(str, sizeof(str)));
	free (path);
	g_glob.ex_st = 0;
}

void	cd_util3(t_built *built)
{
	char	*old;
	char	str[1024];

	old = get_env(built, "OLDPWD");
	if (!old)
	{
		put_err("cd: OLDPWD not set\n");
		free (old);
		g_glob.ex_st = 1;
		return ;
	}
	if (chdir(old) == -1)
	{
		check_dir(old);
		free (old);
		return ;
	}
	else
		printf("%s\n", old);
	free (old);
	old = get_env(built, "PWD");
	update_pwd(built, "OLDPWD", old);
	update_pwd(built, "PWD", getcwd(str, sizeof(str)));
	free (old);
	g_glob.ex_st = 0;
}

void	ft_cd(t_built *built, char **cmd)
{
	char	str[1024];
	char	*old;

	if (!cmd[1] || !ft_strcmp(cmd[1], "~"))
		cd_util1(built);
	else if (!ft_strcmp(cmd[1], "."))
		cd_util2(built);
	else if (!ft_strcmp(cmd[1], "-"))
		cd_util3(built);
	else
	{
		if (chdir(cmd[1]) == -1)
			check_dir(cmd[1]);
		else
		{
			old = get_env(built, "PWD");
			update_pwd(built, "OLDPWD", old);
			update_pwd(built, "PWD", getcwd(str, sizeof(str)));
			free (old);
			g_glob.ex_st = 0;
		}
	}
}
