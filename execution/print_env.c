/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:12:00 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/01 22:33:45 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	print_env(t_exec *exec)
{
	while (exec)
	{
		if (exec->name && exec->value)
			printf("%s=%s\n", exec->name, exec->value);
		exec = exec->next;
	}
}
