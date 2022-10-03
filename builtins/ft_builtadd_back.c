/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:53:35 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/03 03:55:48 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_builtadd_back(t_built **lst, t_built *new)
{
	t_built	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while ((tmp)->next)
			tmp = (tmp)->next;
		tmp->next = new;
		new->next = NULL;
	}
}
