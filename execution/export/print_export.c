/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:03:59 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/01 23:53:58 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void	print_export(t_exec *exec)
{
	while (exec)
	{
		if (exec->name)
		{
			printf("declare -x %s", exec->name);
			if (!exec->value)
				printf("\n");
		}
		if (exec->value)
			printf("=\"%s\"\n", exec->value);
		exec = exec->next;
	}
}
