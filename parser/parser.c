/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:00:38 by orekabe           #+#    #+#             */
/*   Updated: 2022/09/24 23:29:56 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*rm_par(char *str, t_list *n_list, t_lx_var *lx_var)
{
	lx_var->tmp = n_list;
	lx_var->str = NULL;
	lx_var->i = 0;
	lx_var->j = 0;
	lx_var->q = 0;
	str[ft_strlen(str) - 1] = '\0';
	str++;
	str = get_clean_cmd(str);
	return (str);
}

t_tree	*ft_treenew(t_list *list)
{
	t_tree	*new;

	new = (t_tree *)malloc(sizeof(t_tree));
	if (!new)
		return (NULL);
	new->list = list;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

t_tree	*parser(t_list *list)
{
	t_tree	*root;

	root = ast_lvl1(list);
	return (root);
}
