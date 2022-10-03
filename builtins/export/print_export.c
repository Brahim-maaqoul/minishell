/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:03:59 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/03 03:52:17 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

void	print_export(t_built *built)
{
	while (built)
	{
		if (built->name)
		{
			printf("declare -x %s", built->name);
			if (!built->value)
				printf("\n");
		}
		if (built->value)
			printf("=\"%s\"\n", built->value);
		built = built->next;
	}
}
