/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:51:10 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/29 15:01:29 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	readline_heredoc(t_info *info, int tmp_fd, char *eof)
{
	char	*input;

	signal(SIGINT, here_doc_intsig);
	while (true)
	{
		input = readline("heredoc> ");
		if (!input)
		{
			error_out_status("warning",
				"here-document delimited by end-of-file", 0, info);
			close(tmp_fd);
			exit(0);
		}
		if (ft_strcmp(input, eof))
			ft_putendl_fd(input, tmp_fd);
		else
		{
			close(tmp_fd);
			free(input);
			break ;
		}
		free(input);
	}
	exit(0);
}

void	heredoc_inp(t_info *info, char *eof, int *save_fd)
{
	int		tmp_fd;
	int		save_fd_out;
	int		pid;
	int		status;

	tmp_fd = make_temp_file(info);
	if (tmp_fd == -1)
		return ;
	save_fd_out = dup(STD_OUT);
	dup2(save_fd[STD_OUT], STDOUT_FILENO);
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
		readline_heredoc(info, tmp_fd, eof);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
	{
		clear_temp_file_inp();
		info->exit_status = 130;
	}
	make_temp_file_inp();
	dup2(save_fd_out, STDOUT_FILENO);
	close(save_fd_out);
}
