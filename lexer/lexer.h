/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 22:52:18 by orekabe           #+#    #+#             */
/*   Updated: 2022/08/14 02:59:49 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H

#include "../minishell.h"
#include "../libft/libft.h"

char	*lexer(char *cmd, char *n_cmd);
int		check_ws(char c);
int		check_sc(char c);
void	rm_extra_sp(char *n_cmd);
void	add_need_sp(char *cmd, char *n_cmd);


#endif