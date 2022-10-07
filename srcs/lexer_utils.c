/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:36:45 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/28 14:42:48 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	spaces_convert(char **line)
{
	int	i;

	i = 0;
	while ((*line)[i])
	{
		if (ft_isspace((*line)[i]))
			(*line)[i] = ' ';
		i++;
	}
}

int	check(char *line, int i, int *index, char c)
{
	while (line[i++])
	{
		if (line[i] == c)
		{
			*index = i;
			return (1);
		}
	}
	return (0);
}

int	tkn_blt_in_check(char *content, size_t tkn_length)
{
	if (!content)
		return (0);
	if (!(ft_strncmp(content, "echo", tkn_length)) \
	|| !(ft_strncmp(content, "cd", tkn_length)) \
	|| !(ft_strncmp(content, "pwd", tkn_length)) \
	|| !(ft_strncmp(content, "export", tkn_length)) \
	|| !(ft_strncmp(content, "unset", tkn_length)) \
	|| !(ft_strncmp(content, "env", tkn_length)) \
	|| !(ft_strncmp(content, "exit", tkn_length))
	)
		return (1);
	return (0);
}

int	only_dollar_in_wallet(char *content)
{
	while (*content)
	{
		if (*content != '$')
			return (0);
		content++;
	}
	return (1);
}
