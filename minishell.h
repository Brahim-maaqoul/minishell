/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 23:37:03 by orekabe           #+#    #+#             */
/*   Updated: 2022/10/20 20:01:17 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "lexer/lexer.h"
# include "parser/parser.h"
# include "builtins/builtins.h"
# include "exec/exec.h"

typedef struct s_var
{
	char	*cmd;
	char	*n_cmd;
	t_built	*built;
	t_list	*list;
	t_tree	*tree;
}				t_var;

void	free_tree(t_tree *root);
void	print_tree(t_tree *tree, int lvl);
void	ctrl_d(char *cmd);
int		event(void);

#endif
