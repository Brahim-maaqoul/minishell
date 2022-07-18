/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 21:33:57 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/07/18 15:25:47 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int main(int ac, char **av)
{
    char ez[100];
    char *line, **split, **path, *tmp;
    int i, pid;
    struct stat s;
    while (1)
    {
        line = readline("minishell> ");
        split = ft_split(line, ' ');
        path = ft_split(getenv("PATH"), ':');
        add_history(line);
        if (!ft_strncmp(line, "pwd", 3))
            printf("%s\n", getcwd(ez, sizeof(ez)));
        else if (!ft_strncmp(line, "cd", 2))
            chdir(split[1]);
        else
        {
            i = 0;
            while (path[i])
            {
                // printf("%s\n", path[i]);
                pid = fork();
                if (pid == 0)
                {
                    tmp = ft_strjoin(path[i], "/");
                    if (!stat(ft_strjoin(tmp, split[0]), &s))
                    {
                        execve(ft_strjoin(tmp, split[0]), split, NULL);
                        break;
                    }
                }
                else
                    waitpid(-1, NULL, 0);
                i++;
            }
        }
        // printf("%s\n", getenv("PATH"));
        // i++;
    }
    // read(0, command, 4);
}