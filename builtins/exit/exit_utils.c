/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:34:57 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/03 03:47:53 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

void	print_num_err(char *str)
{
	put_err("exit: ");
	put_err(str);
	put_err(": numeric argument required\n");
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			print_num_err(str);
			return (0);
		}
		i++;
	}
	return (1);
}

void	check_overflow(char *str, char *tab)
{
	if (ft_strlen(str) > ft_strlen(tab))
	{
		put_err("exit\n");
		print_num_err(str);
		g_status = 255;
		exit (255);
	}
}

void	check_overflow_max(char *str)
{
	int		i;
	int		len;
	char	*tab;

	tab = "9223372036854775807";
	len = ft_strlen(str);
	if (ft_isdigit(*str))
		check_overflow(str, tab);
	i = 0;
	if (len == ft_strlen("9223372036854775807"))
	{
		while (str[i])
		{
			if (str[i] > tab[i])
			{
				put_err("exit\n");
				print_num_err(str);
				g_status = 255;
				exit (255);
			}
			else if (str[i] < tab[i])
				return ;
			i++;
		}
	}
}

void	check_overflow_min(char *str)
{
	int		i;
	int		len;
	char	*tab;

	tab = "-9223372036854775808";
	len = ft_strlen(str);
	check_overflow(str, tab);
	i = 0;
	if (len == ft_strlen("-9223372036854775808"))
	{
		while (str[i])
		{
			if (str[i] > tab[i])
			{
				put_err("exit\n");
				print_num_err(str);
				g_status = 255;
				exit (255);
			}
			else if (str[i] < tab[i])
				return ;
			i++;
		}
	}
}
