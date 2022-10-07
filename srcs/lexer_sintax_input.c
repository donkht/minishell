/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_sintax_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 21:36:03 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/28 22:18:25 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	syntax_inp(char **line)
{
	if (check_open_quotes(*line))
	{
		sintax_error_output(line, T_UNEXP_QUOTES);
		return (1);
	}
	if (check_semicolon_bslash(line))
		return (1);
	if (check_brackets(*line))
	{
		sintax_error_output(line, T_UNEXP_BRACKETS);
		return (1);
	}
	if (check_uncorrect_pipes(*line))
	{
		sintax_error_output(line, T_UNEXP_PIPES);
		return (1);
	}
	return (0);
}
