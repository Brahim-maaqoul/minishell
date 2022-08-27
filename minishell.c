/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 00:06:20 by orekabe           #+#    #+#             */
/*   Updated: 2022/08/27 03:14:21 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*cmd;
	char	*n_cmd;
	t_list	*lst;

	lst = NULL;
	n_cmd = NULL;
	while (1)
	{
		cmd = readline("minishell :");
		lst = lexer(cmd, n_cmd, lst);
	}
	// while (lst)
	// {
	// 	printf("%s ----> %d\n", lst->content, lst->token);
	// 	lst = lst->next;
	// }
}
