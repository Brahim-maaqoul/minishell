/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 00:27:28 by orekabe           #+#    #+#             */
/*   Updated: 2022/09/24 23:12:06 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list *lst)
{
	t_list	*temp;
	t_list	*curr;

	if (!lst)
		return ;
	curr = lst;
	while (curr != NULL)
	{
		temp = curr;
		curr = curr->next;
		if (temp->content)
		{
			free(temp->content);
			temp->content = NULL;
			temp->next = NULL;
		}
		if (temp)
		{
			free(temp);
			temp = NULL;
		}
	}
}
