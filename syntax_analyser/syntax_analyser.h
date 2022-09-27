/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyser.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 00:11:42 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/09/27 00:51:21 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_ANALYSER_H
# define SYNTAX_ANALYSER_H

# include "../libft/libft.h"

int		syntax_analyser(char *str);
int		check_borders(char *str);
int		check_reder(char c);
int		check_pipe(char c);
int		check_quotes(char *str, int c, int lp, int rp);
int		fnct1(int d, int s);
int		check_red(char *str);
int		check_parenth(char c);
int		check_middle(char *str);
int		handle_red(char *str, int i);
int		handle_pipe(char *str, int i);
void	put_err(char *str);
void	ft_putchar_fd(char c, int fd);
void	print_errs(char *str, int len, int i);
int		check_par(char *str, int lp, int rp);
int		fcnt2(int lp, int rp);
int		check_valid_p(char *cmd);
void	p_err(char *cmd, char *str);
int		check_p_in_q(char *str, int i);

#endif