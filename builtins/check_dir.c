/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 02:06:12 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/18 03:07:51 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	check_dir(char *path)
{
	put_err("cd: ");
	put_err(path);
	put_err(": No such file or directory\n");
	g_glob.ex_st = 1;
}
