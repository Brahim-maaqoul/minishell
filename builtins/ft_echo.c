/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 02:35:04 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/18 03:05:50 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	check_n(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 1;
	while (*str == '-' && str[i] == 'n')
		i++;
	if (i == len && len > 1)
		return (1);
	return (0);
}

void	ft_echo(char **args)
{
	int		i;

	i = 1;
	while (args[i] && check_n(args[i]))
		i++;
	while (args[i])
	{
		if (args[i][0] == '#')
			break ;
		ft_putstr_fd(args[i], 1);
		if (args[i + 1] && args[i + 1][0] != '#')
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (!args[1] || !check_n(args[1]))
		printf("\n");
	g_glob.ex_st = 0;
}
