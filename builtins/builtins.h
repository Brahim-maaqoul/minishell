/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 02:31:01 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/20 20:20:24 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../libft/libft.h"
# include "../parser/parser.h"
# include "../syntax_analyser/syntax_analyser.h"

typedef struct s_env
{
	char			*name;
	char			*value;
}		t_env;

typedef struct s_built
{
	char			*name;
	char			*value;
	struct s_built	*next;
}		t_built;

t_built		*ft_env(t_built *built, char **env);
void		ft_export(t_built **built, char **cmd);
t_built		*ft_builtnew(char *name, char *value);
void		ft_builtadd_back(t_built **lst, t_built *new);
void		print_env(t_built *built);
void		print_export(t_built *built);
void		ft_swap(t_built *p1, t_built *p2);
void		builtins(t_built **built, t_tree *node);
void		sort_name(t_built *tmp, t_built *tmp2);
int			check_name(char *str);
char		*get_env(t_built *built, char *name);
int			get_equal(char *str);
int			get_plus(char *str);
int			check_equal(char *str);
int			error_name(t_env *env);
int			update_val(t_built *tmp, char *str, char *name, char *value);
char		*get_env(t_built *built, char *name);
t_env		*take_splited(char *str, t_built *tmp);
void		ft_unset(t_built **built, char **cmd);
void		ft_pwd(void);
void		ft_cd(t_built *built, char **cmd);
void		update_pwd(t_built *built, char *name, char *value);
void		del_list(t_built *node);
void		ft_echo(char **args);
void		ft_exit(char **args);
long long	check_num(char *str);
int			is_numeric(char *str);
t_built		*fill_env(t_built **built, t_env *env, char *str);
void		add_shlvl(char *env, char *name, char *value);
void		check_env(t_env *env, t_built *tmp, char *str);
void		print_num_err(char *str);
int			check_arguments(char **args);
void		check_overflow(char *str, char *tab);
void		check_overflow_max(char *str);
void		check_overflow_min(char *str);
void		handler(int sig);
int			ft_builtsize(t_built *lst);
int			exit_status(int status);
void		check_dir(char *path);
void		update_equal(t_env *env, char *str, int len);
void		handler_pars(int sig);
int			check_alpha(char *str);
void		check_shlvl(char *value);

#endif