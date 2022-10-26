/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 03:18:40 by orekabe           #+#    #+#             */
/*   Updated: 2022/10/18 23:09:21 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	and_or(t_tree *node, t_built **built)
{
	exec_tree(node->left, built);
	if ((!g_glob.ex_st && node->list->token == 1)
		|| (g_glob.ex_st && node->list->token == 2))
		exec_tree(node->right, built);
	return ;
}
