/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 21:33:57 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/07/18 00:22:41 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int main(int ac, char **av)
{
    char ez[100];
    char *line, **split, **path, *tmp;
    int i = 0;
    while (1)
    {
        line = readline("minishell> ");
        split = ft_split(line, ' ');
        path = ft_split(getenv("PATH"), ':');
        while (path[i])
        {
            // printf("%s\n", path[i]);
            tmp = ft_strjoin(path[i], "/");
            execve(ft_strjoin(tmp, split[0]), split, NULL);
            i++;
        }
        // printf("%s\n", getenv("PATH"));
        // if (!strcmp(line, "pwd"))
        // {
        //     printf("%s\n", getcwd(ez, sizeof(ez)));
        // }
        // else if (!strncmp(line, "cd", 2))
        // {
        //     chdir(split[1]);
        // }
        // i++;
    }
    // read(0, command, 4);
}