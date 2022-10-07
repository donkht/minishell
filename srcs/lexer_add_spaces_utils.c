/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_spaces_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:20:03 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 12:29:09 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	locate_spaces_around(char *line, char *begin)
{
	if (line == begin)
	{
		if (*(line + 1) == ' ')
			return (1);
		else
			return (0);
	}
	if ((*(line - 1) == ' ') && (*(line + 1) == ' '))
		return (1);
	return (0);
}

static int	check_spaces_near_redir(char *line, char *bef_pos, char *begin)
{
	if ((*(line + 1) == *line) && \
	((*(bef_pos)) != ' ' || (*(line + 2)) != ' '))
		return (1);
	else
		if (!(locate_spaces_around(line, begin)))
			return (1);
	return (0);
}

int	check_spaces_near_oper(char *line, char *begin)
{
	char	*bef_pos;

	bef_pos = line - 1;
	if (line == begin)
		bef_pos = line;
	if ((*line == '|') && !(locate_spaces_around(line, begin)))
		return (1);
	if (*line == '>' || *line == '<')
		if (check_spaces_near_redir(line, bef_pos, begin))
			return (1);
	return (0);
}
