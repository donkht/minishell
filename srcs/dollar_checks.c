/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:30:36 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 17:17:54 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dollar_alone(char **content, t_info *info)
{
	char	*repl_content;

	repl_content = ft_strdup("$");
	if (!repl_content)
		malloc_error_exit(info);
	free(*content);
	*content = repl_content;
}

void	dollar_dubbles(char **content, t_info *info)
{
	char	*repl_content;

	repl_content = ft_strdup("$$");
	if (!repl_content)
		malloc_error_exit(info);
	free(*content);
	*content = repl_content;
}
