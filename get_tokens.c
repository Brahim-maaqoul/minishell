/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 02:32:42 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/08/14 04:25:01 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    get_tokens(t_list *list)
{
    int i;
	
	// list->splited = ft_split(list->line, PIPE);
	// list->word = malloc(sizeof(char *) * ft_strlen(list->splited[0]));
	
	// if (!list)
	// 	return ;
	// check_word(list);
	// list = list->next;
	i = 0;
	// while (list)
	// {
	// 	while (list->line[i])
	// 	{

	// 		i++;
	// 	}
	// 	// list->word[i] = ft_strdup(list->splited[i]);
	// 	// if (list->line[i + 1] == PIPE)
	// 	// {
	// 	// 	// list->flags = word;
	// 	// 	*list = *(list)->right;
	// 	// 	break;
	// 	// }
	// 	list = list->next;
	// }
	// i = 0;
	// while (list->line[i])
	// {
	// 	if (list->line[i] == PIPE)
	// 	{
	// 		list->flags = PIPE;
	// 		break ;
	// 	}
	// 	i++;
	// }
    	// printf("%s", list->splited[i++]);
}

int main()
{
	t_list list;

	// list = NULL;
	// list = (t_list *) malloc(sizeof(t_list));
 	list.line = readline("minishell> ");
	 int i = 0;
	 check_word(&list);
	//  while (list)
	// {
		printf("%s\n", list.content);
		// printf("%u\n", list->flags);
		// list = list->next;
		// i++;
	// }
}