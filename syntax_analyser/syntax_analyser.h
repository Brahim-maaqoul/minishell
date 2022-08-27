/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyser.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 00:11:42 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/08/27 03:43:11 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_ANALYSER_H
# define SYNTAX_ANALYSER_H

# include "../libft/libft.h"

int    syntax_analyser(char *str);
int check_borders(char *str);
int check_flag(char c);

#endif