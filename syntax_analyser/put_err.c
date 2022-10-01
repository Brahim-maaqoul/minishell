/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 22:47:22 by bmaaqoul          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/30 02:26:11 by bmaaqoul         ###   ########.fr       */
=======
/*   Updated: 2022/09/26 22:08:22 by orekabe          ###   ########.fr       */
>>>>>>> 2469868c048956f9f6f18e66937d07df6ba93cf2
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyser.h"

void	put_err(char *str)
{
	write(2, str, ft_strlen(str));
}

void	print_errs(char *str, int len, int i)
{
	put_err("syntax error near unexpected token `");
	if (len < 2 || len == 3)
	{
		ft_putchar_fd(str[i], 2);
		put_err("'\n");
	}
	else
	{
		ft_putchar_fd(str[i], 2);
		ft_putchar_fd(str[i + 1], 2);
		put_err("'\n");
	}
}

int	fnct1(int d, int s)
{
	if (d % 2 != 0 || s % 2 != 0)
	{
		put_err("error unclosed quotes\n");
		return (0);
	}
	return (1);
}

int	check_quotes(char *str, int c, int lp, int rp)
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
	if (d % 2 != 0 || s % 2 != 0)
	{
		if (!c)
			return (0);
	}
	return (fnct1(d, s));
}
