/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:43:43 by orekabe           #+#    #+#             */
/*   Updated: 2022/10/18 19:46:01 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

void	handler_pars(int sig)
{
	(void) sig;
	rl_done = 1;
	g_glob.gl = 0;
	g_glob.ex_st = 1;
}
