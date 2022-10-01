/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 00:48:55 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/09/27 01:19:26 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyser.h"

int	check_p_in_q(char *str, int i)
{
	if ((str[i + 2] == str[i + 3] && check_pipe(str[i + 2])))
	{
		if (!check_quotes(str + i, 0, 0, 0))
			return (1);
		print_errs(str, 2, i + 2);
		return (0);
	}
	return (1);
}

int	handle_pipe(char *str, int i)
{
	if (check_pipe(str[i]))
	{
		if (!check_p_in_q(str, i))
			return (0);
		if (str[i] == str[i + 1] && check_reder(str[i - 2]))
		{
			print_errs(str, 2, i);
			return (0);
		}
		else if ((str[i] == str[i + 2] && str[i + 3])
			|| (check_pipe(str[i + 2])
				&& str[i + 3]) || check_reder(str[i - 2]))
		{
			if (!check_quotes(str + i, 0, 0, 0))
				return (1);
			if (check_reder(str[i - 2]))
				print_errs(str, 1, i);
			else
				print_errs(str, 1, i + 2);
			return (0);
		}
	}
	return (1);
}

int	handle_red(char *str, int i)
{
	if (check_reder(str[i]))
	{
		if (str[i + 2] == check_reder(str[i + 2])
			&& str[i + 2] == str[i + 3])
		{
			if (!check_quotes(str + i, 0, 0, 0))
				return (1);
			print_errs(str, 2, i + 2);
			return (0);
		}
		else if (str[i + 2] == check_reder(str[i + 2]))
		{
			if (!check_quotes(str + i, 0, 0, 0))
				return (1);
			print_errs(str, 1, i + 2);
			return (0);
		}
	}
	return (1);
}

int	check_middle(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] == '<' || str[i] == '>')
			&& (!str[i + 1] || !str[i + 2]))
		{
			put_err("syntax error near unexpected token `newline'\n");
			return (0);
		}
		if (str[i] == '&' && str[i + 1] != '&'
			&& str[i - 1] != '&')
		{
			print_errs(str, 1, i);
			return (0);
		}
		if (!handle_pipe(str, i))
			return (0);
		if (!handle_red(str, i))
			return (0);
	}
	return (1);
}

int	syntax_analyser(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	if (!check_quotes(str, 1, 0, 0) || !check_par(str, 0, 0))
		return (0);
	if (check_borders(str))
		return (0);
	if (!check_middle(str))
		return (0);
	if ((check_pipe(str[len]) && ((str[len] == str[len - 1])
				&& str[len - 1] != str[len - 2])))
	{
		print_errs(str, 2, len - 1);
		return (0);
	}
	if (check_pipe(str[len]) && !str[len + 1])
	{
		print_errs(str, 1, len);
		return (0);
	}
	return (1);
}
