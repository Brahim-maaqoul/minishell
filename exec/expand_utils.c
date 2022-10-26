/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 02:06:53 by orekabe           #+#    #+#             */
/*   Updated: 2022/10/19 05:18:31 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	check_alphanum(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= '0' && c <= '9')
		return (2);
	if (c == '?')
		return (1);
	return (0);
}

char	*expand_num(char *str, char *bash)
{
	char	*ret;
	char	*exp;
	int		i;
	int		j;

	i = 0;
	if (!bash)
		i++;
	j = i;
	while (str[j] && str[j] != ' ')
		j++;
	exp = ft_strndup(str + i, j);
	if (!bash)
		return (exp);
	ret = ft_strjoin(bash, exp);
	free(exp);
	free(bash);
	return (ret);
}

char	*expand_z_alpha(char *str, char *bash)
{
	char	*ret;
	char	*exp;
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	exp = ft_strndup(str, i);
	if (!bash)
		return (exp);
	ret = ft_strjoin(bash, exp);
	free(exp);
	free(bash);
	return (ret);
}

char	*expand_var(char *str, t_built **built)
{
	char	*ret;
	char	*exp;
	char	*a_exp;
	int		i;

	i = 0;
	a_exp = NULL;
	while (str[i] && str[i] != ' ' && str[i] != '\'' && str[i] != '$')
		i++;
	exp = ft_strndup(str, i);
	ret = get_env(*built, exp);
	if (str[i] == '\'')
	{
		a_exp = ft_strdup("'");
		free(exp);
		exp = ft_strjoin(ret, a_exp);
		free(ret);
		free(a_exp);
		return (exp);
	}
	if (!ret)
		ret = ft_calloc(1, sizeof(char));
	free(exp);
	return (ret);
}
