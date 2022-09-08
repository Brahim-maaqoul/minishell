/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 00:06:20 by orekabe           #+#    #+#             */
/*   Updated: 2022/09/04 21:40:47 by bmaaqoul         ###   ########.fr       */
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
		add_history(cmd);
		lst = lexer(cmd, n_cmd, lst);
	}
	// while (lst)
	// {
	// 	printf("%s ----> %d\n", lst->content, lst->token);
	// 	lst = lst->next;
	// }
}
