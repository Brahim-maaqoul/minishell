/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:41:54 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/08/06 16:40:57 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_pipe(t_list *list, int i)
{
	if (list->line[i] == PIPE)
		return (1);
	return (0);
}

int	check_leftred(t_list *list, int i)
{
	if (list->line[i] == left_red)
		return (1);
	return (0);
}

int	check_rightred(t_list *list, int i)
{
	if (list->line[i] == right_red)
		return (1);
	return (0);
}

int	check_space(t_list *list, int i)
{
	if (list->line[i] == space)
		return (1);
	return (0);
}

void	check_word(t_list *list)
{
	int	i;
	char	*tmp;

	i = 0;
	while (list->line[i])
	{
		if (check_pipe(list, i))
		{
			ft_lstnew(list->line+i, PIPE);
			list = list->next;
		}
		else if (check_leftred(list, i))
		{
			ft_lstnew(list->line+i, left_red);
			list = list->next;
		}
		else if (check_rightred(list, i))
		{
			ft_lstnew(list->line+i, right_red);
			list = list->next;
		}
		else if (check_space(list, i))
		{
			ft_lstnew(list->line+i, space);
			list = list->next;
		}
		else
		{
			tmp[i] = list->line[i];
			if (check_pipe(list, i + 1) || check_leftred(list, i+ 1)
				|| check_rightred(list, i + 1) || check_space(list, i + 1))
			{
				ft_lstnew(list->line, word);
				list = list->next;
			}
		}
		i++;
	}
}