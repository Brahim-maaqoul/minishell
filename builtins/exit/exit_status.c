/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:43:01 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/18 03:14:30 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

int	exit_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WTERMSIG(status) != SIGINT)
	{
		if (WTERMSIG(status) == SIGQUIT)
			printf("Quit: ");
		printf("%d", WTERMSIG(status));
	}
	printf("\n");
	return (128 + WTERMSIG(status));
}
