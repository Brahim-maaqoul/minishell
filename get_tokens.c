/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 02:32:42 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/08/04 23:30:32 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    get_tokens(t_mystruct *list)
{
    int i;
	
	list->splited = ft_split(list->line, PIPE);
	list->word = malloc(sizeof(char *) * ft_strlen(list->splited[0]));
	i = 0;
	while (list->line[i] && list->line[i] != PIPE)
	{
		list->word[i] = list->line[i];
		// if (list->line[i + 1] == PIPE)
		// {
		// 	// list->flags = word;
		// 	*list = *(list)->right;
		// 	break;
		// }
		i++;
	}
	if (list->line[i] == PIPE)
		list->flags = PIPE;
    	// printf("%s", list->splited[i++]);
}

int main()
{
	t_mystruct list;
 	 list.line = readline("minishell> ");
	 get_tokens(&list);
	 printf("%s\n", list.word);
	 printf("%c\n", list.flags);
}