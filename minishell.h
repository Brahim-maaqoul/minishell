/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 23:37:03 by orekabe           #+#    #+#             */
/*   Updated: 2022/08/26 01:33:27 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "libft/libft.h"
# include "lexer/lexer.h"
# include "syntax_analyser/syntax_analyser.h"

typedef struct s_tree
{
	char			*token;
	char			*cmd;
	struct s_tree	*left;
	struct s_tree	*right;
}				t_tree;

t_tree	*ft_treenew(char *token, char *cmd);
void	ft_addleaf(t_tree *root, t_tree *leaf);
void	ft_addroot(t_tree *root, t_tree *leaf);

#endif
