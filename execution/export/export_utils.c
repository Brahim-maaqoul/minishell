/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:20:20 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/01 22:07:13 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void	ft_swap(t_exec *p1, t_exec *p2)
{
	char	*tmp;
	char	*tmp1;

	tmp = p1->name;
	tmp1 = p1->value;
	p1->name = p2->name;
	p1->value = p2->value;
	p2->name = tmp;
	p2->value = tmp1;
}

int	get_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (0);
}

int	get_plus(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' && str[i + 1] == '=')
			return (i);
		i++;
	}
	return (0);
}

int	check_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

void	sort_name(t_exec *tmp, t_exec *tmp2)
{
	t_exec	*tmp1;

	while (tmp)
	{
		tmp1 = tmp2;
		while (tmp1)
		{
			if (tmp1->next && ft_strcmp(tmp1->name, tmp1->next->name) > 0)
				ft_swap(tmp1, tmp1->next);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}
