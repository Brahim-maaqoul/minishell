/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyser.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 00:11:42 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/09/08 14:22:05 by bmaaqoul         ###   ########.fr       */
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
int		fnct1(int d, int s, int lp, int rp);
int		check_red(char *str);
int		check_parenth(char c);
int		check_middle(char *str);
int		handle_red(char *str, int i);
int		handle_pipe(char *str, int i);
void	put_err(char *str);
void	ft_putchar_fd(char c, int fd);
void	print_errs(char *str, int len, int i);

#endif