/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 22:52:18 by orekabe           #+#    #+#             */
/*   Updated: 2022/08/18 03:29:31 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../libft/libft.h"

typedef enum e_tokens
{
    AND = 1,
    OR = 2,
    PIPE = 3,
    L_RD = 4,
    R_RD = 5,
    DL_RD = 6,
    DR_RD = 7,
    DQ  = 8,
    SQ  = 9,
    WORD = 10,
    VAR = 11,
    SP = 12
}       t_tokens;

t_list	*lexer(char *cmd, char *n_cmd, t_list *lst);
int		check_ws(char c);
int		check_sc(char c);
int		check_q(char c, int q);
void	rm_extra_sp(char *n_cmd);
void	add_need_sp(char *cmd, char *n_cmd);

#endif