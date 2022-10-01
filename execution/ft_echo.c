/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 02:35:04 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/01 23:39:05 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

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

void	ft_echo(char *args)
{
	char	**splited;
	int		i;

	i = 1;
	splited = ft_split(args, ' ');
	while (splited[i] && check_n(splited[i]))
		i++;
	while (splited[i])
	{
		ft_putstr_fd(splited[i], 1);
		if (splited[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (!splited[1] || !check_n(splited[1]))
		printf("\n");
}
