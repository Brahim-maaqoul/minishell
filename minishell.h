/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 23:37:03 by orekabe           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/30 03:20:24 by bmaaqoul         ###   ########.fr       */
=======
/*   Updated: 2022/09/24 01:16:01 by orekabe          ###   ########.fr       */
>>>>>>> 2469868c048956f9f6f18e66937d07df6ba93cf2
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <paths.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "libft/libft.h"
# include "lexer/lexer.h"
<<<<<<< HEAD
# include "syntax_analyser/syntax_analyser.h"
#include "execution/execution.h"

long long	g_status;

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
=======
# include "parser/parser.h"
>>>>>>> 2469868c048956f9f6f18e66937d07df6ba93cf2

#endif
