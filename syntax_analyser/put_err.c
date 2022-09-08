/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 22:47:22 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/09/08 14:23:10 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyser.h"

void	put_err(char *str)
{
	write(2, str, ft_strlen(str));
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	print_errs(char *str, int len, int i)
{
	if (!check_quotes(str + i, 0, 0, 0))
		return ;
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
	free (str);
}

int	fnct1(int d, int s, int lp, int rp)
{
	if (d % 2 != 0 || s % 2 != 0)
	{
		put_err("error unclosed quotes\n");
		return (0);
	}
	if (lp != rp)
	{
		put_err("error unclosed parentheses\n");
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
	return (fnct1(d, s, lp, rp));
}
