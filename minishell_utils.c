/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:59:15 by orekabe           #+#    #+#             */
/*   Updated: 2022/10/20 20:00:41 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_d(char *cmd)
{
	if (!cmd && g_glob.gl)
	{
		printf("exit\n");
		exit (g_glob.ex_st);
	}
}

int	event(void)
{
	return (0);
}
