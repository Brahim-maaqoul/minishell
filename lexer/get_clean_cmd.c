/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_clean_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 03:05:59 by orekabe           #+#    #+#             */
/*   Updated: 2022/08/25 23:21:50 by orekabe          ###   ########.fr       */
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

int	check_ws(char c)
{
	if (c == ' ' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r' || c == '\n')
		return (1);
	return (0);
}

void	rm_extra_sp(char *n_cmd)
{
	int		i;
	int		j;
	int		p;
	char	c;

	i = -1;
	while (n_cmd[++i])
	{
		p = 0;
		if (n_cmd[i] == '"' || n_cmd[i] == '\'')
		{
			c = n_cmd[i];
			while (n_cmd[++i] != c && n_cmd[i])
				;
		}
		if (n_cmd[i] == ' ')
		{
			p = 1;
			j = i + 1;
		}
		while (p && n_cmd[j] == ' ')
			j++;
		if (p)
			ft_memmove(n_cmd + i + 1, n_cmd + j, ft_strlen(n_cmd) - i);
	}
}

void	add_need_sp(char *cmd, char *n_cmd)
{
	int	i;
	int	j;
	int	p;

	i = -1;
	p = -1;
	while (cmd[++i])
	{
		if (check_sc(cmd[i]))
		{
			if (cmd[i - 1] != ' ' && cmd[i] != cmd[i - 1] && i > 0)
			{
				j = i + (++p);
				ft_memmove(n_cmd + j + 1, n_cmd + j, ft_strlen(cmd) - i);
				n_cmd[j] = ' ';
			}
			if (cmd[i + 1] != ' ' && cmd[i] != cmd[i + 1])
			{
				j = i + (++p);
				ft_memmove(n_cmd + j + 2, n_cmd + j + 1, ft_strlen(cmd) - i);
				n_cmd[j + 1] = ' ';
			}
		}
	}
}

char	*get_clean_cmd(char *n_cmd)
{
	int	len;

	while (*n_cmd == ' ')
		n_cmd++;
	len = ft_strlen(n_cmd) - 1;
	while (n_cmd[len] == ' ')
		len--;
	n_cmd[len + 1] = '\0';
	return (n_cmd);
}