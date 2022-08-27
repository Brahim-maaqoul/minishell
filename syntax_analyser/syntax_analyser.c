/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 00:48:55 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/08/27 04:16:16 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyser.h"

int check_flag(char c)
{
    if (c == '|' || c == '<' || c == '>'
        || c == '&')
        return (c);
    return (0);
}

int check_borders(char *str)
{
    int len;

    len = ft_strlen(str) - 1;
    if (check_flag(str[0]) == '|' || check_flag(str[0]) == '&')
    {
        if (str[1] == str[0])
            printf("syntax error near unexpected token '%c%c'\n", str[0],str[1]);
        else
            printf("syntax error near unexpected token '%c'\n", str[0]);
        return (1);
    }
    if (check_flag(str[len]) == '<' || check_flag(str[len]) == '>')
    {
        if (str[len - 1] == str[len])
            printf("syntax error near unexpected token `newline'\n");
        else
            printf("syntax error near unexpected token '%c'\n", str[len]);
        return (1);
    }
    return (0);
}

int    syntax_analyser(char *str)
{
    int i;

    i = 0;
    if (check_borders(str))
        return (0);
    while (str[i])
    {
        if (str[i] == check_flag(str[i]) && str[i + 2] == str[i])
        {
            printf("syntax error near unexpected token '%c'\n", str[i]);
            return (0);
        }
        i++;
    }
    return (1);
}