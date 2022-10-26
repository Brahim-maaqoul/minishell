/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 00:29:01 by orekabe           #+#    #+#             */
/*   Updated: 2022/10/20 16:35:57 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	alphanum(char c)
{
	int	i;

	i = 0;
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	if (c == '_' || c == '?')
		return (1);
	return (0);
}

char	*get_expand(char *str, t_built **built)
{
	char	*bash;
	int		i;

	i = 0;
	bash = NULL;
	while (str[i] && str[i] != ' ')
	{
		if (str[i] == '0' && !bash)
			bash = ft_strndup("minishell", ft_strlen("minishell"));
		else if (str[i] == '?' && !bash)
			bash = ft_itoa(g_glob.ex_st);
		else if (check_alphanum(str[i]) == 2)
			return (expand_num(str + i, bash));
		else if (check_alphanum(str[i]) && bash)
			return (expand_z_alpha(str + i, bash));
		else if (check_alphanum(str[i]))
			return (expand_var(str + i, built));
		i++;
	}
	return (bash);
}

char	*expand(char *arg, t_built **built)
{
	t_exp	var;
	int		i;

	i = 0;
	var.built = built;
	while (arg[i] && alphanum(arg[i]))
		i++;
	var.str = ft_strndup(arg, i);
	if (i)
		var.exp = get_expand(var.str, var.built);
	else
		var.exp = ft_strdup("$");
	free(var.str);
	var.str = expander(arg + i, built);
	var.ret = ft_strjoin(var.exp, var.str);
	free(var.exp);
	free(var.str);
	return (var.ret);
}

char	*expander(char *arg, t_built **built)
{
	t_exp	var;
	int		i;

	i = 0;
	var.built = built;
	while (arg[i] && arg[i] != '$')
	{
		if (arg[i] == -2)
			i += check_sq(arg + i);
		i++;
	}
	var.str = ft_strndup(arg, i);
	if (!arg[i])
		return (var.str);
	var.exp = expand(arg + i + 1, built);
	var.ret = ft_strjoin(var.str, var.exp);
	free(var.str);
	free(var.exp);
	return (var.ret);
}

void	get_args(t_tree *node, t_built **built)
{
	t_list	*tmp;
	char	*exp;
	int		i;

	(void)built;
	tmp = node->list;
	while (tmp)
	{
		exp = expander(tmp->content, built);
		exp = flag_sp(exp);
		node->args = ft_tabjoin(node->args, ft_split(exp, -3));
		free(exp);
		tmp = tmp->next;
	}
	node->args = wild_card(node->args);
	i = 0;
	while (node->args[i])
	{
		rm_q(node->args[i]);
		i++;
	}
	return ;
}
