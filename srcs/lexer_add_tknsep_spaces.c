/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_add_tknsep_spaces.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:45:16 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 13:26:02 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*merge_parts(char *before, char *op_tkn, char *after)
{
	char	*union_line;
	char	*part1;
	char	*part2;
	char	*part3;

	part1 = ft_strjoin(before, " ");
	free(before);
	part2 = ft_strjoin(part1, op_tkn);
	free(part1);
	free(op_tkn);
	part3 = ft_strjoin(part2, " ");
	free(part2);
	union_line = ft_strjoin(part3, after);
	free(part3);
	free(after);
	return (union_line);
}

static char	*make_space_line(char *line, char *op_beg, int op_len, int off_set)
{
	char	*before;
	char	*operator;
	char	*after;
	char	*new_line;

	before = ft_substr(line, 0, off_set);
	operator = ft_substr(op_beg, 0, op_len);
	after = ft_strdup(op_beg + op_len);
	if (!before || !operator || !after)
	{
		ft_putstr_fd("Memory error: ", 2);
		ft_putendl_fd(strerror(12), 2);
		exit(12);
	}
	new_line = merge_parts(before, operator, after);
	return (new_line);
}

char	*add_tknsep_spaces(char **line, char *op_beg, char *l_begin)
{
	int		op_len;
	int		off_set;
	char	*new_line;

	op_len = 0;
	if (op_beg != l_begin)
		if (*(op_beg - 1) == '>' || *(op_beg - 1) == '<')
			return (op_beg++);
	if (*op_beg == *(op_beg + 1))
		op_len = 2;
	else
		op_len = 1;
	off_set = op_beg - *line;
	new_line = make_space_line(*line, op_beg, op_len, off_set);
	free(*line);
	*line = new_line;
	return (new_line + off_set + op_len + 1);
}
