/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:03:34 by orekabe           #+#    #+#             */
/*   Updated: 2022/10/20 19:45:00 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*fill_pipe(char *cmd)
{
	char	*n_cmd;
	char	*c_cmd;
	char	*t_cmd;
	char	*r_cmd;

	if (cmd[ft_strlen(cmd) - 1] != '|' || ft_strlen(cmd) == 1)
		return (cmd);
	n_cmd = readline("> ");
	if (!n_cmd)
		return (cmd);
	c_cmd = ft_calloc(ft_strlen(n_cmd) * 2, sizeof(char));
	c_cmd = ft_strncpy(n_cmd, c_cmd, ft_strlen(n_cmd));
	add_need_sp(n_cmd, c_cmd);
	rm_extra_sp(c_cmd);
	t_cmd = c_cmd;
	c_cmd = get_clean_cmd(c_cmd);
	free(n_cmd);
	n_cmd = ft_strndup(c_cmd, ft_strlen(c_cmd));
	c_cmd = ft_strjoin(" ", n_cmd);
	r_cmd = ft_strjoin(cmd, c_cmd);
	free(t_cmd);
	free(n_cmd);
	free(c_cmd);
	free(cmd);
	return (fill_pipe(r_cmd));
}

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

void	init_lx_var(t_lx_var *lx_var, t_list *lst)
{
	lx_var->tmp = lst;
	lx_var->str = NULL;
	lx_var->i = 0;
	lx_var->j = 0;
	lx_var->q = 0;
}
