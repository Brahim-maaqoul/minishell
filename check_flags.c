/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:41:54 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/08/14 04:26:55 by bmaaqoul         ###   ########.fr       */
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
	char	*tmp1;
	char	*tmp2;
	t_list	*new;
	// t_list	*new
	// new = list;
	i = 0;
	while (list->line[i])
	{
		if (check_pipe(list, i))
		{
			tmp2 = ft_strncpy(tmp1, list->line, i);
			// printf("%s\n", tmp2);
			// printf("%s\n", "hmm0");
			ft_lstadd_back(&list, ft_lstnew(tmp2, word));
		}
		i++;
	}
}