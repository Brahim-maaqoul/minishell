/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 01:41:08 by orekabe           #+#    #+#             */
/*   Updated: 2022/09/26 16:27:09 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_tree	*get_node(t_tree *tree, t_list *list, t_list *l_tmp)
{
	tree = ft_treenew(list);
	list->next->prev = NULL;
	if (!list->prev)
	{
		if (list->next->next)
		{
			list->prev = list->next->next;
			list->prev->prev = NULL;
			list->next->next = NULL;
		}
		l_tmp = list->prev;
	}
	else
	{
		list->prev->next = list->next->next;
		list->next->next = NULL;
		if (list->prev->next)
			list->prev->next->prev = list->prev;
	}
	tree->left = ast_lvl3(l_tmp);
	tree->right = ast_lvl4(list->next);
	return (tree);
}

t_tree	*ast_lvl4(t_list *list)
{
	t_tree		*tree;
	t_list		*n_list;
	t_lx_var	lx_var;
	char		*str;

	n_list = NULL;
	tree = NULL;
	if (list && list->token == 11)
	{
		tree = ft_treenew(list);
		lx_var.str = ft_strndup(list->content, ft_strlen(list->content));
		str = lx_var.str;
		lx_var.str = rm_par(str, n_list, &lx_var);
		n_list = tokenizer(n_list, lx_var.str, &lx_var);
		tree->left = parser(n_list);
		free(str);
	}
	else if (list)
	{
		while (list && list->prev)
			list = list->prev;
		tree = ft_treenew(list);
	}
	return (tree);
}

t_tree	*ast_lvl3(t_list *list)
{
	t_tree	*tree;
	t_list	*l_tmp;

	tree = NULL;
	while (list && list->prev)
		list = list->prev;
	l_tmp = list;
	while (list && list->next)
	{
		if (list->token >= 4 && list->token <= 7)
		{
			tree = get_node(tree, list, l_tmp);
			list->next = NULL;
			return (tree);
		}
		list = list->next;
	}
	if (list && !list->next)
	{
		tree = ast_lvl4(list);
		return (tree);
	}
	return (NULL);
}

t_tree	*ast_lvl2(t_list *list)
{
	t_tree	*tree;
	t_list	*l_tmp;

	l_tmp = list;
	while (list && list->prev)
	{
		if (list->token == 3)
		{
			tree = ft_treenew(list);
			list->prev->next = NULL;
			tree->left = ast_lvl2(list->prev);
			list = list->next;
			list->prev->next = NULL;
			list->prev = NULL;
			tree->right = ast_lvl3(l_tmp);
			return (tree);
		}
		list = list->prev;
	}
	if (!list->prev)
	{
		tree = ast_lvl3(l_tmp);
		return (tree);
	}
	return (NULL);
}

t_tree	*ast_lvl1(t_list *list)
{
	t_tree	*tree;
	t_list	*l_tmp;

	l_tmp = list;
	while (list && list->prev)
	{
		if (list->token == 1 || list->token == 2)
		{
			tree = ft_treenew(list);
			list->prev->next = NULL;
			tree->left = ast_lvl1(list->prev);
			list = list->next;
			list->prev->next = NULL;
			list->prev = NULL;
			tree->right = ast_lvl2(l_tmp);
			return (tree);
		}
		list = list->prev;
	}
	if (!list->prev)
	{
		tree = ast_lvl2(l_tmp);
		return (tree);
	}
	return (NULL);
}
