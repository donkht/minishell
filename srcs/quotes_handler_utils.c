/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_handler_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:37:56 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 15:10:41 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_quotes(char **value, char quote)
{
	char	*temp;

	temp = ft_strtrim(*value, &quote);
	if (!temp)
	{
		ft_putstr_fd("Memory error: ", 2);
		ft_putendl_fd(strerror(12), 2);
		exit(12);
	}
	free(*value);
	*value = temp;
}

void	remove_all_quotes(t_parts *parts, char	**token_arg, int *end_quote)
{
	char	*token;

	token = *token_arg;
	remove_quotes(&parts->after, token[*end_quote]);
	remove_quotes(&parts->value, token[*end_quote]);
	remove_quotes(&parts->before, token[*end_quote]);
}

void	identi_first_q(char *first_quote, char *token)
{
	int		i;

	i = 1;
	*first_quote = *token;
	while ((*first_quote != '\'') && (*first_quote != '\"'))
	{
		*first_quote = *(token + i);
		i++;
	}
}

void	identi_last_q(char *token, bool has_variable,
			char first_quote, int *end_quote)
{
	char	*quote;

	quote = NULL;
	quote = ft_strchr(token, '\"');
	if (!quote && !has_variable)
		quote = ft_strchr(token, '\'');
	else if (quote && first_quote != '\'')
	{
		*quote = '\0';
		*end_quote = ft_strlen(token);
		*quote = '\"';
	}
	else if (!quote || first_quote == '\'')
		*end_quote = ft_strlen(token);
	else
	{
		*quote = '\0';
		*end_quote = ft_strlen(token);
		*quote = '\'';
	}
}
