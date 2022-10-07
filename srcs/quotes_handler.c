/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 00:17:32 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 14:25:34 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_match(char *line, int i, int *match_i, char c)
{
	while (line[i++] != '\0')
	{
		if (line[i] == c)
		{
			*match_i = i;
			return (1);
		}
	}
	return (0);
}

static void	expand_vars_in_parts(t_parts *parts, bool *has_var, t_info *info)
{
	dollar_vars_uncover(&parts->before, info);
	dollar_vars_uncover(&parts->value, info);
	dollar_vars_uncover(&parts->after, info);
	*has_var = 1;
}

static void	split_parts_strings(t_parts *parts, char *token, int i, int end_quo)
{
	parts->before = ft_substr(token, 0, i);
	parts->value = ft_substr(token, i, (end_quo + 1 - i));
	parts->after = ft_substr(token, end_quo + 1, \
	ft_strlen(&token[end_quo]));
}

void	quotes_handler_act(char **token_ptr, \
int i, int *end_quote, t_info *info)
{
	t_parts	parts;
	char	*token;
	char	first_quote;
	bool	has_variable;
	char	*tmp;

	(void)info;
	has_variable = 0;
	token = *token_ptr;
	identi_first_q(&first_quote, token);
	split_parts_strings(&parts, token, i, *end_quote);
	if ((token[*end_quote] == '\"') && (ft_strchr(token, '$')))
		expand_vars_in_parts(&parts, &has_variable, info);
	remove_all_quotes(&parts, &token, end_quote);
	free(token);
	tmp = ft_strjoin(parts.before, parts.value);
	token = ft_strjoin(tmp, parts.after);
	free(tmp);
	*token_ptr = token;
	identi_last_q(token, has_variable, first_quote, end_quote);
	free_struct_t_parts(&parts);
}

void	quotes_handler(char **content, t_info *info)
{
	int		i;
	int		end_quote;
	char	*token;

	i = 0;
	token = *content;
	while (token[i])
	{
		if ((token[i] == '\'' || token[i] == '\"') && \
		check_match(token, i, &end_quote, token[i]))
		{
			quotes_handler_act(&token, i, &end_quote, info);
			i = end_quote - 1;
			if (i < 0)
				i = 0;
		}
		if (token[i])
			i++;
	}
	*content = token;
}
