/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:04:38 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 15:05:08 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	mini_cycle(t_info *info)
{
	int	old_pipe_inp;

	while (info->exit_flag != 1)
	{
		signals_for_minishell();
		info->line = ft_readline(info);
		if (info->line && info->line[0])
		{
			if (lexer(info))
			{
				if (info->tokens)
				{
					old_pipe_inp = 0;
					check_pipe_rcrs(info, info->tokens, &old_pipe_inp);
					if (old_pipe_inp != 0)
						close(old_pipe_inp);
				}
				tkn_lstclear(&info->tokens, free);
				if (info->line)
					free(info->line);
			}
		}
	}
	free_all_data(info);
	return (EXIT_FAILURE);
}
