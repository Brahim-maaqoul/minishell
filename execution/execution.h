/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 02:31:01 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/10/01 23:52:55 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../libft/libft.h"
# include "../syntax_analyser/syntax_analyser.h"
# include "../lexer/lexer.h"
# include "../minishell.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_env
{
	char			*name;
	char			*value;
}		t_env;

typedef struct s_exec
{
	char			*name;
	char			*value;
	struct s_exec	*next;
}		t_exec;

t_exec		*ft_env(t_exec *exec, char **env);
void		ft_export(t_exec **exec, char *cmd);
t_exec		*ft_execnew(char *name, char *value);
void		ft_execadd_back(t_exec **lst, t_exec *new);
void		print_env(t_exec *exec);
void		print_export(t_exec *exec);
void		ft_swap(t_exec *p1, t_exec *p2);
void		builtins(t_exec **exec, char *cmd);
void		sort_name(t_exec *tmp, t_exec *tmp2);
int			check_name(char *str);
int			get_equal(char *str);
int			get_plus(char *str);
int			check_equal(char *str);
int			error_name(t_env *env);
int			update_val(t_exec *tmp, char *str, char *name, char *value);
char		*get_env(t_exec *exec, char *name);
t_env		*take_splited(char *str, t_exec *tmp);
void		ft_unset(t_exec **exec, char *cmd);
void		ft_pwd(void);
void		ft_cd(t_exec *exec, char *cmd);
void		update_pwd(t_exec *exec, char *name, char *value);
void		del_list(t_exec *node);
void		ft_echo(char *args);
void		ft_exit(char *args);
long long	check_num(char *str);
int			is_numeric(char *str);
t_exec		*fill_env(t_exec **exec, t_env *env, char *str);
void		add_shlvl(t_exec *exec);
void		check_env(t_env *env, t_exec *tmp, char *str);
void		print_num_err(char *str);
void		check_arguments(char **args);
void		check_overflow(char *str, char *tab);
void		check_overflow_max(char *str);
void		check_overflow_min(char *str);

#endif