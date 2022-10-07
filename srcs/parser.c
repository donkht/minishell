/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:05:41 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 15:08:34 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_new(t_token *pipe_tkn, int *old_pipe_in)
{
	int	pipe_new[2];

	dup2(*old_pipe_in, STDIN_FILENO);
	if (*old_pipe_in != 0)
		close(*old_pipe_in);
	if (!pipe_tkn)
		return ;
	pipe(pipe_new);
	dup2(pipe_new[STD_OUT], STDOUT_FILENO);
	close(pipe_new[STD_OUT]);
	*old_pipe_in = dup(pipe_new[STD_IN]);
	close(pipe_new[STD_IN]);
}

void	command_parser(t_info *info, t_token *token_lst, \
t_token *pipe, int *old_pipe_input)
{
	int		save_fd[2];
	char	**cmd;

	save_fd[STD_IN] = dup(STDIN_FILENO);
	save_fd[STD_OUT] = dup(STDOUT_FILENO);
	pipe_new(pipe, old_pipe_input);
	check_mk_re(token_lst, pipe, save_fd, info);
	cmd = create_commands(token_lst, pipe);
	executor_select(info, cmd);
	xx_arr_clean(cmd);
	dup2(save_fd[STD_IN], STDIN_FILENO);
	close(save_fd[STD_IN]);
	dup2(save_fd[STD_OUT], STDOUT_FILENO);
	close(save_fd[STD_OUT]);
}

int	check_redir_sintax(t_token *tokens)
{
	t_token	*tmp;

	while (tokens)
	{
		tmp = tokens->next;
		if (tokens->type == TOKEN_REDIR)
			if (tmp == NULL || tmp->type != TOKEN_FILE)
				return (0);
		tokens = tmp;
	}
	return (1);
}

void	check_pipe_rcrs(t_info *info, t_token *tokens_first, int *old_pipe_inp)
{
	t_token	*tmp;

	tmp = tokens_first;
	while (tmp != NULL)
	{
		if (tmp->type != TOKEN_PIPE)
			tmp = tmp->next;
		else
		{
			if (check_redir_sintax(tokens_first))
				command_parser(info, tokens_first, tmp, old_pipe_inp);
			else
				sintax_error_out_status(T_BAD_REDIR_UNCOR_FILE, 2, info);
			tokens_first = tmp->next;
			check_pipe_rcrs(info, tokens_first, old_pipe_inp);
			break ;
		}
	}
	if (tmp == NULL)
	{
		if (check_redir_sintax(tokens_first))
			command_parser(info, tokens_first, tmp, old_pipe_inp);
		else
			sintax_error_out_status(T_BAD_REDIR_UNCOR_FILE, 2, info);
	}
}
