/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilda_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:42:44 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 17:17:00 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tilda_handler(char **content, t_info *info)
{
	char	*env_value;
	char	*repl_content;

	env_value = find_envair_value(info, "HOME");
	repl_content = ft_strdup(env_value);
	if (!repl_content)
		repl_content = ft_strdup("/");
	if (!repl_content)
		malloc_error_exit(info);
	free(*content);
	*content = repl_content;
}
