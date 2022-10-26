/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:12:00 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/16 19:46:28 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	print_env(t_built *built)
{
	while (built)
	{
		if (built->name && built->value)
			printf("%s=%s\n", built->name, built->value);
		built = built->next;
	}
	g_glob.ex_st = 0;
}
