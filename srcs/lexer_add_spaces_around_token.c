/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_spaces_around_token.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:51:01 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 12:35:40 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_oper(char *cur_c)
{
	char	quote;
	char	oper;

	quote = *cur_c;
	cur_c++;
	while (*cur_c == ' ')
		cur_c++;
	if (!(ft_strncmp(cur_c, "|", 1)) \
	|| !(ft_strncmp(cur_c, ">>", 2)) \
	|| !(ft_strncmp(cur_c, "<<", 2)) \
	|| !(ft_strncmp(cur_c, ">", 1)) \
	|| !(ft_strncmp(cur_c, "<", 1)))
		return (0);
	oper = *cur_c;
	cur_c++;
	if (*cur_c == oper)
		cur_c++;
	while (*cur_c == ' ')
		cur_c++;
	if (*cur_c != quote)
		return (0);
	return (1);
}

static bool	check_match(char **tmp_pos, char c)
{
	char	*cur_c;

	cur_c = *tmp_pos;
	cur_c++;
	while (*cur_c != '\0')
	{
		if (*cur_c == c)
		{
			*tmp_pos = cur_c;
			return (true);
		}
		cur_c++;
	}
	return (false);
}

static int	check_field_in_quotes(char **tmp_pos)
{
	char	*cur_pos;

	cur_pos = *tmp_pos;
	if (check_oper(cur_pos))
		return (0);
	if ((*cur_pos == '\'' || *cur_pos == '\"') \
	&& check_match(tmp_pos, *cur_pos))
		return (1);
	return (0);
}

void	add_spaces_around_token(char **line)
{
	char	*begin;
	char	*tmp_pos;

	tmp_pos = *line;
	begin = *line;
	while (tmp_pos && *tmp_pos)
	{
		if (check_field_in_quotes(&tmp_pos))
		{
			tmp_pos++;
			continue ;
		}
		if (check_spaces_near_oper(tmp_pos, begin))
			tmp_pos = add_tknsep_spaces(line, tmp_pos, begin);
		tmp_pos++;
	}
}
