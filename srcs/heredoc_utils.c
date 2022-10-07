/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:12:34 by gjacqual          #+#    #+#             */
/*   Updated: 2022/04/28 19:19:32 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	here_doc_intsig(int signal)
{
	if (signal == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		exit(130);
	}
}

int	make_temp_file(t_info *info)
{
	int	fd;

	fd = open("heredoc_tmp", O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		error_out_status("redirect", strerror(errno), 1, info);
	return (fd);
}

void	make_temp_file_inp(void)
{
	int		tmp_fd;

	tmp_fd = open("heredoc_tmp", O_RDONLY);
	unlink("heredoc_tmp");
	dup2(tmp_fd, STD_IN);
	close(tmp_fd);
}

void	clear_temp_file_inp(void)
{
	int		tmp_fd;

	tmp_fd = open("heredoc_tmp", O_WRONLY | O_TRUNC, 0600);
	close(tmp_fd);
}
