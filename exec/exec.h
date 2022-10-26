/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 02:13:49 by orekabe           #+#    #+#             */
/*   Updated: 2022/10/20 04:33:56 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "../libft/libft.h"
# include "../lexer/lexer.h"
# include "../parser/parser.h"
# include "../builtins/builtins.h"

typedef struct s_exp
{
	char	*str;
	char	*exp;
	char	*ret;
	t_built	**built;
}				t_exp;

void	check_exec(t_tree *node, t_built **builts);
int		check_alphanum(char c);
char	*expand_num(char *str, char *bash);
char	*expand_z_alpha(char *str, char *bash);
char	*expand_var(char *str, t_built **built);
char	*get_expand(char *str, t_built **built);
void	get_args(t_tree *node, t_built **built);
char	*expander(char *arg, t_built **built);
void	exec_cmd(t_tree *node, t_built **built);
void	pippe(t_tree *node, t_built **built);
void	exec_tree(t_tree *root, t_built **built);
void	redirec(t_tree *node, t_built **built);
char	**convert_toarr(t_built *built);
void	and_or(t_tree *node, t_built **built);
char	check_sq(char *arg);
char	*flag_sp(char *exp);
void	rm_q(char *n_cmd);
int		ft_tabsize(char **tab);
char	**ft_tabjoin(char **tab1, char **tab2);
void	cmd_nf(char *cmd);
void	free_tab(char **args);
char	**wild_card(char **args);
char	*exp_star(char *str, char **curr);
char	**get_curr(void);
int		get_curr_size(void);
int		cmp_first(char *str, char *cmp);
int		cmp_last(char *str, char *cmp);
int		check_valid(char *str, char *cmp);
int		check_star(char *str);
char	*wc_substr(char *s, int len);
char	*joinchr(char *str);

#endif