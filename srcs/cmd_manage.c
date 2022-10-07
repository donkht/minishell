/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:56:39 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 13:34:28 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cmds_len(t_token *current, t_token *pipe)
{
	int	i;

	i = 0;
	while (current != pipe)
	{
		if ((current->type == TOKEN_WORD) || (current->type == TOKEN_BLT_IN))
			i++;
		current = current->next;
	}
	return (i);
}

static char	**create_cmd_arr(t_token *current, t_token *end, char **cmd)
{
	int	i;

	i = 0;
	while (current != end)
	{
		if ((current->type == TOKEN_WORD) || (current->type == TOKEN_BLT_IN))
		{
			cmd[i] = ft_strdup(current->content);
			if (!cmd[i])
			{
				ft_putstr_fd("Memory error: ", 2);
				ft_putendl_fd(strerror(12), 2);
				exit(12);
			}	
			i++;
		}
		current = current->next;
	}
	return (cmd);
}

char	**create_commands(t_token *first, t_token *pipe)
{
	char	**cmd;
	int		cmd_length;

	cmd_length = cmds_len(first, pipe);
	cmd = (char **)malloc((cmd_length + 1) * sizeof(char *));
	cmd[cmd_length] = NULL;
	cmd = create_cmd_arr(first, pipe, cmd);
	return (cmd);
}
