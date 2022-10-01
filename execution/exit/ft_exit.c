/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 02:34:02 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/01 22:57:03 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

long long	check_num(char *str)
{
	int			i;
	int			len;
	long long	n;
	long long	rst;

	i = 0;
	rst = 0;
	len = ft_strlen(str);
	n = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		rst = rst * 10 + (str[i] - 48);
		i++;
	}
	return (rst * n);
}

void	check_arguments(char **args)
{
	int	i;

	i = 1;
	if (!args[1])
	{
		put_err("exit\n");
		exit(g_status);
	}
	if (!is_numeric(args[1]))
		exit (255);
	while (args[i])
		i++;
	if (i > 2)
	{
		put_err("exit\n");
		put_err("exit: too many arguments\n");
		g_status = 1;
		return ;
	}
}

void	ft_exit(char *args)
{
	long long	nbr;
	char		**splited;

	splited = ft_split(args, ' ');
	check_arguments(splited);
	check_overflow_min(splited[1]);
	check_overflow_max(splited[1]);
	nbr = check_num(splited[1]);
	if (nbr == -923372036854775808)
	{
		put_err("exit\n");
		exit (0);
	}
	else if (nbr % 256 < 0)
	{
		g_status = (nbr % 256) + 256;
		put_err("exit\n");
		exit (g_status);
	}
	else
	{
		g_status = nbr % 256;
		put_err("exit\n");
		exit (g_status);
	}
}
