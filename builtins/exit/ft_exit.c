/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 02:34:02 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/20 20:20:09 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

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

int	check_arguments(char **args)
{
	int	i;

	i = 1;
	if (!args[1])
	{
		put_err("exit\n");
		exit(g_glob.ex_st);
	}
	if (args[1] && !is_numeric(args[1]))
		exit (255);
	while (args[i])
		i++;
	if (i > 2)
	{
		put_err("exit\n");
		put_err("mini'c'hill: exit: too many arguments\n");
		g_glob.ex_st = 1;
		return (1);
	}
	return (0);
}

void	ft_exit(char **args)
{
	long long	nbr;

	if (check_arguments(args))
		return ;
	check_overflow_min(args[1]);
	check_overflow_max(args[1]);
	nbr = check_num(args[1]);
	if (nbr == -923372036854775808)
	{
		put_err("exit\n");
		exit (0);
	}
	else if (nbr % 256 < 0)
	{
		g_glob.ex_st = (nbr % 256) + 256;
		put_err("exit\n");
		exit (g_glob.ex_st);
	}
	else
	{
		g_glob.ex_st = nbr % 256;
		put_err("exit\n");
		exit (g_glob.ex_st);
	}
}
