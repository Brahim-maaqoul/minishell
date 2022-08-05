/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 21:33:57 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/08/05 16:21:29 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int main(int ac, char **av, char **env)
{
    char ez[100];
    char *line, **split, **path, *tmp;
    int i = 0, pid;
    struct stat s;
    t_mystruct list;
	// list.splited = ft_split(env[0], '=');
    while (1)
    {
        // rl_catch_signals = 0;
        line = readline("minishell> ");
        if (!line)
            exit(0);
        split = ft_split(line, ' ');
        path = ft_split(getenv("PATH"), ':');
        add_history(line);
        if (!ft_strncmp(split[0], "pwd", 3))
            printf("%s\n", getcwd(ez, sizeof(ez)));
        else if (!ft_strncmp(split[0], "cd", 2))
            chdir(split[1]);
        else if (!ft_strncmp(split[0], "echo", 4))
        {
            if (split[1] && !ft_strncmp(split[1], "-n", 2))
                i = 2;
            else
                i = 1;
            while (split[i])
            {
                if (!split[i + 1])
                    printf("%s", split[i++]);
                else
                    printf("%s ", split[i++]);
            }
            if (!split[1] || ft_strncmp(split[1], "-n", 2))
                printf("\n");
        }
        else if (!ft_strncmp(split[0], "env", 3))
        {
            i = 0;
			while (env[i])
			{
				list.splited = ft_split(env[i], '=');
				list.name= list.splited[0];
				list.value = list.splited[1];
				printf("%s=",list.name);
				printf("%s\n", list.value);
				i++;
			}
        }
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
        free(line);
    }

    // read(0, command, 4);
}