/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 23:03:15 by orekabe           #+#    #+#             */
/*   Updated: 2022/10/20 16:30:02 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	get_q(char	*n_cmd)
{
	char	c;
	int		i;

	i = 1;
	c = n_cmd[0];
	while (n_cmd[i] && n_cmd[i] != c)
		i++;
	return (i);
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

char	*flag_q(char *n_cmd)
{
	char	c;
	int		i;

	i = 0;
	c = 0;
	while (n_cmd[i])
	{
		if (c == n_cmd[i])
		{
			n_cmd[i] = -1 - (n_cmd[i] == '\'');
			c = 0;
		}
		else if (!c && (n_cmd[i] == '"' || n_cmd[i] == '\''))
		{
			c = n_cmd[i];
			n_cmd[i] = -1 - (n_cmd[i] == '\'');
		}
		i++;
	}
	return (n_cmd);
}

t_list	*tokenizer(t_list *lst, char *n_cmd, t_lx_var *lx_var)
{
	while (n_cmd[lx_var->i])
	{
		if ((n_cmd[lx_var->i] == -1 || n_cmd[lx_var->i] == -2)
			&& n_cmd[lx_var->i + 1])
			lx_var->i += get_q(&n_cmd[lx_var->i]);
		if (n_cmd[lx_var->i] == '(')
			lx_var->i += get_p_lvl(&n_cmd[lx_var->i + 1]);
		if (n_cmd[lx_var->i] == ' ')
		{
			lx_var->str = ft_strndup(n_cmd + lx_var->j,
					lx_var->i - lx_var->j);
			lx_var->tmp = ft_lstnew(lx_var->str, get_token(lx_var->str));
			ft_lstadd_back(&lst, lx_var->tmp);
			lx_var->tmp = lx_var->tmp->next;
			lx_var->j = lx_var->i + 1;
		}
		lx_var->i++;
	}
	lx_var->str = ft_strndup(n_cmd + lx_var->j, lx_var->i - lx_var->j + 1);
	lx_var->tmp = ft_lstnew(lx_var->str, get_token(lx_var->str));
	ft_lstadd_back(&lst, lx_var->tmp);
	return (lx_var->tmp);
}

t_list	*lexer(char *cmd, char *n_cmd, t_list *lst)
{
	t_lx_var	lx_var;
	char		*tmp_ncmd;

	init_lx_var(&lx_var, lst);
	n_cmd = ft_calloc(ft_strlen(cmd) * 2, sizeof(char));
	n_cmd = ft_strncpy(cmd, n_cmd, ft_strlen(cmd));
	add_need_sp(cmd, n_cmd);
	rm_extra_sp(n_cmd);
	tmp_ncmd = n_cmd;
	n_cmd = get_clean_cmd(n_cmd);
	n_cmd = ft_strndup(n_cmd, ft_strlen(n_cmd) + 1);
	n_cmd = fill_pipe(n_cmd);
	if (!syntax_analyser(n_cmd) || !check_valid_p(n_cmd))
	{
		g_glob.ex_st = 258;
		free(tmp_ncmd);
		free(n_cmd);
		return (NULL);
	}
	n_cmd = flag_q(n_cmd);
	lst = tokenizer(lst, n_cmd, &lx_var);
	free(tmp_ncmd);
	free(n_cmd);
	return (lst);
}
