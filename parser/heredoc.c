/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 04:19:09 by orekabe           #+#    #+#             */
/*   Updated: 2022/10/20 18:04:42 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*change_del(char *str, t_tree *root)
{
	char	*tmp;
	int		i;
	int		b;

	i = 0;
	b = 0;
	while (str[i])
	{
		if (str[i] == -1)
		{
			str[i] = '"';
			b = 1;
		}
		if (str[i] == -2)
		{
			str[i] = '\'';
			b = 1;
		}
		i++;
	}
	if (b)
		root->exp_h = 0;
	tmp = ft_strtrim(str, "\"'");
	return (tmp);
}

void	fill_heredoc(t_tree *node, t_tree *root)
{
	char	*line;
	char	*here;
	char	*tmp_line;
	char	*tmp_here;
	char	*tmp;

	if (!g_glob.gl)
		return ;
	here = ft_calloc(1, sizeof(char));
	tmp = change_del(node->list->content, root);
	line = readline("> ");
	while (line && ft_strcmp(line, tmp) && g_glob.gl)
	{
		tmp_here = here;
		tmp_line = ft_strjoin(line, "\n");
		here = ft_strjoin(tmp_here, tmp_line);
		free(tmp_line);
		free(tmp_here);
		free(line);
		line = readline("> ");
	}
	free(line);
	free(tmp);
	free(node->list->content);
	node->list->content = here;
}

void	get_heredoc(t_tree *node)
{
	if (node)
	{
		if (node->list->token == 6)
			fill_heredoc(node->right, node);
		get_heredoc(node->left);
		get_heredoc(node->right);
	}
	return ;
}
