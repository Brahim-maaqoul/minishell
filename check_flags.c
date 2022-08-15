/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:41:54 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/08/15 23:52:52 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_pos(char	*str, int flag)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == flag)
			return (i);
		i++;
	}
	return (0);
}

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
	int	j;
	char	*tmp1;
	char	*tmp2;
	char	*tmp;
	// t_list	*new
	// new = list;
	i = 0;
	j = i;
	// list->content = ft_strdup("");
	while (list->line[i])
	{
		if (check_pipe(list, i))
		{
			// list->content = ft_substr(list->line, i, get_pos(list->line, PIPE));
			// printf("%d\n", get_pos(list->line, PIPE));
			list->content = ft_strncpy(tmp1, list->line, i - j);
			// printf("%s\n", tmp2);
			// printf("%s\n", "hmm0");
			j = i;
			ft_lstadd_back(&list, ft_lstnew(list->content, word));
			// printf("%s\n", list->content);
			tmp2 = ft_substr(list->line, i, 1);
			ft_lstadd_back(&list, ft_lstnew(tmp2, PIPE));
			printf("%s\n", list->content);

		}
		i++;
	}
}