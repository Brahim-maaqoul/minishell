/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:50:50 by orekabe           #+#    #+#             */
/*   Updated: 2022/10/20 17:57:52 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../libft/libft.h"
# include "../lexer/lexer.h"

typedef struct s_tree
{
	int				exp_h;
	struct s_list	*list;
	struct s_tree	*left;
	struct s_tree	*right;
	char			**args;
}				t_tree;

t_tree	*parser(t_list *list);
t_tree	*ft_treenew(t_list *list);
t_tree	*ft_addleaf(t_tree *root, t_tree *leaf);
t_tree	*ast_lvl1(t_list *list);
t_tree	*ast_lvl2(t_list *list);
t_tree	*ast_lvl3(t_list *list);
t_tree	*ast_lvl4(t_list *list);
t_tree	*get_node(t_tree *tree, t_list *list, t_list *l_tmp);
char	*rm_par(char *str, t_list *n_list, t_lx_var *lx_var);
void	get_heredoc(t_tree *node);
void	fill_heredoc(t_tree *node, t_tree *root);

#endif