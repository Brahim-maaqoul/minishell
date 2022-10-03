/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:48:27 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/03 03:55:55 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

t_built	*ft_builtnew(char *name, char *value)
{
	t_built	*new;

	new = (t_built *)malloc(sizeof(t_built));
	if (!new)
		return (NULL);
	new->name = name;
	new->value = value;
	new->next = NULL;
	return (new);
}
