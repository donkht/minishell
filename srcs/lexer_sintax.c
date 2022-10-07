/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_sintax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:15:41 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/26 15:06:57 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_open_quotes(char *str)
{
	int	i;
	int	is_open_qu;

	i = 0;
	is_open_qu = 0;
	while (str[i])
	{
		if (i > 0 && str[i - 1] == '\\')
			;
		else if (is_open_qu == 0 && str[i] == '\'')
			is_open_qu = 1;
		else if (is_open_qu == 0 && str[i] == '\"')
			is_open_qu = 2;
		else if (is_open_qu == 1 && str[i] == '\'')
			is_open_qu = 0;
		else if (is_open_qu == 2 && str[i] == '\"')
			is_open_qu = 0;
		i++;
	}
	return (is_open_qu);
}

int	check_semicolon_bslash(char **line)
{
	int		i;
	char	*control_str;

	control_str = *line;
	i = 0;
	while (control_str[i])
	{
		if (control_str[i] == ';')
		{
			sintax_error_output(line, T_UNEXP_SCOLON);
			return (1);
		}
		if (control_str[i] == '\\')
		{
			sintax_error_output(line, T_UNEXP_BSLASH);
			return (2);
		}
		i++;
	}
	return (0);
}

int	check_brackets(char *control_str)
{
	int	i;

	i = 0;
	while (control_str[i])
	{
		if (control_str[i] == '(' || control_str[i] == ')'\
		|| control_str[i] == '{' || control_str[i] == '}')
			return (1);
		i++;
	}
	return (0);
}

int	check_uncorrect_pipes(char *control_str)
{
	int	i;
	int	len;

	i = 0;
	while (control_str[i] == ' ')
		i++;
	if (control_str[i] == '|')
		return (1);
	len = ft_strlen(control_str) - 1;
	while (control_str[len] == ' ')
		len--;
	if (control_str[len] == '|')
		return (1);
	return (0);
}
