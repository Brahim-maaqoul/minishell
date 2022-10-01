/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_par.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 01:30:26 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/09/26 20:20:22 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyser.h"

void	p_err(char *cmd, char *str)
{
	int	i;

	i = 0;
	put_err("syntax error near unexpected token `");
	while (cmd[i] && cmd[i] != ' ')
		i++;
	str = ft_strndup(cmd, i);
	put_err(str);
	put_err("'\n");
	free(str);
}

int	fcnt2(int lp, int rp)
{
	if (lp != rp)
	{
		put_err("error unclosed parentheses\n");
		return (0);
	}
	return (1);
}

int	check_par(char *str, int lp, int rp)
{
	int	i;
	int	d;
	int	s;

	i = -1;
	d = 0;
	s = 0;
	while (str[++i])
	{
		if (str[i] == '"' && s % 2 == 0)
			d++;
		else if (str[i] == '\'' && d % 2 == 0)
			s++;
		else if (str[i] == '(' && (s % 2 == 0 && d % 2 == 0))
			lp += 1;
		else if (str[i] == ')' && (s % 2 == 0 && d % 2 == 0))
			rp += 1;
	}
	return (fcnt2(lp, rp));
}
