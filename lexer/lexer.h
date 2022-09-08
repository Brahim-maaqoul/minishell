/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 22:52:18 by orekabe           #+#    #+#             */
/*   Updated: 2022/09/04 20:51:39 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../libft/libft.h"
# include "../syntax_analyser/syntax_analyser.h"

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
    SP = 12,
    RAND = 13
}       t_tokens;

t_list	*lexer(char *cmd, char *n_cmd, t_list *lst);
int		check_ws(char c);
int		check_sc(char c);
int		check_q(char c, int q);
int	    get_token(char *str);
int	    check_q(char c, int flag);
int	    get_rand(char *str);
void	rm_extra_sp(char *n_cmd);
void	add_need_sp(char *cmd, char *n_cmd);
char	*get_clean_cmd(char *n_cmd);

#endif