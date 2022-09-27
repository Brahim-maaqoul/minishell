/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 23:03:15 by orekabe           #+#    #+#             */
/*   Updated: 2022/09/26 21:26:15 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	get_token(char *str)
{
	if (!ft_strncmp(str, "&&", 2))
		return (AND);
	else if (!ft_strncmp(str, "||", 2))
		return (OR);
	else if (!ft_strncmp(str, "|", 1))
		return (PIPE);
	else if (!ft_strncmp(str, "<<", 2))
		return (DL_RD);
	else if (!ft_strncmp(str, ">>", 2))
		return (DR_RD);
	else if (!ft_strncmp(str, "<", 1))
		return (L_RD);
	else if (!ft_strncmp(str, ">", 1))
		return (R_RD);
	else if (!ft_strncmp(str, " ", 1))
		return (SP);
	else if (!ft_strncmp(str, "(", 1))
		return (P);
	return (WORD);
}

int	check_q(char c, int flag)
{
	if (!flag && (c == '"' || c == '\''))
		return (1);
	if (flag && (c == '"' || c == '\''))
		return (0);
	return (flag);
}

int	get_p_lvl(char *n_cmd)
{
	int	i;
	int	p;
	int	lvl;

	i = 0;
	p = 1;
	lvl = 1;
	while (n_cmd[i] && p > 0)
	{
		if (n_cmd[i] == '(')
		{
			p++;
			lvl++;
		}
		if (n_cmd[i] == ')')
			p--;
		i++;
	}
	return (i);
}

t_list	*tokenizer(t_list *lst, char *n_cmd, t_lx_var *lx_var)
{
	while (n_cmd[lx_var->i])
	{
		lx_var->q = check_q(n_cmd[lx_var->i], lx_var->q);
		if (n_cmd[lx_var->i] == '(')
			lx_var->i += get_p_lvl(&n_cmd[lx_var->i + 1]);
		if (n_cmd[lx_var->i] == ' ' && !lx_var->q)
		{
			lx_var->str = ft_strndup(n_cmd + lx_var->j, lx_var->i - lx_var->j);
			lx_var->tmp = ft_lstnew(lx_var->str, get_token(lx_var->str));
			ft_lstadd_back(&lst, lx_var->tmp);
			lx_var->tmp = lx_var->tmp->next;
			lx_var->j = lx_var->i + 1;
		}
		lx_var->i++;
	}
	lx_var->str = ft_strndup(n_cmd + lx_var->j, lx_var->i - lx_var->j);
	lx_var->tmp = ft_lstnew(lx_var->str, get_token(lx_var->str));
	ft_lstadd_back(&lst, lx_var->tmp);
	return (lx_var->tmp);
}

t_list	*lexer(char *cmd, char *n_cmd, t_list *lst)
{
	t_lx_var	lx_var;

	lx_var.tmp = lst;
	lx_var.str = NULL;
	lx_var.i = 0;
	lx_var.j = 0;
	lx_var.q = 0;
	n_cmd = ft_calloc(ft_strlen(cmd) * 2, sizeof(char));
	n_cmd = ft_strncpy(cmd, n_cmd, ft_strlen(cmd));
	add_need_sp(cmd, n_cmd);
	rm_extra_sp(n_cmd);
	n_cmd = get_clean_cmd(n_cmd);
	if (!syntax_analyser(n_cmd) || !check_valid_p(n_cmd))
	{
		free(n_cmd);
		return (NULL);
	}
	lst = tokenizer(lst, n_cmd, &lx_var);
	free(n_cmd);
	return (lst);
}
