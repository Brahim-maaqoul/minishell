/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 21:33:57 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/07/17 02:24:07 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int main(int ac, char **av)
{
    char ez[100];
    char command[4];
    char *line, **split;
    int i = 0;
    while (1)
    {
        line = readline("minishell> ");
        if (!strcmp(line, "pwd"))
        {
            printf("%s\n", getcwd(ez, sizeof(ez)));
        }
        else if (!strncmp(line, "cd", 2))
        {
            split = ft_split(line, ' ');
            chdir(split[1]);
        }
        // i++;
    }
    // read(0, command, 4);
}