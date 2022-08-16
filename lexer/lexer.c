/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 23:03:15 by orekabe           #+#    #+#             */
/*   Updated: 2022/08/16 02:51:27 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	get_token(char *str)
{
	if (!ft_strncmp(str, "&&", 2))
		return (AND);
	else if (!ft_strncmp(str, "||", 2))
		return (OR);
	else if (!ft_strncmp(str, "|", 1))
		return (PIPE);
	else if (!ft_strncmp(str, "<", 1))
		return (L_RD);
	else if (!ft_strncmp(str, ">", 1))
		return (R_RD);
	else if (!ft_strncmp(str, "<<", 2))
		return (DL_RD);
	else if (!ft_strncmp(str, ">>", 2))
		return (DR_RD);
	else if (!ft_strncmp(str, " ", 1))
		return (SP);
	return (WORD);
}

t_list	*tokenizer(t_list *lst, char *n_cmd)
{
	t_list	*tmp;
	int		i;
	int		j;
	int		b;

	i = 0;
	j = 0;
	b = 0;
	tmp = lst;
	while (n_cmd[i])
	{
		if (n_cmd[i] == ' ')
		{
			tmp = ft_lstnew(ft_strndup(n_cmd + j, i - j), get_token(tmp->content));
			ft_lstadd_back(&lst, tmp);
			tmp = tmp->next;
			j = i + 1;
			b = 1;
		}
		if (b)
		{
			tmp = ft_lstnew(ft_strndup(" ", 1), SP);
			ft_lstadd_back(&lst, tmp);
			tmp = tmp->next;
			b = 0;
		}
		i++;
	}
	return (lst);
}

t_list	*lexer(char *cmd, char *n_cmd, t_list *lst)
{
	n_cmd = ft_calloc(ft_strlen(cmd) * 2, sizeof(char));
	n_cmd = ft_strncpy(cmd, n_cmd, ft_strlen(cmd));
	add_need_sp(cmd, n_cmd);
	rm_extra_sp(n_cmd);
	lst = tokenizer(lst, n_cmd);
	return (lst);
}
