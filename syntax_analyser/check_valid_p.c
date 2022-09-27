/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 03:38:05 by orekabe           #+#    #+#             */
/*   Updated: 2022/09/27 00:44:20 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyser.h"

int	ft_check_q(char c, int flag)
{
	if (!flag && (c == '"' || c == '\''))
		return (1);
	if (flag && (c == '"' || c == '\''))
		return (0);
	return (flag);
}

int	check_vp1(char *cmd)
{
	int		i;
	char	*str;
	int		q;

	i = ft_strlen(cmd) - 1;
	q = 0;
	str = NULL;
	while (i >= 2)
	{
		q = ft_check_q(cmd[i], q);
		if (!q && cmd[i] == ')' && (cmd[i - 2] == '(' || cmd[i - 2] == ')'
				|| check_reder(cmd[i - 2]) || check_pipe(cmd[i - 2])))
		{
			p_err(cmd + i, str);
			return (0);
		}
		i--;
	}
	return (1);
}

int	check_vp2(char *cmd)
{
	int		i;
	char	*str;
	int		q;

	i = ft_strlen(cmd) - 1;
	q = 0;
	str = NULL;
	while (i >= 2)
	{
		q = ft_check_q(cmd[i], q);
		if (!q && (cmd[i] != ')' && cmd[i] != '|' && cmd[i] != '&'
				&& cmd[i] != '>' && cmd[i] != '<') && cmd[i - 2] == ')')
		{
			p_err(cmd + i, str);
			return (0);
		}
		i--;
	}
	return (1);
}

int	check_vp3(char *cmd)
{
	int		i;
	char	*str;
	int		q;

	i = 0;
	q = 0;
	str = NULL;
	while (cmd[i])
	{
		q = ft_check_q(cmd[i], q);
		if (!q && cmd[i] == '(' && check_pipe(cmd[i + 2]))
		{
			p_err(cmd + i + 2, str);
			return (0);
		}
		if (i > 1 && !q && cmd[i] == '(' && !check_pipe(cmd[i - 2])
			&& cmd[i - 2] != '(')
		{
			p_err(cmd + i, str);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_valid_p(char *cmd)
{
	if (check_vp1(cmd) && check_vp2(cmd) && check_vp3(cmd))
		return (1);
	return (0);
}
