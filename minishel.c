/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 00:06:20 by orekabe           #+#    #+#             */
/*   Updated: 2022/08/16 03:56:04 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*cmd;
	char	*n_cmd;
	t_list	*lst;

	lst = NULL;
	cmd = readline("minishell :");
	n_cmd = NULL;
	lst = lexer(cmd, n_cmd, lst);
	while (lst)
	{
		printf("%s ----> %d\n", lst->content, lst->token);
		lst = lst->next;
	}
	
}
