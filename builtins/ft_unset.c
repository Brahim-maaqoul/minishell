/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:42:35 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/16 19:25:54 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	check_err(char *str)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			a = 1;
		else
		{
			if (ft_isdigit(str[i]) && !a)
				return (0);
			else if (!ft_isdigit(str[i]) && str[i] != '_')
				return (0);
		}
		i++;
	}
	return (1);
}

t_built	*remove_env(t_built *head, char *str)
{
	t_built	*node;
	t_built	*next;

	node = head;
	if (node && !ft_strcmp(str, node->name))
	{
		head = node->next;
		del_list(node);
		return (head);
	}
	while (node && node->next)
	{
		if (!ft_strcmp(str, node->next->name))
		{
			next = node->next;
			node->next = next->next;
			del_list(next);
			break ;
		}
		node = node->next;
	}
	return (head);
}

void	ft_unset(t_built **built, char **cmd)
{
	int		j;
	int		b;

	j = 1;
	if (!cmd[j])
		g_glob.ex_st = 0;
	while (cmd[j])
	{
		b = 0;
		if (!check_err(cmd[j]))
		{
			put_err("minishell: unset: `");
			put_err(cmd[j]);
			put_err("': not a valid identifier\n");
			b = 1;
			g_glob.ex_st = 1;
		}
		if (!b)
			*built = remove_env(*built, cmd[j]);
		j++;
	}
}
