/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 02:31:01 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/03 03:56:55 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../libft/libft.h"
# include "../syntax_analyser/syntax_analyser.h"
# include "../lexer/lexer.h"
# include "../minishell.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>

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
void		ft_export(t_built **built, char *cmd);
t_built		*ft_builtnew(char *name, char *value);
void		ft_builtadd_back(t_built **lst, t_built *new);
void		print_env(t_built *built);
void		print_export(t_built *built);
void		ft_swap(t_built *p1, t_built *p2);
void		builtins(t_built **built, char *cmd);
void		sort_name(t_built *tmp, t_built *tmp2);
int			check_name(char *str);
int			get_equal(char *str);
int			get_plus(char *str);
int			check_equal(char *str);
int			error_name(t_env *env);
int			update_val(t_built *tmp, char *str, char *name, char *value);
char		*get_env(t_built *built, char *name);
t_env		*take_splited(char *str, t_built *tmp);
void		ft_unset(t_built **built, char *cmd);
void		ft_pwd(void);
void		ft_cd(t_built *built, char *cmd);
void		update_pwd(t_built *built, char *name, char *value);
void		del_list(t_built *node);
void		ft_echo(char *args);
void		ft_exit(char *args);
long long	check_num(char *str);
int			is_numeric(char *str);
t_built		*fill_env(t_built **built, t_env *env, char *str);
void		add_shlvl(t_built *built);
void		check_env(t_env *env, t_built *tmp, char *str);
void		print_num_err(char *str);
void		check_arguments(char **args);
void		check_overflow(char *str, char *tab);
void		check_overflow_max(char *str);
void		check_overflow_min(char *str);
void		handler(int sig);

#endif