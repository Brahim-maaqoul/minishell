/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:36:31 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/09/06 13:37:11 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyser.h"

int	check_reder(char c)
{
	if (c == '<' || c == '>')
		return (c);
	return (0);
}

int	check_pipe(char c)
{
	if (c == '|' || c == '&')
		return (c);
	return (0);
}

int	check_parenth(char c)
{
	if (c == '(' || c == ')')
		return (c);
	return (0);
}

int	check_borders(char *str)
{
	if (check_pipe(str[0]))
	{
		if (str[1] == str[0])
			print_errs(str, 2, 0);
		else
			print_errs(str, 1, 0);
		return (1);
	}
	return (0);
}
