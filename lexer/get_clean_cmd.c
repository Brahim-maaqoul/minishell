/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_clean_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 03:05:59 by orekabe           #+#    #+#             */
/*   Updated: 2022/08/14 03:06:39 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	check_sc(char c)
{
	if (c == '|' || c == '&' || c == '<'
		|| c == '>' || c == '(' || c == ')')
		return (1);
	return (0);
}

int		check_ws(char c)
{
	if (c == ' ' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r' || c == '\n')
		return (1);
	return (0);
}

void	rm_extra_sp(char *n_cmd)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	while(n_cmd[i])
	{
		p = 0;
		if (n_cmd[i] == ' ')
		{
			p = 1;
			j = i + 1;
		}
		while (p && n_cmd[j] == ' ')
			j++;
		if (p)
			ft_memmove(n_cmd + i + 1, n_cmd + j, ft_strlen(n_cmd) - i);
		i++;
	}
}

void	add_need_sp(char *cmd, char *n_cmd)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	j = 0;
	p = 0;
	while(cmd[i])
	{
		if (check_sc(cmd[i]))
		{
			if (cmd[i - 1] != ' ' && cmd[i] != cmd[i - 1])
			{
				j = i + p;
				ft_memmove(n_cmd + j + 1, n_cmd + j, ft_strlen(cmd) - i);
				n_cmd[j] = ' ';
				p++;
			}
			if (cmd[i + 1] != ' ' && cmd[i] != cmd[i + 1])
			{
				j = i + p;
				ft_memmove(n_cmd + j + 2, n_cmd + j + 1, ft_strlen(cmd) - i);
				n_cmd[j + 1] = ' ';
				p++;
			}
		}
		i++;
	}
}
